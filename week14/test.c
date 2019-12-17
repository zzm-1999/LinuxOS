#include"my.h"
#define NUM_THREADS 4
void hello(void *t)
{
pthread_t my_tid;
struct info *y;
int s=0;
y=(struct info *)(t);
for(int i=0;i<=y->n;i++)
s+=i;
my_tid=pthread_self();
printf("\tThread %d:my tid is %lx,Hello world\n",(int)y->no+1,my_tid);
printf("\tThread %d:sun 1 to %d is %d\r",(int)y->no,y->n,s);
}
int main()
{
pthread_t tid;
struct info a[4];
int rv,t;
for(t=0;t<NUM_THREADS;t++){
a[t].no=t;
a[t].n=100*(t+1);
rv=pthread_create(&tid,NULL,(void *(*)())hello,(void*)t);
if(rv!=0)
{
printf("thread create failed!\n");
return -1;
}
printf("Create thread %lx\n",tid);
}
printf("goodbye");
pthread_exit(NULL);
}
