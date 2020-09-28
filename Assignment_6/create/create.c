#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<dirent.h>
int main(int argc,char *argv[])
{
	int fd=0;
	DIR *d;
	struct dirent *dir;
	d=opendir(argv[1]);
	fd=creat(argv[2],0744);
	if(fd==-1)
	{
		printf("File creation failed\n");
		return -1;
	}
	else printf("File creation successfull\n");
	return 0;
}
