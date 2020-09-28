#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
	int d=0;
	if(argc != 2)
	{
		printf("Number of input parameters required are not met");
	}
	else
	{
		d=mkdir( argv[1] , S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH );
		if(d==-1)
		{
			printf("Unable to create directory");
		}
		else
		{
			printf("Directory created successfully");
		}
	}
	return 0;
}
