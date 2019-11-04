#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
printf("test:pid=%d,ppid=%d",getpid(),getppid());
system("/home/rlk/Desktop/workspace/week9/code/test");
printf("after calling");
return 0;
}
