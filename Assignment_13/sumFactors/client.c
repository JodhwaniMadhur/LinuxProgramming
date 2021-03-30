#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dlfcn.h>

int main(int argc,char* argv[])
{
    void* lib=NULL;
    int (*fptr) (int);
    int ret=0;
    lib=dlopen("./libraryfactors.so",RTLD_LAZY);
    if(lib==NULL)
    {
        printf("unable to open library\n");
        return -1;
    }

    fptr=dlsym(lib,"sumFactors");
    if(fptr==NULL)
    {
        printf("Unable to link to library\n");
        return -1;
    }   
    ret=fptr(atoi(argv[1]));
    printf("The Sum of factors of %d is %d\n",atoi(argv[1]),ret);
    dlclose(lib);
    return 0;
}
