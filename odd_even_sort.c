#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 250000
#define RANGE 500000

/* Cria um vetor com MAX elementos e o preenche com numeros
 aleatorios de 1 a RANGE e depois ordena usando o odd-even sort */

void swapV(int *A, int *B){
    int aux = *A;
    *A = *B;
    *B = aux;
}

void odd_even(int v[]){
    bool ordenado = false;
    while(!ordenado){
        ordenado = true;
        for(int i=1;i<MAX-1; i+=2){
            if(v[i]>v[i+1]){
                swapV(&v[i], &v[i+1]);
                ordenado = false;
            }
        }

        for(int i=0;i<MAX-1; i+=2){
            if(v[i]>v[i+1]){
                swapV(&v[i], &v[i+1]);
                ordenado = false;
            }
        }
    }
}


int main(){
    time_t inicio = time(NULL);
    int vetor[MAX];
    srand(time(NULL));
    for(int i=0; i<MAX; i++){
        vetor[i] = rand() % RANGE;
    }
 
    odd_even(vetor);
    
    for(int i=0; i<MAX; i++){
        printf("%d\n", vetor[i]);
    }

    printf("Tempo de execucao: %lds\n\n", time(NULL)-inicio);

    return 1;
}