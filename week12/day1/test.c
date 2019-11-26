
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
 
int tprintf(const char *fmt,...);
 
int main(void)
{
	printf("I'm your father,PID is %d.\n",getpid());
	pid_t pid = fork();
	if(pid == 0){
		printf("I'm a first son.PID is %d.\n",getpid());
		exit(1);//若此处没有exit（1）， 进程也会执行 pid_t pid2 = fork()语句,会出现孙进程
		printf("You should never see this.\n");
	}
	pid_t pid2 = fork();
	if(pid2 == 0){
		printf("I'm a second son.PID is %d.\n",getpid());
		exit(1);
		printf("You should never see this.\n");
	}
	pid_t pid3 = fork();
	if(pid3 ==0){
		printf("I'm a third son.PID is %d.\n",getpid());
		exit(1);
		printf("You should never see this.\n");
	}
	else if(pid != -1){
		tprintf("Parent forked child process--%d.\n",pid);
		tprintf("Parent is waiting for child to exit.\n");
		waitpid(pid,NULL,0);
		waitpid(pid2,NULL,0);
		waitpid(pid3,NULL,0);
		tprintf("Child Process had exited.\n");
		tprintf("Parent had exited.\n");
	}
	else	tprintf("Everything was done without error.\n");
 
	return 0;
}
 
 
/*
* 设置输出格式
*/
int tprintf(const char* fmt,...)
{
	va_list args;
	struct tm *tstruct;
	time_t tsec;
	tsec = time(NULL);
	tstruct = localtime(&tsec);
	printf("%02d:%02d:%02d:%5d|",tstruct->tm_hour,tstruct->tm_min,tstruct->tm_sec,getpid());
	va_start(args,fmt);
	return vprintf(fmt,args);
}


