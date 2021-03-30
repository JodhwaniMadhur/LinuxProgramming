#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(void)
{
    int fd[2],nbytes;
    pid_t childpid;
    
    char buffer[100];

    pipe(fd);
    childpid=fork();
    if(childpid==0)
    {
        char string[]="MARVELLOUS INFOSYSTEMS MADHUR JODHWANI LB006";
        close(fd[0]);//close input side of pipe
        write(fd[1],string,strlen(string)+1);
        exit(0);
    }
    else
    {
       close(fd[1]);
       nbytes=read(fd[0],buffer,sizeof(buffer));
       printf("Recieved String:%s\n",buffer);
       
    }
    return 0;
}