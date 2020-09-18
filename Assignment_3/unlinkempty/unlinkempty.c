#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>



int main(int argc,char *argv[])
{
	
	DIR *d;
	long long int m = 0;
	struct dirent *dir;
	struct stat sb;
	
	
	d=opendir(argv[1]);
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{
			stat(dir->d_name,&sb);
			if(sb.st_size==0)
			{
				unlink(dir->d_name);
			}
		}
		closedir(d);
		printf("Deletion Succesfull\n");
	}
	return 0;
}


