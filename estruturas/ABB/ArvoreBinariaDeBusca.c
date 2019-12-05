#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ArvoreBinariaDeBusca.h"


// ***********************************************
// ******                                   ******
// ***********************************************

void limpaArvore( tNo** r) {
	if(r == NULL)
		return;
	if((*r)->esq!= NULL)
		limpaArvore(&((*r)->esq));
	if((*r)->dir!=NULL)
		limpaArvore(&((*r)->dir));
	// printf("removendo o nó o %d\n",(*r)->data);
	free(*r);
	*r = NULL;
	return;
}

// ***********************************************
// ******                                   ******
// ***********************************************

void percursoPreOrd( tNo* r) {

	if (r != NULL) {
		printf("%d ", r->data);
		percursoPreOrd( r->esq);
		percursoPreOrd( r->dir);
		}
	else 
		printf(".");	

}

// ***********************************************
// ******                                   ******
// ***********************************************

void percursoInOrd( tNo* r) {

	if (r != NULL) {
		percursoInOrd( r->esq);
		printf("%d ", r->data);
		percursoInOrd( r->dir);
		}
	else 
		printf(".");	

}

// ***********************************************
// ******                                   ******
// ***********************************************

void percursoPosOrd( tNo* r) {

	if (r != NULL) {
		percursoPosOrd( r->esq);
		percursoPosOrd( r->dir);
		printf("%d ", r->data);
		}
	else 
		printf(".");	
}

// ***********************************************
// ******                                   ******
// ***********************************************

tNo* criaNo(int n) {

	tNo* novoNo = (tNo*) malloc(sizeof(tNo));
	
	if ( novoNo != NULL) {
		novoNo->data 	= n;
		novoNo->esq 	= NULL;
		novoNo->dir		= NULL;
		}
		
	return novoNo;
}

// ***********************************************
// ******                                   ******
// ***********************************************

bool insereNo(tNo** r, int n) {
	if(r == NULL) return false;
	if(*r==NULL){
		tNo *no = criaNo(n);
		*r = no; 
		return true;
	} else if(n > (*r)->data){
		return insereNo(&(*r)->dir, n);
	} else {
		return insereNo(&(*r)->esq, n);
	}
}

// ***********************************************
// ******                                   ******
// ***********************************************

tNo* procuraNo( tNo* r, int n) {
	if(r == NULL){
		return NULL;
	}
	if( r->data == n ){
		return r;
	}else if( r->data > n){
		tNo* left = procuraNo( r->esq, n);
		if(left != NULL){
			return left;
		}
	}else{
		tNo* right = procuraNo( r->dir, n);
		if(right != NULL){
			return right;
		}
	}

	return NULL;

}

// ***********************************************
// ******                                   ******
// ***********************************************

bool removeNo( tNo** r, int n) {
	if(*r == NULL) return false;
	if((*r)->data == n){
		/** O nó não possui filhos*/
		if((*r)->esq == NULL && (*r)->dir == NULL ){
			*r = NULL;
			return true;
		} else if((*r)->esq != NULL && (*r)->dir!=NULL ){

			tNo** aux = &((*r)->dir);
			while((*aux)->esq !=NULL){
				aux = &((*aux)->esq);
			}
			printf("O menor filho do %d é o %d\n", n, (*aux)->data);
			/** Troca o valor do nó com o menor nó da sub arvore a direita*/
			int valor = (*aux)->data;
			(*aux)->data = (*r)->data;
			(*r)->data = valor;
			/**Remove o mesmo nó só que em uma posição diferente
			 * e o mesmo não possui dois filhos agora
			*/
			return removeNo((aux), (*aux)->data);
		} else{
			if((*r)->esq != NULL){
				tNo * aux = (*r)->esq; 
				free(*r);
				*r = aux->esq;
			} else {
				tNo * aux = (*r)->dir; 
				free(*r);
				*r = aux->dir; 
			}
		}
	} else if((*r)->data < n){
		return removeNo(&(*r)->dir, n);
	} else	{
		return removeNo(&(*r)->esq, n);
	}
	
	return false;

}
