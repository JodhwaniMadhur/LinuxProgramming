#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int i=0,ret=0;
	for(i=0;i<2;i++)
	{
		
		if(ret=fork()==0)
		{
			printf("I am Child Process %d with PID->%d and PPID->%d \n",i,getpid(),getppid());
			
		}
		else
		{
			wait(NULL);
			printf("waiting for child termination\n");
		}
	}
	
	exit(0);
}
