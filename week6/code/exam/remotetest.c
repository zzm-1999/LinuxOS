#include "dylib.h"
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
int main()
{
	int a[5];
	

	void *hd;
	char *error;
	void(*f1)();
	int (*f2)(),(*f3)();
	void(*f4)();
	
	hd=dlopen("../dynamic/libdylib.so",RTLD_LAZY);

	if(!hd){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
}

	f1=dlsym(hd,"show");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
}

	f2=dlsym(hd,"max");
		if((error=dlerror())!=NULL){
			fprintf(stderr,"%s\n",dlerror());
			exit(1);
	}

	f3=dlsym(hd,"sum");
		if((error=dlerror())!=NULL){
			fprintf(stderr,"%s\n",dlerror());
			exit(1);
	}

	f4=dlsym(hd,"init");
			if((error=dlerror())!=NULL){
				fprintf(stderr,"%s\n",dlerror());
				exit(1);
		}
	f4(a,5);
	f1(a,5);
	printf("max = %d\n",f2(a,5));
	printf("sum = %d\n",f3(a,5));
	return 0;
}
