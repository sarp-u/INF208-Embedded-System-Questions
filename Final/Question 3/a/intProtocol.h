#include <sys/mman.h>
#include <pthread.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define errExit(msg)      do{  perror(msg);  exit(EXIT_FAILURE);\
                            } while(0)

#define MaxItems 100


struct shmbuf{
    char buffer[MaxItems];
    pthread_mutex_t mutex;
    pthread_mutexattr_t mutex_attr;
    pthread_condattr_t cond_attr;
    pthread_cond_t flag;
    sem_t full;
    sem_t empty;
};