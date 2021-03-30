#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *fun(void *p)
{
	printf("------------------------------fun:%d\n",p);
	int i=0,no=0;
	for(i=0;i<=p;i++)
	{
		printf("%d",i);
	}
	no=i;
	printf("End of fun\n");
	pthread_exit(no);
}

int main(int argc,char *argv[])
{
	pthread_t thread1;
	
	int ret=0,myret=0;
	int no1=10000;
	printf("Inside main thread\n");
	ret= pthread_create(&thread1,//address of pthread_t pointer
	NULL,						//attributes of thread
	fun,						//address of callback function
	(void*)no1						//parameters of call back funtion
	);
	if(ret!=0)
	{
		printf("Unable to create thread\n");
	}
	
	pthread_join(thread1,&myret);
	
	printf("---------------------------------------------------------------%d\n",myret);
	printf("terminating main thread\n");
	return 0;
}


/*
1. Write a program which is used to create simple thread by using pthread
library.
2. Write a program which creates two thread , first thread print numbers
from 1 to 500 & other thread print the numbers from 500 to 1.
3. Write a program which creates single thread and we have to pass
parameter to that thread from main thread.
4. Write a program which creates single thread and it accept one value from
user and it return some value to the caller thread.
5. Write a program which is used to get thread id inside its thread function.
*/