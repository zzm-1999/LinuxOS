#include"stdio.h"
#include"stdlib.h" //exit包含在stdlib.h头文件中
#include"unistd.h"
int main(void)
{
pid_t pid1,pid2;
pid1=fork();
switch(pid1)
{
case 0: //进程创建成功，返回值为0
printf("b"); //子进程1创建成功，输出b
break;
case -1:
printf("Process creation failed\n");//子进程创建失败，输出错误信息
break;
default:
printf("a");//此时执行父进程，输出a
sleep(1);
exit(0);
break;
}
pid2=fork();
switch(pid2)
{
case 0: //进程创建成功，返回值为0
printf("c"); //子进程2创建成功，输出c
break;
case -1:
printf("Process creation failed\n");//子进程创建失败，输出错误信息
exit(0);
break;
default:
printf("a");//此时执行父进程，输出a
//sleep(1);
exit(0);
break;
}
exit(0);
}
