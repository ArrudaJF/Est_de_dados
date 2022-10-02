#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"
#include "caminho.h"

int main(){
	int N;
	float x, y, total = 0;
	Caminho* caminho;

	scanf("%d", &N);
	caminho = makeCaminho(N);

	for(int i = 0; i < N; i++){
		scanf("%f %f", &x, &y);
		Ponto* ponto = makePonto(x, y);
		giveToCaminho(caminho, ponto, i);
	}

	total = distTotal(caminho);
	printf("%.2f\n", total);
	free(caminho);
	caminho = NULL;
	return 0;
}
