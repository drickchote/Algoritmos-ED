#include "fila.h"
#include <stdlib.h>
#include <stdio.h>
#define N 100

int main(){
    Fila *inicio = malloc(sizeof(Fila));
    inicio->anterior = NULL;
    inicio->numero = -1;
    pop(inicio);
    //preenche fila
    for(int i=0; i<N; i++){
        Fila * no = malloc(sizeof(Fila));
        no->numero = i; //no->numero == (*no).numero
        push(inicio, no);
        if(no->numero % 2 == 0){
            Fila * aux = pop(inicio);
            free(aux);
        }
    } 

    imprimir_numeros_fila(inicio);

    return 1;
}