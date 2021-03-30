#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
//callback method
void *fun(void *p)
{
	printf("------------------------------fun:%d\n",p);
	int i=0,no=0;
	for(i=0;i<=p;i++)
	{
		printf("Fun:%d\n",i);
	}
	
}

void *gun(void *p)
{
	printf("-----------------------------gun:%d\n",p);
	int i=0;
	for(i=p;i>0;i--)
	{
		printf("Gun:%d\n",i);
	}
}

int main(int argc,char *argv[])
{
	pthread_t thread1;
	pthread_t thread2;
	int ret=0,myret=0;
	int no1=500,no2=500;
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
	ret= pthread_create(&thread2,NULL,gun,(void*)no2);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("---------------------------------------------------------------%d\n",myret);
	printf("terminating main thread\n");
	return 0;
}
