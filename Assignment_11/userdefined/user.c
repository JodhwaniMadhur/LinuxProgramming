#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<signal.h>

void sig_handler(int no)
{
    if(no==SIGUSR1)
    {
        printf("recieved SIGUSR1\n");
    }
    if(no==SIGKILL)
    {
        printf("Recieved SIGKILL");
    }
    if(no==SIGSTOP)
    {
        printf("recieved SIGSTOP");
    }
}

int main(void)
{
    if(signal(SIGUSR1,sig_handler)==SIG_ERR)
    {
        printf("Unable to catch SIGUSR\n");
    }
    if(signal(SIGKILL,sig_handler)==SIG_ERR)
    {
        printf("Unable to catch SIGKILL\n");
    }
    if(signal(SIGSTOP,sig_handler)==SIG_ERR)
    {
        printf("Unable to catch SIGSTOP\n");
    }
    while(1)
        sleep(1);
    return 0;
}