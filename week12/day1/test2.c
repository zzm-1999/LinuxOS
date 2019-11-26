#include "my.h"
int count=0;
int main()
{
	pid_t p1,p2,p3;
	int r_num,i,sum=0;
	int pipefd[2];
	int buf[4098];
	if(pipe(pipefd)<0)
	{
		perror("pipe failed.\n");
		return -1;
	}
	p1=fork();
	if(p1<0)
	{
		perror("fork1 failed.\n");
		return -1;
	}	
	else if(p1==0)
	{
		count+=1;
		printf("child1 pid=%d,pidd=%d,count=%d\n",getpid(),getppid(),count);
		for(i=0;i<=4098;i++)
			buf[i]=i;
		close(pipefd[0]);
		write(pipefd[1],buf,sizeof(buf));
		close(pipefd[1]);
		exit(99);
	}
	else	
	{	
		//printf("parent fork second time.\n");
		p2=fork();
		if(p2<0)
		{
			perror("fork2 failed\n");
			return -1;
		}
		else if(p2==0)
		{
			count+=1;
			printf("child2 pid=%d,pidd=%d,count=%d\n",getpid(),getppid(),count);
			close(pipefd[1]);
			r_num=read(pipefd[0],buf,sizeof(buf));
			close(pipefd[0]);
			exit(34);
		}
		else
		{
			//printf("parent fork third time.\n");
			p3=fork();
			if(p3<0)
			{
				perror("fork2 failed\n");
				return -1;
			}
			else if(p3==0)
			{
				count+=1;
				printf("child3 pid=%d,pidd=%d,count=%d\n",getpid(),getppid(),count);
				close(pipefd[1]);
				if((r_num=read(pipefd[0],buf,sizeof(buf)))>0)
				{
					for(i=0;i<=4098;i++)
						sum=sum+buf[i];
				}
				printf("child3 :sum= %d",sum);
				close(pipefd[0]);
				return 0;
			}
			else
			{
				printf("parent waitting\n");
				sleep(5);
				printf("parent pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
				return 0;			
			}
		}
	}
}
