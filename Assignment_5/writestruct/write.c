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
	fd=open(argv[1],O_WRONLY | O_APPEND);
	if(fd==-1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	struct emp *input = malloc(sizeof(struct emp));
	strcpy(input->name,argv[2]);
	strcpy(input->ID,argv[3]);
	input->pr=argv[4];
	strcpy(input->cmp,argv[5]);
	
	
	i=write(fd,input,sizeof(struct emp));
	if(i==-1)
	{
		printf("Unable to write\n");
		return -1;
	}
	else
	{
		printf("Write successfull\n");
	}
	close(fd);
	return 0;
}
	
