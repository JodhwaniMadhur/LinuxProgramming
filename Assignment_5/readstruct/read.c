#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

struct emp
{
	char name[20];
	char ID[10];
	int pr;
	char cmp[30];
};
	
int main(int argc,char *argv[])
{
	int fd=0,i=0;
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	struct emp *input = malloc(sizeof(struct emp));
	
	i=read(fd,input,sizeof(struct emp));
	if(i==-1)
	{
		printf("Unable to read\n");
		return -1;
	}
	else
	{
		printf("Name:%s\nID:%s\nNo. of projects%d\nCompany:%s\n",input->name,input->ID,input->pr,input->cmp);
	}
	close(fd);
	return 0;
}
	
