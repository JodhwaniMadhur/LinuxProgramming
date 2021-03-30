#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

extern char **environ;
int main()
{
	char *s = getenv ("HOME");
	printf("%s\n",s);
	exit(0);
}
