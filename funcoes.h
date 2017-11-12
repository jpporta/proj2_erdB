typedef struct caminho{
    tCity caminho[100];
    int index;
    double dist;
    int vizitadas;
    struct caminho *prox;
} tCaminho;

tCaminho solucaoTST;

void criarMatriz(tCity cidades[], int matriz[NCIDADES][NCIDADES]);
void tst(tCity cidade);
tCaminho pop(tCaminho **raiz, int *num);
void push(tCaminho **atual, int *numElementos, tCaminho aux);
