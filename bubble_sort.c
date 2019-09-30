#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 250000
#define RANGE 500000

/* Cria um vetor com MAX elementos e o preenche com numeros
 aleatorios de 1 a RANGE e depois ordena usando o bubble sort */

void swapV(int * A, int * B){
    int aux = *A;
    *A = *B;
    *B = aux;
}

void bubble_sort(int v[], int N){
    while(N>1){
        for(int i=0; i<N; i++){
            if(v[i]>v[i+1]){
                swapV(&v[i], &v[i+1]);
            }
        }
        N-=1;
    }
    return;
}

int main(){
    time_t inicio = time(NULL);
    int vetor[MAX];
    srand(time(NULL));
    for(int i=0; i<MAX; i++){
        vetor[i] = rand() % RANGE;
    }

    bubble_sort(vetor, MAX);

    for(int i=0; i<MAX; i++){
        printf("%d\n", vetor[i]);
    }

    printf("Tempo de execucao: %lds\n\n", time(NULL)-inicio);

    return 1;
}