#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
int i;
printf("test:pid%d,ppid%d\n",getpid(),getppid());
for(i=0;i<argc;i++)
{
printf("%s\n",argv[i]);
}


