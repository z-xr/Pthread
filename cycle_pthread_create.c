#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

void* func(void* arg){
	int i=(int)arg;
	//sleep(i);
	printf("第%d个线程，pthread id=%lu,pid=%u\n",i,pthread_self(),getpid());
	return NULL;
}
int main()
{
	pthread_t tid;
	int i,ret;
		
	for(int i=0;i<5;i++){
		ret=pthread_create(&tid,NULL,func,(void*)i);
		if(ret!=0){
			fprintf(stderr,"pthread_create error:%s\n",strerror(ret));
			exit(1);
		}
	}
	
	sleep(1);
	printf("main pthread id=%lu,pid=%u\n",pthread_self(),getpid());
	return 0;
}
