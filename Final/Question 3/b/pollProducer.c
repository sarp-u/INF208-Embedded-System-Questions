#include <string.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>
#include "pollProtocal.h"

char *concat(const char *s1,const char *s2){
    char *result=malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result,s1);
    strcat(result,s2);
    return result;

}

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
    char *path=concat("/dev/shm/",shmpath);
    if(access(path,F_OK)!= -1){
        shm_unlink(shmpath);
    }
    int fd=shm_open(shmpath, O_CREAT | O_EXCL | O_RDWR ,S_IRUSR | S_IWUSR);
    if(fd==-1){
        errExit("shm_open");
    }
    if(ftruncate(fd , sizeof( struct shmbuf))==-1){
        errExit("ftruncate");
    }
    struct shmbuf *shmp = mmap(NULL, sizeof( struct shmbuf), PROT_READ | PROT_WRITE , MAP_SHARED,fd,0);

    if(shmp == MAP_FAILED)
      errExit("mmap");


    printf("Neue Charge wird produziert..\n");
    openlog("writer:" , LOG_NOWAIT , LOG_USER);
    
       char *array="Greetings from TAU";
       int size=strlen(array);
        for(int i=0;i<size;i++){
        char item = array[i];
        shmp->buffer[shmp->sizeArr]=item;
        printf("writer:Added Charackter %c by %d\n",item,i);
        syslog(LOG_INFO,"writer: Ein Element , %c , wird ins Shared Memory geschrieben",shmp->buffer[0]);
        shmp->sizeArr++;
        delay(milliseconds);
        
        }
       
     
    closelog();
    return 0;


}