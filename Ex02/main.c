#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "jogo.h"
#include "catalogo.h"

int main(){
	char* nome;
	char* prod;
	char* buscaProd;
	int ano;
	Catalogo* catalogo;
	catalogo = makeCatalogo();
	
	while(1){
		nome = lerNome();
		if (strcmp(nome, "F\0") == 0){
			break;
		}
		prod = lerNome();
		ano = lerAno();
		Jogo* jogo = armazenaJogo(nome, prod, ano);
		incluiJogo(catalogo, jogo);	
	}

	while(1){
		nome = lerNome();

		if (strcmp(nome, "F\0") == 0){
			break;
		}
		if (strcmp(nome, "A\0") == 0){
			ano = lerAno();
			buscaA(catalogo, ano);
		} else if (strcmp(nome, "E\0") == 0){
			buscaProd = lerNome();
			buscaP(catalogo, buscaProd);
		}
	}
	printSaida(catalogo);
	liberaCatalogo(catalogo);

	return 0;
}

