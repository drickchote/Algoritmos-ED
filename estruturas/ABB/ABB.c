#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "ArvoreBinariaDeBusca.h"


// ***********************************************
// ***********************************************
// ***********************************************

int main() {
	
#define MAX 15
	
tNo*  root  = NULL;
bool  OK    = true;
int   i     = 0, 
      n,
      V[MAX] = { 50, 10, 70, 2, 1, 13, 15, 65, 69, 77, 11, 3, 80, 76, 64}; 

    for ( i = 0 ; i < MAX ; i++ ) 
    	if (!insereNo(&root, V[i])) {
        
        printf("--> Arvore cheia\n");
        exit(-1);
        }
      else
        printf("[%d] ", V[i]);
    	
		
   	printf("\n====== PRE ======\n");
    percursoPreOrd(root);
   	printf("\n====== IN ======\n");
    percursoInOrd(root);
   	printf("\n====== POS ======\n");
    percursoPosOrd(root);
    
   	printf("\n");
   	printf("\n====== REMOVING.... ======\n");
   	i	= 0; 
   	OK 	= true;
  	   	
      n = 50;
    
    	printf("removendo %d", n);
    	
    	if (removeNo(&root, n) )
   			printf(" ===> OK\n");
      else
        printf("\n");
    n = 70;
    removeNo(&root, n);
    printf("\n====== PRE ======\n");
    percursoPreOrd(root);
    printf("\n=================\n\n\n");

    printf("\n====== IN ======\n");
    percursoInOrd(root);
    printf("\n=================\n\n\n");

    printf("\n====== POS ======\n");
    percursoPosOrd(root);
    printf("\n=================\n\n\n");

    printf("Limpando\n\n");
    limpaArvore(&root);

    printf("\n====== PRE ======\n");
    percursoPreOrd(root);
    printf("\n=================\n\n\n");

    printf("\n====== IN ======\n");
    percursoInOrd(root);
    printf("\n=================\n\n\n");

    printf("\n====== POS ======\n");
    percursoPosOrd(root);
    printf("\n=================\n\n\n");

}

    

