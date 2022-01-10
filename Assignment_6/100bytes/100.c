#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>



int main(int argc,char *argv[])
{
	
	DIR *d;
	struct dirent *dir;
	struct stat sb;
	
	
	d=opendir(argv[1]);
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{
			stat(dir->d_name,&sb);
			printf("%d\n",(int)sb.st_size);
			if(sb.st_size>100)
			{
				remove(dir->d_name);
			}
		}
		closedir(d);
		printf("Deletion Succesfull\n");
	}
	return 0;
}

