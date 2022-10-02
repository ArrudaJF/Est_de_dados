#include "ponto.h"

typedef struct caminho Caminho;

Caminho* makeCaminho(int N);
void giveToCaminho(Caminho* caminho, Ponto* ponto, int ordem);
float distTotal(Caminho* caminho);
void free_caminho(Caminho *C);
