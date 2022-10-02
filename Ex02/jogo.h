typedef struct jogo Jogo;

Jogo* armazenaJogo(char* n, char* prod, int a);
char* lerNome();
int lerAno();
int isOver(char* name);
void printJogo(Jogo* jogo);
void liberaJogo(Jogo* jogo);
int getAno(Jogo* jogo);
int checkProd(Jogo* jogo, char* busca);
