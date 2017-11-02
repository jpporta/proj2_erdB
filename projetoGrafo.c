#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loadBancoDeDados.h"
#include "funcoes.h"

int menu();
void clrscr();

tCaminho solucaoTST;

int main(){
    tCity cidades[NCIDADES];
    int opcao;
    char cidadeInicial[20];
    int matrizCusto[NCIDADES][NCIDADES];

    // recepção de todas as cidades pelo arquivo
    // também é feita a organização e linkagem delas no vetor de cidades
    recebeCidades(cidades);
    criarMatriz(cidades, matrizCusto);
    for(int i = 0; i < NCIDADES; i++){
        for(int j = 0; j < NCIDADES; j++){
            printf("%i ", matrizCusto[i][j]);
        }
        printf("\n");
    }
    opcao = menu();
    switch (opcao) {
        case 1:
            puts("Cidade Inicial?");
            scanf("%s", cidadeInicial);

    }
}
int menu(){
    int op;
    puts("Bem vindo ao planejador de Rotas 3001");
    printf("Opções:\n");
    printf("\t1- Escolher uma cidade ir a todas as outras cidades e voltar para cidade inicial\n");
    printf("\t\n");
    printf("\t\n");
    printf("\t\n");
    scanf("%i", &op);
    clrscr();
    return op;
}

void clrscr(){
    system("@cls||clear");
}
