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

void tst(tCity cidade){
    tCaminho *raiz = *atual = NULL;
    int numElementos = 0;
    //Primeiro Elemento
    tCaminho aux;
    aux.index = 0;
    aux.caminho[aux.index] = cidade;
    aux.vizitadas = 1;
    aux.dist = 0;
    //SOLUCAO
    tCaminho solucao;
    solucao.dis = %infinity;

    push(&atual, &numElementos, aux);
    raiz = atual;

    //Brute Force Start
    while(numElementos > 0){
        aux = pop(&raiz, &numElementos);
        if(aux.index < 99){
            //NAO ESTOROU O LIMITE
            if(aux.vizitadas == NCIDADES && aux.caminho[aux.index] == cidade){
            // EH SOLUCAO
                if(aux.dist < solucao.dist){
                    //MENOR SOLUCAO ATE O MOMENTO
                    solucao = aux;
                }
            }
            else{
            // NAO EH SOLUCAO
                tCity cidadeAux = aux.caminho[aux.index];
                for(int i = 0; i < cidadeAux.qtdVizinhos; i++){
                    tCaminho auxInsere;
                    auxInsere = aux;

                    auxInsere.index++; //INDEX
                    auxInsere.caminho[auxInsere.index] = *(cidadeAux.vizinhos[i]); //VETOR COM VIZINHO ADICIONADO
                    auxInsere.dist += (double)cidadeAux.dist[i]; //DISTANCIA ATULAIZADA
                    //Checar se ja passou pela cidade
                    int repetido = 0;
                    for(tCIty forAux : auxInsere.caminho){
                        if(forAux == cidadeAux) repetido = 1;
                    }
                    if(!repetido) auxInsere.vizitadas++;

                    push(&atual, &numElementos, auxInsere);       
                }
            }
        }
    }
    solucaoTST = solucao;
}