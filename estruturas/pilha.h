#ifndef pilha_h_
#define pilha_h_


typedef struct pilha Pilha;

struc pilha{
    Pilha * proximo;
    int cod; 
}

void push(Pilha * pilha, Pilha * no);

Pilha * pop(Pilha pilha);






#endif