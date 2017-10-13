#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loadBancoDeDados.h"
#include "funcoes.h"

tCaminho pop(tPilha **raiz){
    if((*raiz) -> prox == NULL){
        tPilha ret = **raiz;
        tPilha *aux = *raiz;
        *raiz == NULL;
        free(aux);
        return ret.atual;
    }
    return pop(&((*raiz)->prox));
}
void push (tCaminho item, tPilha *raiz){
    if(raiz->prox != NULL) push(item, raiz);
    else{
        raiz->prox = (tPilha *)malloc(sizeof(tPilha));
        raiz->atual = item;
    }
}
void todasCidadesDestino(tCity *cidades, int inicial, int destino, int *caminho){
    tCaminho menorCaminho;
    int count = 0;
    tPilha *pilha = NULL;
    tCaminho atual;
    menorCaminho.custo == 9999999;

    atual.cidades[0] = inicial;
    atual.custo = 0;
    atual.index = 0;
    atual.visitadas = 1;
    push(atual, pilha);

    while(pilha != NULL){
        atual = pop(&pilha);
        if(atual.cidades[atual.index] == inicial && atual.visitadas >= NCIDADES){
            if(menorCaminho.custo > atual.custo){
                menorCaminho.custo = atual.custo;
                for(int i = 0; i <- atual.index; i++)
                    menorCaminho.cidades[i] = atual.cidades[i];
            }
        }
        else{
            for(int i = 0; i < cidades[atual.cidades[atual.index]].qtdVizinhos; i++){
                tCaminho aux;
                int j;
                aux = atual;
                aux.index += 1;
                int city = encontraCidade((cidades[(atual.cidades[atual.index])].vizinhos[i])->name, cidades, 0, NCIDADES-1, 0);
                for(j = 0; j < aux.index - 1; j++){
                    if(aux.cidades[j] == city) break;
                }
                if(j < aux.index - 1) aux.visitadas += 1;
                aux.cidades[aux.index] = city;
                push(aux, pilha);
            }
        }
    }
}
