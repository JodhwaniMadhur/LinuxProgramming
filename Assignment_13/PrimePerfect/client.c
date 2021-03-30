#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dlfcn.h>

int main(int argc,char* argv[])
{
    void* lib=NULL;
    int (*fptr) (int);
    int ret=0;
    lib=dlopen("./libraryprime.so",RTLD_LAZY);
    if(lib==NULL)
    {
        printf("unable to open library\n");
        return -1;
    }

    fptr=dlsym(lib,"Prime");
    if(fptr==NULL)
    {
        printf("Unable to link to library\n");
        return -1;
    }   
    ret=fptr(atoi(argv[1]));
    if(ret==1)
        printf("The number is prime\n");
    else if(ret==atoi(argv[1]))
        printf("The number is Perfect\n");
    else printf("Number is neither Prime nor perfect.\n");
    dlclose(lib);
    return 0;
}
