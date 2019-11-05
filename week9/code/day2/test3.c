#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
static void __attribute__ ((constructor)) before_main()
{
printf("running before main\n");
}
static void callback1()
{
printf("1:running after main\n");
}
static void callback2()
{
printf("2:running after main\n");
}
static void callback3()
{
printf("3:running after main\n");
}
int main(int argc,char *argv[])
{
atexit(callback1);
atexit(callback2);
atexit(callback3);
printf("test1:pid=%d,ppid=%d\n",getpid(),getppid());
for(int i=0;i<argc;i++)
printf("test3:arg[%d]:%s\n",i,argv[i]);
sleep(2);
printf("test3 finish running");
return 0;
}
