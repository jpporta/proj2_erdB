#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loadBancoDeDados.h"
#include "funcoes.h"

int menu();
void clrscr();

int main(){
    tCity cidades[NCIDADES];
    int opcao;
    char cidadeInicial[20];
    int caminho[100];

    // recepção de todas as cidades pelo arquivo
    // também é feita a organização e linkagem delas no vetor de cidades
    recebeCidades(cidades);

    opcao = menu();
    switch (opcao) {
        case 1:
            puts("Cidade Inicial?");
            scanf("%s", cidadeInicial);
            todasCidadesDestino(cidades, encontraCidade(cidadeInicial, cidades, 0, NCIDADES-1, 0),
                encontraCidade(cidadeInicial, cidades, 0, NCIDADES-1, 0), caminho);
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
