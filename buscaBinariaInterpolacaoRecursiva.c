#include <stdio.h>


int buscaBinaria(float v[], int inicio, int fim, int k){
    int meio = (int)(( k-v[inicio]/(v[fim]-v[inicio]) )*(fim-inicio)+inicio);

	if(v[meio]==k){
	       	return 1;
	}
	if(inicio > fim){
	       	return 0;
	}else if (v[meio]>k){
	       	return buscaBinaria(v, inicio, meio-1, k);
	}else{
	       	return buscaBinaria(v, meio+1, fim, k);

	}
}


int main(){

    float v[] = {1,2,3,4,5};
    int k=6;
    printf("%d\n",buscaBinaria(v, 0, 4, k));
}




