#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define MAX_BUF 1024

int main()
{
    int fd=0;
    char* myfifo="./myfifo";
    mkfifo(myfifo,0666);

    fd=open(myfifo,O_WRONLY);
    if(fd<0)printf("Unable to open PIPE\n");
    write(fd,"MADHUR JODHWANI",sizeof("MADHUR JODHWANI"));
    close(fd);
    unlink(myfifo);
    exit(0);
}