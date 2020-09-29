#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char* argv[])
{
	int fd=0;
	char str[26]="ABCD";
	
	fd=open(argv[1],O_WRONLY | O_APPEND);
	if(fd==-1)
	{
		printf("UNABLE TO OPEN FILE\n");
		return;
	}
	write(fd,str,strlen(str));
	close(fd);
	return 0;
}
