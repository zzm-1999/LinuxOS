#include "my.h"
static void __attribute__((constructor)) before_main()
{
	printf("-------------constructor-----------\n");
}
static void __attribute__((destuctor)) before_main()
{
	printf("-------------destructor-----------\n");
}
static void callback1()
{
	printf("------------callback1-----------\n");
}
static void callback2()
{
	printf("------------callback2-----------\n");
}

int main(int argc,char *argv[])
{
	atexit(callback1);
	atexit(callback2);
	FILE *fp;
	char buf[]={"test data!"};
	if((fp=open("test.dat","w"))==NULL)
	{
		perror("failed to fopen!\n");
		return -1;
	}
	if(fputs(buf,fp)==EOF)
	{
		perror("failed to fputs!\n");
		return -1;
	}
	printf("printf:data from line buffer");
	exit(0);
}
