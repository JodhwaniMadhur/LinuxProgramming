#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<dirent.h>
int main(int argc,char *argv[])
{
	char arr[100];
	DIR *d;
	struct dirent *dir;
	struct stat sb;
	
	
	d=opendir(argv[1]);
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{
			printf("%s\t",dir->d_name);
			
			display(dir->d_name);
		}
		printf("\n");
		closedir(d);
	}
	return 0;
	
}		

void display(const struct stat *sb)
{
    switch (sb->st_mode & S_IFMT) 
    {
    case S_IFREG:  printf("regular file\n");            break;
    case S_IFDIR:  printf("directory\n");               break;
    case S_IFCHR:  printf("character device\n");        break;
    case S_IFBLK:  printf("block device\n");            break;
    case S_IFLNK:  printf("symbolic (soft) link\n");    break;
    case S_IFIFO:  printf("FIFO or pipe\n");            break;
    case S_IFSOCK: printf("socket\n");                  break;
    }
}
