#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#define _XOPEN_SOURCE 500
#define BLOCK 20

int main(int argc,char *argv[])
{
	int fd=0,j=0;
	off_t i=0;
	char arr[BLOCK];
	
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open file");
		return -1;
	}
	
	i=lseek(fd,atoi(argv[2]),SEEK_SET);
	if(i<0)
        {
		printf("%d\n",i);
		return -1;
	}
	j=read(fd,arr,BLOCK);
        if(j==-1)
        {
		printf("pread failed\n");
		return -1;
	}
	write(1,arr,BLOCK);
	close(fd);
	return 0;
}
