#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

int a=10;

void* func1(void* arg){
	a=100;
	printf("pthread id=%lu,a=%d\n",pthread_self(),a);
	return NULL;
}


void* func2(void* arg){
        printf("pthread id=%lu,a=%d\n",pthread_self(),a);
        return NULL;
}
int main()
{
	pthread_t tid1,tid2;
	int ret;
	
	ret=pthread_create(&tid1,NULL,func1,NULL);
	if(ret!=0){
		printf("pthread create error\n");
		exit(1);
	}
	sleep(1);
	ret=pthread_create(&tid2,NULL,func2,NULL);
	if(ret!=0){
		printf("pthread create error\n");
		exit(1);
	}
	sleep(1);
	return 0;
}	
