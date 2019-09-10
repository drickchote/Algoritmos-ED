#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tadVetor.h"

/* *********************************************** */
/* *********************************************** */
bool defineVetor(tVetor* V, int n) {

	V->numElem = 0;

	if (n > MAX) {
		V->MaxElem = 0;
		return false;
		}

	V->MaxElem = n;

	return true;
}

/* *********************************************** */
/* *********************************************** */
bool preencheVetorAleatorio(tVetor* V, int n) {

int 	i,
		num;

	if (V->MaxElem > n)
		return false;

	for (i = 0 ; i < n; i++) {
		num = ( rand() % (MAX) );
		V->V[i] = num;
		V->numElem++;
		}
	return true;
}

/* *********************************************** */
/* *********************************************** */
void imprimeVetor(tVetor V) {

int i;

	printf("------------------------------\n");

	if (V.numElem == 0)
		printf("\nVETOR VAZIO !!\n");
	else
		for (i = 0 ; i < V.numElem; i++)
			printf("[ %d ] = %d\n", i, V.V[i]);

	printf("------------------------------\n");

}

/* *********************************************** */
/* *********************************************** */
void selectionSort (tVetor *v) {
	int menor;
	for(int i=0; i<v->numElem-1; i++){
		menor = i;
		for(int j=i+1; j<v->numElem; j++){
			if(v->V[menor]>v->V[j])
				menor = j;
		}
		if(v->V[menor]==v->V[i]) continue;
		swapV(&v->V[menor], &v->V[i]);
	}
	return;
}

/* *********************************************** */
/* *********************************************** */
void insertSort (tVetor *v) {
	for(int i=0; v->numElem-1; i++){
		for(int j=i+1; j>0; j--){
			if(v->V[j-1]<v->V[j]){
				break;
			}
			swapV(&v->V[j-1],&v->V[j]);
		}
	}
	return;
}


/* *********************************************** */
/* *********************************************** */
void bubbleSort (tVetor *v) {
	int mudou = false;
	int contador=0;
	do{
		mudou = false;
		for(int i=0; i<v->numElem-1-contador; i++){
			if(v->V[i]>v->V[i+1]){
				swapV(&v->V[i],&v->V[i+1]);
				mudou = true;
			}
		}
		contador++;
	}while(mudou);
	return;
}

/* *********************************************** */
/* *********************************************** */

void swapV(int *a,int *b ){
	int aux = *a;
	*a = *b;
	*b = aux;
	return;
}
