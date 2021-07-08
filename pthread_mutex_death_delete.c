#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex_A;
pthread_mutex_t mutex_B;

void *tfn(void *arg)
{ 
	srand(time(NULL));
 	while (1) {
		int death_pid;
		pthread_mutex_lock(&mutex_B);
		sleep(1);
		if(pthread_mutex_trylock(&mutex_A)!=0){
			pthread_mutex_unlock(&mutex_B);
			printf("trylock fail,delete mutex_B\n");
			sleep(1);
		}
		else{
 			printf("hello ");
 			printf("world\n");
			pthread_mutex_unlock(&mutex_A);
			pthread_mutex_unlock(&mutex_B);
			sleep(rand() % 3);
		}
 	}
 	return NULL;
}
int main(void)
{
 	pthread_t tid;
 	srand(time(NULL));
	pthread_mutex_init(&mutex_A,NULL);//mutex=1
	pthread_mutex_init(&mutex_B,NULL);

 	pthread_create(&tid, NULL, tfn, NULL);
 	while (1) {
		pthread_mutex_lock(&mutex_A);
		sleep(1);
		pthread_mutex_lock(&mutex_B);
 		printf("HELLO ");
 		printf("WORLD\n");
		pthread_mutex_unlock(&mutex_B);
		pthread_mutex_unlock(&mutex_A);
		sleep(rand() % 3);
 	}
 	pthread_join(tid, NULL);
	pthread_mutex_destroy(&mutex_A);
	pthread_mutex_destroy(&mutex_B);
 	return 0;
} 
