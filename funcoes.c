#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "loadBancoDeDados.h"
#include "funcoes.h"

void criarMatriz(tCity cidades[], int matriz[NCIDADES][NCIDADES]){
    int achouVizinho;
    for(int i = 0; i < NCIDADES; i++){
        for(int j = 0; j < NCIDADES; j++){
            achouVizinho = 0;
            for(int z = 0; z < cidades[i].qtdVizinhos; z++){
                if(strcmp(cidades[j].name, (cidades[i].vizinhos[z])->name) == 0){
                    matriz[i][j] = cidades[i].dist[z];
                    achouVizinho = 1;
                    break;
                }
            }
            if(!achouVizinho)
                matriz[i][j] = -1;
        }
    }
}
