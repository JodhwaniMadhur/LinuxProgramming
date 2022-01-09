#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dirent.h>
int main(int argc,char *argv[])
{
	struct stat sb;
	DIR *d;
	int fd=0,i=0,j=0;
	d=opendir(argv[1]);
	if(d)
	{
		struct dirent *dir;
		while((dir=readdir(d))!=NULL)
		{
			stat(dir->d_name,&sb);
			if(sb.st_size>=1024)
			{
				i=truncate(dir->d_name,1024);
				if(i==-1)
				{
					printf("truncate failed for file:%s\n",dir->d_name);
				}
				else
				{
					printf("%s File truncated successfully\n",dir->d_nam);
				}
			}
			else if(sb.st_size<1024)
			{
				fd=open(dir->d_name,O_RDWR);
				if(fd==-1)
				{
					printf("unable to open file");
				}
				j=lseek(fd,1024,SEEK_SET);
				if(j<0)
				{
					printf("lseek failed for file:%s\n",dir->d_name);
				}
				else
				{
					write(fd," ",1);
					close(fd);
					printf("file hole created for %s\n",dir->d_name);
				}
			}
		}
	}
	closedir(d);
	return 0;
}
