#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc,char* argv[])
{
	int fd=0;
	if(argv[2]=='r')
	{
		fd=open(argv[1],'r');
		printf("File opened successfully in RD with FD:%d\n",fd);
	}
	if(argv[2]=='w')
		{ 
			fd=open(argv[1],'w');
			printf("File opened successfully in WR with FD:%d\n",fd);
		}
	if(argv[2]=='m')
	{
		fd=fopen(argv[1],"r+");
		printf("File opened successfully in RDWR with FD:%d\n",fd);
	}
	else
	{
		printf("Unable to open file");
	}
	close(fd);
	return 0;
}
