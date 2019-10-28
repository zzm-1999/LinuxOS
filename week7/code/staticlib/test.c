
#include"mylib.h"
#define MAX 128
int chmd()
{
	int c;
	mode_t mode=S_IWUSR;
	printf("************************\n");
	printf("0. 用户读、写和执行\n");
	printf("1. 用户只读\n");
	printf("2. 用户只写\n");
	printf("3. 用户执行\n");
	printf("************************\n");
	printf("please input your choice:");
	scanf("%d",&c);
	switch(c)
	{
		case 0:chmod("file1",S_IRWXU);break;
		case 1:chmod("file1",S_IRUSR);break;
		case 2:chmod("file1",S_IWUSR);break;
		case 3:chmod("file1",S_IXUSR);break;
		default:printf("you have a wrong choice\n");
	}
	return 0;
}
void test()
{
	int fd;
	int num;
	int choice;
	char buffer[MAX];
	struct stat buf;
	char* path="/bin/ls";
	char* argv[4]={"ls","-1","file1","NULL"};
	while(1)
	{
		printf("*********主菜单*********\n");
		printf("0. exit\n");
		printf("1. new file\n");
		printf("2. write file\n");
		printf("3. read file\n");
		printf("4. modefy permissions\n");
		printf("5. view permissions\n");
		printf("************************\n");
		printf("please input your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				close(fd);
				exit(0);
			case 1:
				fd=open("file1",O_RDWR|O_TRUNC|O_CREAT,0705);
				if(fd==-1)
					printf("file create failed\n");
				else printf("fd =%d\n",fd);
				break;
			case 2:
				num=read(0,buffer,MAX);
				write(fd,buffer,num);
				break;
			case 3:
				read(fd,buffer,MAX);
				write(1,buffer,num);
				break;
			case 4:
				chmd();
				printf("change mode success\n");
				break;
			case 5:
				execv(path,argv);
				break;
			default:printf("you have wrong choice\n");
		}
	}
}
