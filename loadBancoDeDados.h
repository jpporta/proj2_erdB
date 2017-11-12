#define NCIDADES 42

typedef struct city{
    char name[20];
    int index;
    int qtdVizinhos;
    struct city *vizinhos[10];
    int dist[10];
} tCity;


void organizarVetor(tCity *c);
void recebeCidades(tCity *cidades);
int encontraCidade(char *name, tCity *cidades, int inicio, int final, int m);
void linkagemDasCidades(FILE *arq, tCity *cidades);
