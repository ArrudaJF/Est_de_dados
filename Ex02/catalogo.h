typedef struct catalogo Catalogo;

Catalogo* makeCatalogo();
void incluiJogo(Catalogo* catalogo, Jogo* jogo);
void buscaA(Catalogo* catalogo, int buscaAno);
void buscaP(Catalogo* catalogo, char* buscaProd);
void liberaCatalogo(Catalogo* catalogo);
void putListaBusca(Catalogo* catalogo, int j);
void printSaida(Catalogo* catalogo);
