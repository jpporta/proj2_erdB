typedef struct caminho{
    int cidades[100];
    int custo;
    int index;
    int visitadas;
} tCaminho;

typedef struct pilha{
    tCaminho atual;
    struct pilha *prox;
}tPilha;

void todasCidadesDestino(tCity *cidades, int inicial, int destino, int *caminho);
tCaminho pop(tPilha **raiz);
void push (tCaminho item, tPilha *raiz);
