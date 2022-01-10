#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
int main(int argc,char *argv[])
{
	DIR *d;
	struct dirent *dir;
	struct stat s2;
	int fd=0;
	int i=0,j=0;
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	
	while(read(fd,&s2,sizeof(struct stat))!=0)
				{
					
					printf("File st_uid %d \n",s2.st_uid);
  					printf("File st_blksize %ld \n",s2.st_blksize);
  					printf("File st_gid %d \n",s2.st_gid);
  					printf("File st_blocks %d \n",(int)s2.st_blocks);
  					printf("File st_size %d \n",(int)s2.st_size);
  					printf("File st_nlink %u \n",(unsigned int)s2.st_nlink);
  					printf("File Permissions User\n");
  					printf((s2.st_mode & S_IRUSR)? "r":"-");
  					printf((s2.st_mode & S_IWUSR)? "w":"-");
  					printf((s2.st_mode & S_IXUSR)? "x":"-");
  					printf("");
  					printf("File Permissions Group\n");
  					printf((s2.st_mode & S_IRGRP)? "r":"-");
  					printf((s2.st_mode & S_IWGRP)? "w":"-");
  					printf((s2.st_mode & S_IXGRP)? "x":"-");
  					printf("");
  					printf("File Permissions Other\n");
  					printf((s2.st_mode & S_IROTH)? "r":"-");
  					printf((s2.st_mode & S_IWOTH)? "w":"-");
  					printf((s2.st_mode & S_IXOTH)? "x":"-");
  					printf("\n--------------------------------------\n");
  					memset(&s2,0,sizeof(struct stat));
				}
			
	close(fd);
	printf("end of program\n");
	return 0;
}


