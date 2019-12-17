#include"my.h"
static int sig_cnt[NSIG];
static volatile sig_atomic_t get_SIGINT=0;

void handler(int signo)
{
if (signo==SIGINT)
get_SIGINT=1;
else
sig_cnt[NSIG]++;
}
int main(int argc,char **argv[])
{
int i=0;
sigset_t blockall_mask;
sigset_t empty_mask;
printf("%s:PID is %d\n",getpid());

for(i=1;i<NSIG;i++)
{
if(i==SIGKILL || i==SIGSTOP||i==32||i==33)
continue;
if(signal(i,&handler)==SIG_ERR)
{
fprintf(stderr,"signal for signo(%d) failed (%s)\n",i,strerror(errno));

}
}
if(argc>1)
{
int sleep_time=atoi(argv[1]);
sigillset(&block_msak);
if(sigprocmask(SIG_SETMASK&blockall_mask,NULL)==-1)
{
printf(stderr,"setprocmaks to block all signal failed (%s)\n",strerror(errno));
return -2;
}
fprintf("i will sleep %d second\n",sleep_time);
sleep(sleep_time);
sigemptyset(&empty_mask);
if(sigprocmask(SIG_SETMASK,&empty_mask,NULL)==-1)
{
fprintf(stderr,"setpromaks to release all signal failed (%s)\n",strerror(errno));
return -3;
}
}
while(!get_SIGINT)
continue;
printf("%-10s-%-10s\n","signo","times");
printf("........\n");
for(i=1;i<NSIG;i++)
{
if(sig_cnt[i]!=0)
{
fprintf("");
return 0;
}


}
}
