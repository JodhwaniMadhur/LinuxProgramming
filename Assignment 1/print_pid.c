#include<stdio.h>
#include<unistd.h>

int main()
{
pid_t mypid;//header file for process id
mypid=getpid(); //returns PID of calling process
printf("The PID number is %zd\n",(long)mypid);
/*zd or ld both can be used corresponding to size_t or ssize_t
prefer using ld since it can also be used for long long values and also int128_t but exception is not same on all UNIX systems*/
return 0;
}
