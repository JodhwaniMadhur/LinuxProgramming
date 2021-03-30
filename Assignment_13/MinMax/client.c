#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    int* lib=NULL;
    int (*fptr1)(int*,int);
    int (*fptr2)(int*,int);
    int arr[]={12,34,55,78,1,0,78,98,-3,-8,-1234,67,98,554,7890,456,2378,908,-95479,-1,0,45,789};
    int len=sizeof(arr)/sizeof(int),ret=0;
    lib=dlopen("./libminmax.so",RTLD_LAZY);
    if(lib==NULL)
    {
        printf("Unable to bind library\n");
        return -1;
    }
    fptr1=dlsym(lib,"Max");
    if(fptr1==NULL)
    {
        printf("Unable to load Max function\n");
        return -1;
    }
    ret=fptr1(arr,len);
    printf("The largest number in the array is %d\n",ret);

    fptr2=dlsym(lib,"Min");
    if(fptr2==NULL)
    {
        printf("Unable to load Min function\n");
        return -1;
    }
    ret=fptr2(arr,len);
    printf("The smallest number in the array is %d\n",ret);
    dlclose(lib);
    return 0;
}