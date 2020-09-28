#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
	int i=0;
	int fd=0;

	i=truncate(argv[1],atoi(argv[2]));
	if(i==-1)
	{
		printf("unable to truncate\n");
		return -1;
	}
	printf("truncate successfull\n");
	return 0;
}


