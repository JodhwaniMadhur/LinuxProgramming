#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>


int main(int argc,char *argv[])
{
	
	DIR *d;
	struct stat sb;
	d=opendir(argv[1]);
	if(d)
	{
		struct dirent *dir;
		while((dir=readdir(d))!=NULL)
		{
			int i;
			i=stat(argv[2] , &sb);
			if(i==0)
			{
				printf("Present\n");
				break;
			}
			else
			{
				printf("File not present\n");
				break;
			}
		}
		
		closedir(d);
	}
	return 0;
}

