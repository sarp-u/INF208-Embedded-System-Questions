#include <ctype.h>
#include <string.h>
#include <syslog.h>
#include <time.h>
#include "pollProtocal.h"



void delay(int number_of_seconds){
    int micro_seconds=1000* number_of_seconds;
    clock_t start_time=clock();
    while(clock() < start_time+micro_seconds);
}

int main(int argc,char *argv[]){
    if(argc != 3){
        fprintf(stderr,"Usage: %s /shm-path delay ms\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    char *shmpath=argv[1];
    long milliseconds = strtol(argv[2], NULL,10);
    
    int fd=shm_open(shmpath,  O_RDWR , 0);
    if(fd==-1){
        errExit("shm_open");
    }
    if(ftruncate(fd , sizeof( struct shmbuf))==-1){
        errExit("ftruncate");
    }
    struct shmbuf *shmp = mmap(NULL, sizeof( struct shmbuf), PROT_READ | PROT_WRITE , MAP_SHARED,fd,0);

    if(shmp == MAP_FAILED)
      errExit("mmap");

    

    openlog("reader:" , LOG_NOWAIT , LOG_USER);
    while(1){
        printf("\nNeue Charge wird gelesen..\n");
        
        
        
        for(int i=0;i<shmp->sizeArr;i++){
         char item = shmp->buffer[i];
        printf("reader:Read Element %c\n",item);
        syslog(LOG_INFO,"reader : Ein Element , %c , wird ins Shared Memory gelesen",item);
        

        }
     delay(milliseconds);
    }
    closelog();
    return 0;


}