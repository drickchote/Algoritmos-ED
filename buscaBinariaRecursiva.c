int buscaBinaria(int v[], int inicio, int fim, int k){
	int meio = (inicio + fim)/2;

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







