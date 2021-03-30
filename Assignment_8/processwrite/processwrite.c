#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc,char *argv[])
{
	int ret=0,status=0,pid=0;
	ret=fork();
	if(ret==0)
	{
		printf("Running Read Directory process\n");
		execl("./process",argv[1],NULL);
	}
	else
	{
		printf("Parent process is waiting\n");
		pid=wait(&status);
		printf("Terminating Child Process\n");
	}
	exit(0);
}
