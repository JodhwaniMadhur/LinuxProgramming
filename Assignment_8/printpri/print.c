#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int main()
{
	int rc=0;
	pthread_t thread1;
	printf("Inside main thread\n");
	int policy, s=1;
    struct sched_param param;
    pthread_attr_t attr;
        

    s = pthread_getschedparam(pthread_self(), &policy, &param);
    if (s != 0)
        printf("Unable to call priority function\n");

	printf("Thread priority:%d\n",s);
	s=nice(-2);
	printf("Thread priority:%d\n",s);
	printf("terminating main thread\n");
	return 0;
}
