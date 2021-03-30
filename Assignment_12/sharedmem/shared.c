#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define BLOCK 128

int main()
{
    pid_t child1=0,child2=0;
    char c;
    int shmid;
    char* shm,*s;
    child1=fork();
    key_t key=ftok(".",11);
    if(child1==0)
    {
        
        shmid = shmget(key, BLOCK, IPC_CREAT | 0666);
        shm=shmat(shmid,NULL,0);
        for (c = 'a'; c <= 'z'; c++)
	    {
        	*s = c;
		    s++;	
	    }
        *s = NULL;
        while (*shm != '*')
            sleep(10);

    }
    else
    {

       wait();
    }
    if((child2=fork())==0)
    {
        shmid=shmget(key,BLOCK,0666);
       shm = shmat(shmid, NULL, 0);
        for (s = shm; *s != NULL; s++)
        putchar(*s);
        putchar('\n');
        *shm = '*';
    }

    return 0;
}