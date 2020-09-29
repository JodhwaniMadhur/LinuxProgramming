#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#define BLOCK 10

int main(int argc,char*argv[])
{
	int fd=0,iRet=0;
	char Arr[BLOCK];
	
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("UNABLE TO OPEN FILE\n");
		return;
	}
	
	while((iRet=read(fd,Arr,BLOCK))!=0)
	{
		write(1,Arr,BLOCK);
		memset(Arr,0,BLOCK);
	}
	close(fd);
	return 0;
}
