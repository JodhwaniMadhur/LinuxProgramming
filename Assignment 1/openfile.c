#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	int fd=0,iRet=0;
	char *Arr=NULL;
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open file\n");
	}
	else
	{
		printf("File opened with file descriptor %d\n",fd);
		
	}
	Arr=(char*)malloc(sizeof(char)*5);//this is not platform or OS specific but will allocate array for 5 characters
	iRet=read(fd,Arr,5);//read from the arr 5 characters that has fd of the file
	if(iRet==-1)
	{
		printf("Unable to read from file\n");
		close(fd);
		free(Arr);
	}
	printf("%s\n",Arr);
	close(fd);
	free(Arr);
	return 0;
}
