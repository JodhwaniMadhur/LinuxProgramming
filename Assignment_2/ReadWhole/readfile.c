#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

#define BLOCK 20

int main(int argc,char* argv[])
{
	int fd=0,i=0;
	char arr[BLOCK];
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("UNABLE TO OPEN FILE\n");
	}
	
	while(i=read(fd,arr,BLOCK)!=0)
	{
		write(1,arr,BLOCK);
		memset(arr,0,BLOCK);
	}
	close(fd);
	return 0;
}
	
