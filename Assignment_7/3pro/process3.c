#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int i=0;
	for(i=0;i<atoi(argv[1]);i++)
	{
		
		if(fork()==0)
		{
			printf("I am Child Process %d with PID->%d and PPID->%d \n",i,getpid(),getppid());
			wait(NULL);
		}
		
	}
	exit(0);
}
