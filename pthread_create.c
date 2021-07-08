#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>
#include<unistd.h>
#include<string.h>

void* print(void* arg){
	sleep(1);
	printf("执行子线程:pthread id=%lu,pid=%u\n",pthread_self(),getpid());
	pthread_exit((void*)100);
}
int main()
{
	pthread_t tid;//线程ID
	int ret,err;
	int* retval;

	ret=pthread_create(&tid,NULL,print,NULL);
	if(ret!=0){
		printf("pthread_create error\n");
		exit(1);
	}
	pthread_detach(tid);//让线程分离，自动退出，无系统残留资源
	
	printf("开始回收\n");
	err=pthread_join(tid,(void**)&retval);
	if(err!=0){
		fprintf(stderr,"pthread_join error:%s\n",strerror(err));
		printf("回收失败\n");
	}
	else{
		printf("回收成功\n");
	}
	pthread_exit(NULL);
}
