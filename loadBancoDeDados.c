#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loadBancoDeDados.h"

// encontra cidade encontra cidade atravez de busca binaria
// recebe: nome da cidade, array de cidades, inicio do vetor, fim do vetor, meio para destravar
int encontraCidade(char *name, tCity *cidades, int inicio, int final, int m){
    if(final >= 0){
        int meio = inicio + (final - inicio)/2;
        if(m == meio){
             return -1;
         }
        if(strcmp(cidades[meio].name, name) == 0) return meio;
        if(strcmp(cidades[meio].name, name) > 0) return encontraCidade(name, cidades, inicio, (meio - 1), meio);
        if(strcmp(cidades[meio].name, name) < 0) return encontraCidade(name, cidades, (meio + 1), final, meio);
    }
    return -1;
}

/*
recebeCidades trabalha com o arquivo
recebe todos elementos e os adiciona no vetor
*/
void recebeCidades(tCity *cidades){
    FILE *arq;
    int cityAtual;
    int qtdCity, distancia;
    char palavra[30], c;
    int counter;

    arq = fopen("cidades.txt", "r");
    if(arq == NULL) puts("ERROR");
    else{
        cityAtual = 0;
        while(!feof(arq)){
            counter = 0;
            c = fgetc(arq);
            if(c != '!'){
                if(c == '.') break;
                if(c == '\n')
                    c = fgetc(arq);
                palavra[counter] = c;
                counter++;
                while((c = fgetc(arq)) != '\n'){
                    if(c == '\n') break;
                    palavra[counter] = c;
                    counter++;
                }
                palavra[counter] = '\0';
                strcpy(cidades[cityAtual].name, palavra);
                fscanf(arq, "%i", &qtdCity);
                cidades[cityAtual].qtdVizinhos = qtdCity;
                fgetc(arq);
                for(int i = 0; i < qtdCity; i++){
                    counter = 0;
                    while((c = fgetc(arq)) != '\n'){
                        if(c == '\n') break;
                        palavra[counter] = c;
                        counter++;
                    }
                    palavra[counter] = '\0';
                }
                for(int i = 0; i < qtdCity; i++){
                    fscanf(arq, "%i", &distancia);
                    cidades[cityAtual].dist[i] = distancia;
                }
                fgetc(arq);
            }
            else{
                cityAtual++;
            }
        }
        organizarVetor(cidades);
        linkagemDasCidades(arq, cidades);
        fclose(arq);
    }
}
/*
Orgaiza o vetor deixa o vetor em ordem alfabetica para facilitar buscas
*/
void organizarVetor(tCity *c){
    tCity aux;
    for(int i = 0; i < NCIDADES - 1; i++){
        for( int j = 0; j < NCIDADES - 1 - i; j++){
            if(strcmp(c[j].name,c[j+1].name) > 0){
                aux = c[j+1];
                c[j+1] = c[j];
                c[j] = aux;
            }
        }
    }
}
/*
Likagem da cidades
é utilizada para likar os vizinhos com ponteiros
*/
void linkagemDasCidades(FILE *arq, tCity *cidades){
    int cityAtual, qtdCity, counter, distancia;
    char palavra[20], c;
    rewind(arq);
    cityAtual = 0;
    while(!feof(arq)){
        counter = 0;
        c = fgetc(arq);
        if(c != '!'){
            if(c == '.') break;
            if(c == '\n')
                c = fgetc(arq);
            palavra[counter] = c;
            counter++;
            while((c = fgetc(arq)) != '\n'){
                if(c == '\n') break;
                palavra[counter] = c;
                counter++;
            }
            palavra[counter] = '\0';
            cityAtual = encontraCidade(palavra, cidades, 0, NCIDADES-1, 0);
            fscanf(arq, "%i", &qtdCity);
            fgetc(arq);
            for(int i = 0; i < qtdCity; i++){
                counter = 0;
                while((c = fgetc(arq)) != '\n'){
                    if(c == '\n') break;
                    palavra[counter] = c;
                    counter++;
                }
                palavra[counter] = '\0';
                cidades[cityAtual].vizinhos[i] = &(cidades[encontraCidade(palavra, cidades, 0, NCIDADES-1, 0)]);
            }
            for(int i = 0; i < qtdCity; i++){
                fscanf(arq, "%i", &distancia);
            }
            fgetc(arq);
        }
    }
}
