#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
#define BLOCK 100

int main(int argc,char *argv[])
{
	
		int fd1=0,fd2=0,i=0,j=0;
		int arr[BLOCK];
		int brr[BLOCK];
		struct stat sb1;
		struct stat sb2;
		stat(argv[1],&sb1);
		stat(argv[2],&sb2);
		
		
		fd1=open(argv[1],O_RDONLY);
		if(fd1==-1)
		{
			printf("Unable to open first file\n");
			return -1;
		}
		
		
		fd2=open(argv[2],O_RDONLY);
		if(fd2==-1)
		{
			printf("Unable to open second file\n");
			return -1;
		}
		
		
		i=read(fd1,arr,BLOCK);
		if(i==-1)
		{
			printf("Unable to read file 1\n");
			return -1;
		}
		
		
		j=read(fd2,brr,BLOCK);
		if(j==-1)
		{
			printf("Unable to read file 2\n");
			return -1;
		}
		memset(arr,0,BLOCK);
		memset(brr,0,BLOCK);
		if(sb1.st_size > sb2.st_size)
		{
			while(read(fd1,arr,BLOCK)!=0)
				{
					if(strcmp(arr,brr)!=0)
						printf("FIles are not equal\n");
					else
					{
						memset(arr,0,BLOCK);
						memset(brr,0,BLOCK);
						read(fd2,brr,BLOCK);
					}
				}
				printf("Files are equal but length of file2 is greater and file1=file2 till length of file 2\n"); 
		}
		
		else if(sb2.st_size > sb1.st_size)
		{
			while(read(fd2,brr,BLOCK)!=0)
				{
					if (strcmp(arr,brr)!=0) 
					{
						printf("Files not equal\n");
					}
					else
					{
						memset(arr,0,BLOCK);
						memset(brr,0,BLOCK);
						read(fd1,arr,BLOCK);
					}
				}
				printf("Files are equal but length of file2 is greater and file1=file2 till length of file 2\n"); 
		}
		
		else
		{
			while(read(fd1,arr,BLOCK)!=0)
			{
				if(strcmp(arr,brr)!=0)
				{
					printf("file not equal");
					break;
				}
				else
				{
					memset(arr,0,BLOCK);
					memset(brr,0,BLOCK);
					read(fd2,brr,BLOCK);
				}
			}
			printf("Files are equal\n");
		}
	
	return 0;
}
					
				
	
	
	
	
	
	
	
	
	
	
	
	
			
