struct caminho typedef{
    tCity caminho[100];
    int index;
    double dist;
    int vizitadas;
    struct caminho *prox;
    }
}

void criarMatriz(tCity cidades[], int matriz[NCIDADES][NCIDADES]);
void tst(tCity cidade);
