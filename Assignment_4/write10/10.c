#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#define BLOCK 10
int main(int argc,char *argv[])
{
	DIR *d;
	int fd=0,fd2=0;
	struct dirent *dir;
	char arr[BLOCK];
	d=opendir(argv[1]);
	if(d)
	{
		fd2=open(argv[2],O_WRONLY|O_APPEND);
		while((dir=readdir(d))!=NULL)
		{
			fd=open((char)dir->d_name,O_RDONLY);
			read(fd,arr,BLOCK);
			close(fd);
			write(fd2,(char)arr,BLOCK);
			write(1,(char)arr,BLOCK);
			printf("\n");
		}
		close(fd2);
		closedir(d);
		printf("\nWrite from directory successfull\n");
	}
	return 0;
}	
