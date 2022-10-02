#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "jogo.h"
#include "catalogo.h"

struct catalogo {
	Jogo** listaJogos;
	int numJogos, numBuscas;
	int* listaBusca;
};


Catalogo* makeCatalogo(){
	Catalogo* catalogo = (Catalogo *) malloc(sizeof(Catalogo*));
	catalogo->listaJogos = (Jogo **) malloc(sizeof(Jogo**));
	catalogo->listaBusca = NULL;
	catalogo->numJogos = 0;
	catalogo->numBuscas = 0;

	return catalogo;
}

void incluiJogo(Catalogo* catalogo, Jogo* jogo){
	
	catalogo->numJogos += 1;
	int i = catalogo->numJogos;
	catalogo->listaJogos = (Jogo **) realloc(catalogo->listaJogos, i*sizeof(Jogo*));

	catalogo->listaJogos[i - 1] = jogo;
	//printJogo(catalogo->listaJogos[0]);
	return;
}


void buscaA(Catalogo* catalogo, int buscaAno){
	int qtosAchou = 0;
	for (int j = 0; j < catalogo->numJogos; j++){
		int a = getAno(catalogo->listaJogos[j]);

		if (a == buscaAno){
			putListaBusca(catalogo, j);
			//printf("%d\n", j);
			qtosAchou++;
		}
	}
	//printf("%d\n", qtosAchou);
	if (qtosAchou == 0){
		putListaBusca(catalogo, -1);
	}
	return;
}

void buscaP(Catalogo* catalogo, char* buscaProd){
	int qtosAchou = 0;
	for (int j = 0; j < catalogo->numJogos; j++){
		if (checkProd(catalogo->listaJogos[j], buscaProd) == 0){
			putListaBusca(catalogo, j);
			qtosAchou++;	
		}
	}

	if(qtosAchou == 0){
		putListaBusca(catalogo, -1);
	}
	free(buscaProd);
	return;
}

void putListaBusca(Catalogo* catalogo, int j){
	
	catalogo->numBuscas += 1;
	int i = catalogo->numBuscas;
	catalogo->listaBusca = (int *) realloc(catalogo->listaBusca, i*sizeof(int));

	catalogo->listaBusca[i-1] = j;
	return;
}

void printSaida(Catalogo* catalogo){

	int i = catalogo->numBuscas;

	for(int j = 0; j < i; j++){
		
		if (catalogo->listaBusca[j] == -1){
			printf("Nada encontrado\n");
		} else {
			int n = catalogo->listaBusca[j];
			printJogo(catalogo->listaJogos[n]);
		}
	}

	return;
}
void liberaCatalogo(Catalogo* catalogo){
	
	int j = catalogo->numJogos;
	for(int i = 0; i < j; i++){
		liberaJogo(catalogo->listaJogos[i]);
	}

	free(catalogo->listaBusca);
	free(catalogo);

	return;
}
