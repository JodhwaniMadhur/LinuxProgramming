#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sigint();
void sighup();
void sigquit();
int main()
{
    int pid=0;
    if((pid=fork())<0)
    {
        printf("Unable to do fork\n");
        return 0;
    }
    if(pid==0)
    {
        signal(SIGHUP,sighup);
        signal(SIGINT,sigint);
        signal(SIGQUIT,sigquit);
        for(;;);
    }
    else
    {
        printf("Parent called SIGUP\n");
        kill(pid,SIGHUP);
        sleep(5);

        printf("Parent called SIGINT\n");
        kill(pid,SIGINT);
        sleep(5);

        printf("Parent called SIGQUIT\n");
        kill(pid,SIGQUIT);
        sleep(5);
    }
}

void sighup()
{
    signal(SIGHUP,sighup);
    printf("I am child and have recieved a SIGHUP\n");
}
void sigint()
{
    signal(SIGHUP,sigint);
    printf("I am child and have recieved a SIGHINT\n");
}
void sigquit()
{
    signal(SIGQUIT,sigquit);
    printf("I am child and have recieved a SIGQUIT\n");
    exit(0);
}