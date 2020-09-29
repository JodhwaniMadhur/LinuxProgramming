#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char* argv[])
{
	int fd=0;
	
	fd=open(argv[1],O_RDWR|O_APPEND);
	if(fd==-1)
	{
		printf("Unable to open file\n");
	}
	else
	{
		printf("File successfully opened with FD:%d\n",fd);
	}
	fd=write(fd,argv[2],strlen(argv[2]));
	if(fd==-1)
	{
		printf("UNABLE TO WRITE IN FILE\n");
	}
	else
	{
		printf("WRITE OPERARTION SUCCESSFULL\n");
	}
	return 0;
}
