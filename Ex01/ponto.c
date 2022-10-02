#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"
#include "caminho.h"

struct ponto {
	float x, y;
};

Ponto* makePonto(float x, float y){
	Ponto* point = malloc(sizeof(Ponto*));
	point->x = x;
	point->y = y;

	//printf("%.2f %.2f\n", ponto->x, ponto->y);
	return point;
}

float getPonto(Ponto* pont, char c){
	float a;
	if(c == 'x'){
		a = pont->x;
		return a;
	} else if(c == 'y'){
		a = pont->y;
		return a;
	} else {
		return 0.0;
	};
}
