#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* fun(void* p)
{
	printf("start of fun\n");
	int i=0,j=0;
	for(i=0;i<p;i++)
	{
		for(j=0;j<i;j++)
		{
			if(j<=i) printf("*");
		}
		printf("\n");
	}
	printf("end of fun\n");	
	pthread_exit(p);
}

int main(int argc,char*argv[])
{
	printf("Start of main\n");
	int no=atoi(argv[1]);
	int ret=0,retvalue=0;
	pthread_t thread1;
	ret=pthread_create(&thread1,NULL,fun,(void*) no);
	if(ret!=0)
	{
		printf("Unable to create thread\n");
	}
	pthread_join(&thread1,&ret);
	printf("End of main\n");
	return 0;
}
