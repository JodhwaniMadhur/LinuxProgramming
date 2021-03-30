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
    char buf[MAX_BUF];
    char* myfifo="./myfifo";
    
    fd=open(myfifo,O_RDONLY);
    if(fd<0)printf("Unable to open PIPE\n");
    read(fd,buf,MAX_BUF);
    printf("%s\n",buf);
    close(fd);
    exit(0);
}