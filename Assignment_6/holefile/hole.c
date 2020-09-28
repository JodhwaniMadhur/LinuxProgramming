#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    int fd=0,i=0,j=0;
    fd=open(argv[1],O_RDWR);
    if(fd==-1)
    {
    	printf("unable to open file\n");
    	return -1;
    }
    i=lseek(fd,1024,SEEK_END);
    if(i<0)
    {
    	printf("Lseek failed\n");
    	return -1;
    }
    j=write(fd,"z",1);
    if(j==-1)
    {
    printf("Unable to write\n");
    return -1;
    }
    close(fd);
    return 0;
    	
}
