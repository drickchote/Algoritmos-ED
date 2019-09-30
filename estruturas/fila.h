#ifndef fila_H_
#define fila_H_
#endif
#define DEBUG

typedef struct fila Fila;

struct fila{
    Fila * proximo;
    int numero;
    Fila * anterior;
};



void push(Fila * ultimo, Fila * novo);

Fila* pop(Fila * inicio);

void imprimir_numeros_fila(Fila * inicio);

