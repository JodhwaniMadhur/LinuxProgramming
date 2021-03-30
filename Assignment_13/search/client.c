#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dlfcn.h>

int main(int argc,char *argv[])
{
    void *lib=NULL;
    int (*fptr1)(int*,int);
    int (*fptr2)(int*,int*,int);
    int ret,i=0;
    int arr[]={78,65,89,0,1,2,5,6,66,5,4,7,76,7,1,8,9,56,74,20};
    int len=sizeof(arr)/sizeof(int);

    lib=dlopen("./librarysearch.so",RTLD_LAZY);
    if(lib==NULL)
    {
        printf("Unable to link to library\n");
        return -1;
    }
    
    fptr1=dlsym(lib,"sort");
    if(fptr1==NULL)
    {
        printf("Unable to get address of sort\n");
        return -1;
    }
    fptr1(arr,len);
    
    

     fptr2=dlsym(lib,"search");
    if(fptr2==NULL)
    {
        printf("Unable to get address of search\n");
        return -1;
    }
    ret=fptr2(atoi(argv[1]),arr,len);
    printf("found at position %d\n",ret);


    dlclose(lib);
    
    
    return 0;
}