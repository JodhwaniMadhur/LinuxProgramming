#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char *argv[])
{
	printf("Start of program\n");
	DIR *d;
	struct dirent *dir;
	int fd=0,m=0;
	char arr[100];
	fd=creat(argv[0],0777);
	if(fd<0) printf("Unable to create file\n");
	fd=open(argv[0],O_WRONLY|O_APPEND);
	if(fd<0) printf("Unable to open file\n");
	d=opendir("/home/madhulicious/Desktop");
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{
			strcpy(arr,dir->d_name);
			write(fd,"\n",1);
			m=write(fd,arr,strlen(dir->d_name));
		}
	}
	closedir(d);
	close(fd);
	return 0;
}	
