#include "pilha.h"

void push(Pilha * pilha, Pilha * no){
    no->proximo = pilha->proximo;
    pilha->proximo = no;
    return;
}

Pilha pop(Pilha * pilha){
    pilha->proximo = 
}