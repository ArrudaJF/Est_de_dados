#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "caminho.h"
#include "ponto.h"

struct caminho {
	Ponto** lista;
	int N;
};

Caminho* makeCaminho(int N){
	Caminho* caminho = (Caminho *) malloc(sizeof(*caminho));
	Ponto** list = (Ponto **) malloc(N*sizeof(Ponto*));

	caminho->lista = list;
	caminho->N = N;

	return caminho;
}

void giveToCaminho(Caminho* caminho, Ponto* ponto, int ordem){
	caminho->lista[ordem] = ponto;
	return;
}

float distTotal(Caminho* caminho){
	float sum = 0.0;//, distX, distY;
	float xi = 0.0, yi = 0.0, xf = 0.0, yf = 0.0;
	for(int j = 1; j < caminho->N; j++){
		
		xi = getPonto(caminho->lista[j-1], 'x');
		yi = getPonto(caminho->lista[j-1], 'y');
		free(caminho->lista[j-1]);
		caminho-> lista[j-1]= NULL;

		xf = getPonto(caminho->lista[j], 'x');
		yf = getPonto(caminho->lista[j], 'y');
		
		xf = pow(xf - xi, 2);
		yf = pow(yf - yi, 2);
		sum = sum + sqrt(xf + yf);
	}
	free(caminho->lista[caminho->N -1]);
	free(caminho->lista);	

	return sum;
}

void free_caminho(Caminho *C){
	
	for(int i = 0; i < C->N; i++){
		free(C->lista[i]);
	}
	free(C->lista);	
	free(C);

	return;
}
