#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
	DIR *d;
	struct dirent *dir;
	struct stat sb,s2;
	int fd=0;
	int i=0,j=0;
	fd=open(argv[2],O_WRONLY | O_APPEND);
	if(fd==-1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	d=opendir(argv[1]);
	if(d==-1)
	{
		printf("Unable to open directory\n");
		return -1;
	}
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{
			if (stat(dir->d_name, &sb) == 0 && S_ISREG(sb.st_mode))
			{	
				s2.st_mode=sb.st_mode;
				s2.st_uid=sb.st_uid;
				s2.st_blksize=sb.st_blksize;
				s2.st_blocks=(int)sb.st_blocks;
				s2.st_nlink=(unsigned int)sb.st_nlink;
				s2.st_size=sb.st_size;
    				j=write(fd,&s2,sizeof(struct stat));
				if(j==-1)
				{
					printf("Write unsuccessfull\n");
				}
				else
				{
					printf("write successfull\n");
				}
			
				
			}
		}
		
	}
	closedir(d);
	close(fd);
	printf("end of program\n");
	return 0;
}


