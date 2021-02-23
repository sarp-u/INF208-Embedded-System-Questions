#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define errExit(msg)      do{  perror(msg);  exit(EXIT_FAILURE);\
                            } while(0)

#define MaxItems 100


struct shmbuf{
    char buffer[MaxItems];
    int sizeArr;
};