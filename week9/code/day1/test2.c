#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
pid_t result;
result=fork();
int newret;
if(result==-1)
{
perror("false");
exit;

}
else if(result==0)
{
printf("return:%d,pid:%d\n,ppid:%d\n",result,getpid(),getppid());
newret=system("ls-1");
}
else
{
sleep(10);
printf("return:%d,pid:%d\n,ppid:%d\n",result,getpid(),getppid());
newret=system("ping wwww.lupaworld.com");

}
}
