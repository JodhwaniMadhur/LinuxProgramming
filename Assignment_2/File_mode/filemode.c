#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	char name[255];
	
		if(access(argv[1],R_OK)<0)
			printf("Our process cannot access the file for reading purpose\n");
		else printf("Our process has read access to the file specified\n");
	
	
		if(access(argv[1],W_OK)<0)
			printf("Our process cannot access the file for writing purpose\n");
		else printf("Our process has write access to the file specified\n");
	
	
		if(access(argv[1],X_OK)<0)
			printf("Our process cannot access the file for execution purpose\n");
		else printf("Our process has executionaccess to the file specified\n");
	
	return 0;
}
