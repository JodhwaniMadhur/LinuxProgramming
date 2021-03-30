#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char*argv[])
{
	int fd=0,cnt=0;
	
	char arr[100]={'\0'};
	
	fd=open(argv[0],O_RDONLY);
	if(fd<0)printf("Unable to open %s  File\n",argv[0]);
	while((read(fd,arr,100))!=0);
	{
		for(int i=0;i<100;i++)
		{
			if((arr[i]>='A')&&(arr[i]<='Z'))cnt++;
		}
	}
	
	close(fd);
	fd=0;
	fd=open(argv[1],O_WRONLY|O_APPEND);
	if(fd<0)printf("Unable to open %s file\n",argv[1]);
	write(fd,&cnt,sizeof(cnt));
	
	close(fd);
	return 0;
}
