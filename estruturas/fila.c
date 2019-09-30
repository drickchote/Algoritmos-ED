#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void push(Fila * raiz, Fila * novo){
    Fila *aux = raiz;
    while(aux->anterior !=NULL){
        aux = aux->anterior;
    }
    novo->proximo = aux;
    aux->anterior = novo;
    novo->anterior = NULL;
};

Fila* pop(Fila * fila){
    if(fila->anterior == NULL){
        #ifdef DEBUG
            printf("A fila já está vazia");
        #endif
        return fila;
    }
    Fila * aux = fila->anterior;
    fila->anterior  = fila->anterior->anterior;
    return(aux);
};

void imprimir_numeros_fila(Fila * inicio){
    printf("%d\n",inicio->numero);
    if(inicio->anterior==NULL)
        return;
    else
    {
        return imprimir_numeros_fila(inicio->anterior);
    }
    
};
