#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>



int main(int argc,char *argv[])
{
	DIR *d;
	long long int m = 0;
	struct stat sb;
	d=opendir(argv[1]);
	if(d)
	{
		struct dirent *dir;
		while((dir=readdir(d))!=NULL)
		{
			stat(dir->d_name,&sb);
			if(sb.st_size>m)
			{
				m=sb.st_size;
			}
		}
		printf("%lld bytes\n",m);
		closedir(d);
	}
	return 0;
}



