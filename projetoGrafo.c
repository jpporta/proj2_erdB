#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loadBancoDeDados.h"
#include "funcoes.h"

int menu();
void clrscr();
void salvaResolucao();

int main() {
  tCity cidades[NCIDADES];
  int opcao, i;
  char cidadeInicial[20];
  int matrizCusto[NCIDADES][NCIDADES];

  // recepção de todas as cidades pelo arquivo
  // também é feita a organização e linkagem delas no vetor de cidades
  recebeCidades(cidades);
  criarMatriz(cidades, matrizCusto);
  opcao = menu();
  switch (opcao) {
  case 1:
    // puts("Cidade Inicial?");
    // scanf("%s", cidadeInicial);
    // for (i = 0; i < NCIDADES; i++) {
    //   if (strcmp(cidades[i].name, "Seatle") == 0)
    //     break;
    // }
    // if (i == NCIDADES)
    //   puts("Cidade não encontrada");

    tst(cidades[37]);
    break;
  }
  salvaResolucao();
  return 0;
}
int menu() {
  // int op;
  // puts("Bem vindo ao planejador de Rotas 3001");
  // printf("Opções:\n");
  // printf("\t1- Escolher uma cidade ir a todas as outras cidades e voltar para
  // cidade inicial\n");
  // printf("\t\n");
  // printf("\t\n");
  // printf("\t\n");
  // scanf("%i", &op);
  clrscr();
  return 1;
}
void salvaResolucao(){
    FILE *arq;
    arq = fopen("salvaessapoha.txt", "w");
    fprintf(arq, "%.0lf\n", solucaoTST.dist);
    for(int i = 0; i <= solucaoTST.index; i++){
        fprintf(arq, "%s\n", solucaoTST.caminho[i].name);
    }
    fclose(arq);
}
void clrscr() { system("@cls||clear"); }
