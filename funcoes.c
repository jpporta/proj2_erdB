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
//TSP
// https://www.youtube.com/watch?v=vNqE_LDTsa0
// 1° Comeca com a matriz conectada como temos
// 2° Row Minimazation, subtrai os elemntos da uma linha pelo menor valor delas
// 3° Columm Minimazation, subtrai os elemtos da coluna pelo menor valor delas
// 4° Repetir 2 e 4 até todas as colunas e linhas terem pelo menos um zero
// 5° Calcular a penalidade de cada zero, a penalidade de um zero é igual a soma
// do menor valor da sua coluna com o menor valor de sua linhas
// 6° Remover qualquer linha e coluna com um dos zeros de maior penalidade,
// e adicionar ao conjunto resposta o caminho removido.
// 7° Voltar ao passo 2 com a nova matriz, até a maior penalidade possivel de um
// zero ser igual a zero
// 8° Verificar se há uma possibilidade possivel para dada linha, remove-la, e
// adiciona-la ao conjunto resposta
// 9° Tentar repetir a partir de 2, até haver apenas uma linha e coluna, que será
// o ultimo caminho a ser cruzado
// 10°̣ Rearranjar os caminhos respostas para se conctarem
// FIM
