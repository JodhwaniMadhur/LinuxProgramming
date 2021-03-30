#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	pid_t pid=fork();
	if(pid==0)
	{
		printf("Child Process=>PPID: %d  PID:%d\n",getppid(),getpid());
		return 0;
	}
	else if(pid>0)
	{
	printf("parent=>PID:%d\n",getpid());
	printf("waiting for chid process\n");
	wait(NULL);
	printf("Child Process terminated\n");
	}
	else
	{
		printf("Unable to create child process\n");
	}
        return 0;
}
