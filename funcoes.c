#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loadBancoDeDados.h"
#include "funcoes.h"

void criarMatriz(tCity cidades[], int matriz[NCIDADES][NCIDADES]) {
  int achouVizinho;
  for (int i = 0; i < NCIDADES; i++) {
    for (int j = 0; j < NCIDADES; j++) {
      achouVizinho = 0;
      for (int z = 0; z < cidades[i].qtdVizinhos; z++) {
        if (strcmp(cidades[j].name, (cidades[i].vizinhos[z])->name) == 0) {
          matriz[i][j] = cidades[i].dist[z];
          achouVizinho = 1;
          break;
        }
      }
      if (!achouVizinho)
        matriz[i][j] = -1;
    }
  }
}

void pushLast(tCaminho **atual, int *numElementos, tCaminho aux) {
  if (*atual == NULL) {
    *atual = (tCaminho *)malloc(sizeof(tCaminho));
    **atual = aux;
    (*atual)->prox = NULL;
    *numElementos += 1;
  } else {
    if ((*atual)->prox == NULL) {
      (*atual)->prox = (tCaminho *)malloc(sizeof(tCaminho));
      *((*atual)->prox) = aux;
      *numElementos += 1;
    } else
      pushLast(&((*atual)->prox), numElementos, aux);
  }
}

void pushFirst(tCaminho **atual, int *numElementos, tCaminho aux) {
  tCaminho *pedaco = *atual;
  *atual = (tCaminho*)malloc(sizeof(tCaminho));
  **atual = aux;
  (*atual)->prox = pedaco;
  *numElementos += 1;
}

tCaminho pop(tCaminho **raiz, int *num) {
  tCaminho *freeAdr = *raiz;
  tCaminho ret = **raiz;
  *raiz = (*raiz)->prox;
  free(freeAdr);
  return ret;
}
void tst(tCity cidade) {
  tCaminho *raiz = NULL;
  int numElementos = 0;
  // Primeiro Elemento
  tCaminho aux;
  aux.index = 0;
  aux.caminho[aux.index] = cidade;
  aux.vizitadas = 1;
  aux.dist = 0;
  // SOLUCAO
  tCaminho solucao;
  solucao.dist = 20000;
  pushFirst(&raiz, &numElementos, aux);

  // Brute Force Start
  int count = 0;
  while (numElementos > 0) {

    aux = pop(&raiz, &numElementos);
    printf("%d %s \t\t\t%d %.0lf\n", aux.index, aux.caminho[aux.index].name,
          aux.vizitadas, aux.dist);
    if (aux.index < 50 && aux.dist < solucao.dist && aux.index <= aux.vizitadas + 2) {
      // NAO ESTOROU O LIMITE
      if ((aux.vizitadas == NCIDADES) &&
          ((aux.caminho[aux.index].index) == cidade.index)) {
        // EH SOLUCAO
        if (aux.dist < solucao.dist) {
          // MENOR SOLUCAO ATE O MOMENTO
          solucao = aux;
        }
      } else {
        // NAO EH SOLUCAO
        tCity cidadeAux = aux.caminho[aux.index];

        for (int i = 0; i < cidadeAux.qtdVizinhos; i++) {
          tCaminho auxInsere;
          auxInsere = aux;

          auxInsere.index++; // INDEX
          auxInsere.caminho[auxInsere.index] =
              *(cidadeAux.vizinhos[i]); // VETOR COM VIZINHO ADICIONADO
          auxInsere.dist += (double)cidadeAux.dist[i]; // DISTANCIA ATULAIZADA
          auxInsere.prox = NULL;


          // Optimizações
          int repetido = 0;
          int replicate = 1;
          int indexUltimo = auxInsere.index;
          // Verifica se foi voltou e foi de novo
          if(auxInsere.index >= 3){
              if(auxInsere.caminho[indexUltimo].index == auxInsere.caminho[indexUltimo-2].index &&
                  auxInsere.caminho[indexUltimo-1].index == auxInsere.caminho[indexUltimo-3].index)
                      replicate = 0;
            }
            // verifica se ha repetido
          for (int j = 0; j < auxInsere.index - 1 && replicate == 1; j++) {
                if (auxInsere.caminho[j].index ==
                    auxInsere.caminho[auxInsere.index].index) {
                  repetido = 1;
                  break;
                }
            }

          if (!repetido)
            auxInsere.vizitadas = aux.vizitadas + 1;
          else auxInsere.vizitadas = aux.vizitadas;

          if(replicate)pushFirst(&raiz, &numElementos, auxInsere);
        }
      }
    }
  }
  printf("FIM dist = %lf\n", solucao.dist);
  solucaoTST = solucao;
}
