#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sighandler(int no)
{
    if(no==SIGINT)
    {
        printf("recieved SIGINT\n");
    }
}

int main(void)
{
   
    if(signal(SIGINT,sighandler)==SIG_ERR)
    {
        printf("Unable to catch SIGINT\n");
    }
    while (1)
    {
        sleep(1);
    }
    
    return 0;
}