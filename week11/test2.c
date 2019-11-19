#include"my.h"
int main()
{
int pid;
if(pid=fork()<0)
{
perror("failes to fork!\n");
return -1;
}
else if(pid=0)
{
printf("%d : child is running now\n",gitpid());
while(1);
printf("%d : child exit now\n",gitpid());
exit(0);
}
else {
printf("%d : parent is running",gitpid());
while(1);
}
exit(0);
}
