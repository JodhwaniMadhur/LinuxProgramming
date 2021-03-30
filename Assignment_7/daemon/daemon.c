#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>

int main()
{
    pid_t pid;
    pid_t sid;
    FILE *fp = NULL;
    
    pid = fork();
    
    if(pid < 0)
    {
        printf("Fork fails");
        exit(-1);
    }
    
    // parent
    if(pid > 0)
    {
        printf("PID of child process is %d\n",pid);
        exit(0);
    }
    
    umask(0);
    
    // Create the session
    sid = setsid();
    
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    fp = fopen("Log.txt","w+");
    if(fp == NULL)
    {
        printf("Unable to create file");
    }
    
    // Task of a deamon process
    while(1)
    {
        sleep(2);
        
        fprintf(fp,"Process is running");
        
        fflush(fp);
    }
    
    fclose(fp);
    
    return 0;
}

