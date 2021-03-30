#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
	DIR *d;
	struct dirent *dir;
	struct stat sb;
	printf("Start of program\n");
	int i=1;
	char arr[]=".txt";
	d=opendir("/home/madhulicious/Desktop/mj/");
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{	
			stat(dir->d_name,&sb);
			if(S_ISREG(sb.st_mode))
			{
				rename(dir->d_name,strcat(i,arr));
				printf("%s\n",strcat(i,arr));
				i++;
			}
			printf("%s\n",dir->d_name);
		}
	}
	closedir(d);
	return 0;
}
