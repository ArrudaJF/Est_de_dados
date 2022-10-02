#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"
#include "catalogo.h"

struct jogo{
        char* nome;
	char* produtora;
        int ano;
}; 

Jogo* armazenaJogo(char* n, char* prod, int a){
        Jogo* jogo = (Jogo *) malloc(sizeof(Jogo*));
	//jogo->nome = (char *) malloc(sizeof(char*));
        //jogo->produtora = (char *) malloc(sizeof(char*));
        
	jogo->nome = n;
        jogo->produtora = prod;
        jogo->ano = a;

        return jogo;
}

char* lerNome(){
	char* string = (char *) malloc(sizeof(char));
	char n;
	int i = 0;

	while(1){
	 scanf("%c",&n);

	 if(n == '\r'){
		scanf("%c", &n);
        	break;
	 } else if(n == '\n'){
	 	break;
	 }

	 string[i] = n;
    	 i++;
	 string = (char *) realloc(string, (i+1)*sizeof(char));
	}

	string[i] = '\0';
	return string;
}
int lerAno(){
	int y;
	char ch;
	scanf("%d", &y);
	scanf("%c", &ch);

	if (ch == '\r'){
		scanf("%c", &ch);
	}
	return y;
}

int isOver(char* name){
	if (name[0] == 'F' && name[1] == '\n'){
		return 0;
	} else {
		return 1;
	}
}

void printJogo(Jogo* jogo){
	int i = 0;
	while(1){
		if(jogo->nome[i] == '\0'){
			break;
		}
		printf("%c", jogo->nome[i]);

		i++;
	}
	printf("\n");
	return;
}


int getAno(Jogo* jogo){
	return jogo->ano;
}

int checkProd(Jogo* jogo, char* busca){
	return strcmp(jogo->produtora, busca);

}

void liberaJogo(Jogo* jogo){
	
	free(jogo->nome);
	free(jogo->produtora);
	free(jogo);
	return;
}
