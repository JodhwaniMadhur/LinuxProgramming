#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#define MARVELLOUS 11
int main()
{
int no=MARVELLOUS;
	pid_t pid=fork();
	printf("I am the orignal process and my PPID=>%d and my PID=>%d\n",getppid(),getpid());
	if(pid!=0)
	{
		printf("I am parent process with PPID=>%d and my PID=>%d\n",getppid(),getpid());
		printf("My child's PID=> %d\n",pid);
	}
	else
	{
		printf(" I am the child process with PPID=>%d and my PID=>%d\n",getppid(),getpid());
	}
	printf("pid %d terminates\n",getpid());
}
