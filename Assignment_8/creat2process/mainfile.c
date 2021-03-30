#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int ret1=0,ret2=0,status=0,pid=0;
	ret1=fork();
	if(ret1==0)
	{
		printf("Running P1 process\n");
		execl("./process1",argv[1],argv[3],NULL);
	}
	else
	{
		printf("Parent waiting for p1\n");
		pid=wait(&status);
		printf("Terminating Child Process 1\n");
	}
	ret2=fork();
	if(ret2==0)
	{
		printf("Running P2 process\n");
		execl("./process2",argv[2],argv[3],NULL);
	}
	else
	{
		printf("Parent waiting for p2\n");
		pid=wait(&status);
		printf("Terminating Child Process 2\n");
	}
	return 0;
}
