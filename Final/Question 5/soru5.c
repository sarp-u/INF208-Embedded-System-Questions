#include <stdio.h>
#include <stdlib.h>
#define Nconst 100

int **add_array;

int main(){
  
    int array[Nconst];
    int a, N;

    printf("Geben Sie die Groesse des Arrays ein, N=");
    scanf("%d", &N);   
    for(int i=0; i< N; ++i){
        add_array = calloc(N, sizeof(int **));
    }
    
    if(!add_array){
        free(add_array);
        exit(0);
    }
    printf("Geben Sie die Nummern des Arrays ein \n");
    for(int i=0; i< N; ++i){
        printf("Element[%d]=",i);
        scanf("%d", &array[i]);
    }
       
    for(int i= 0; i < N; ++i){
        add_array[i] = &(array[i]);
    }
    for(int i = 0; i< N; ++i){
        for(int j = i + 1; j< N; ++j){
            if(*add_array[i] > *add_array[j]){
                a = *add_array[i];
                *add_array[i] = *add_array[j];
                *add_array[j] = a;
            }
        }
    }

    printf("Die in aufsteigender Reihenfolge angeordneten Nummern sind unten angegeben \n");
    for(int i= 0; i< N; ++i){
        printf("%d\n", *add_array[i]);
    }

    free(add_array);
    exit(0);
} 