#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#define BLOCK 10


int main(int argc,char *argv[])
{
	
	char buf[BLOCK];
	int fd1=0,fd2=0,iRet1=0,iRet2=0;
	
	fd1=open(argv[1],O_RDONLY);
	
	fd2=open(argv[2],O_WRONLY | O_APPEND);
	
	while(iRet1=(read(fd1,buf,BLOCK)!=0))
	{
		write(fd2,buf,BLOCK);
		memset(buf,0,BLOCK); 
	}
	close(fd1);
	close(fd2);
	
	printf("Copy succesfull\n");
	return 0;
}

