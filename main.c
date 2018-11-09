#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define THREADCOUNT 128
#define TRUE 1

//for thread timing/interrupt with start routine
void *threadtime(void *arg){

	unsigned long int total = (unsigned long int)arg;
	int seconds;

	for(seconds = 0; seconds < total; seconds++){

		if((seconds % 1000) == 0){
			printf("tid: 0x%x Just counted to %d of %ld\n", (unsigned int)pthread_self(), seconds, total);
		}

	}

	return arg;
}

int main(int argc, char **argv){
    
	pthread_t threads[THREADCOUNT];
	int create;
	unsigned long int unit = 100000;

	//create THREADCOUNT amount of threads
	for(create = 0; create < THREADCOUNT; create++){

		pthread_create(&threads[create], NULL, threadtime, (void*)((create+1)*unit));
	}
    int i;
    for(i = 0; i<THREADCOUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    //pthread_t thread1;
    //pthread_t thread2;
    //pthread_create(&thread1, NULL, count, (void *)(10000));
    //pthread_create(&thread2, NULL, count, (void *)(10000));
    /*int i = 0;
     while(i < 100000) {
     //printf("i: %d\n", i);
     i++;
     }
     printf("i: %d\n", i);*/
    printf("Hey I'm finished!\n");
	
}
