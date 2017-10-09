#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NCIDADES 42

typedef struct city{
    char name[20];
    int qtdVizinhos;
    struct city *vizinhos[10];
    int dist[10];
} tCity;

void organizarVetor(tCity *c);
void recebeCidades(tCity *cidades);
void criaMatriz(int (*distancia)[NCIDADES], tCity *cidades);
int encontraCidade(char *name, tCity *cidades, int inicio, int final, int m);

int main(){
    tCity cidades[NCIDADES];
    int distancias[NCIDADES][NCIDADES];

    recebeCidades(cidades);
    criaMatriz(distancias, cidades);
    // for(int i = 0; i < NCIDADES; i++){
    //     printf("%s %u\n", cidades[i].name, i);
    // }
    return 0;
}
void criaMatriz(int (*distancia)[NCIDADES], tCity *cidades){
    for(int i = 0; i < NCIDADES; i++){
        for(int j = 0; j < cidades[i].qtdVizinhos; j++){
            distancia[i][encontraCidade(cidades[i].vizinhos[j].name, cidades,0, NCIDADES-1, 0)] = cidades[i].vizinhos[j].dist;
        }
    }
}
int encontraCidade(char *name, tCity *cidades, int inicio, int final, int m){
    if(final >= 1){
        int meio = inicio + (final - inicio)/2;
        if(m == meio){
             printf("%s\n", name);
             return -1;
         }
        if(strcmp(cidades[meio].name, name) == 0) return meio;
        if(strcmp(cidades[meio].name, name) < 0) return encontraCidade(name, cidades, inicio, (meio - 1), meio);
        if(strcmp(cidades[meio].name, name) > 0) return encontraCidade(name, cidades, (meio + 1), final, meio);
    }
    return -1;
}
void recebeCidades(tCity *cidades){
    FILE *fCidades;
    int cityAtual;
    int qtdCity, distancia;
    char palavra[30], c;
    int counter;

    fCidades = fopen("cidades.txt", "r");
    if(fCidades == NULL) puts("ERROR");
    else{
        cityAtual = 0;
        while(!feof(fCidades)){
            counter = 0;
            c = fgetc(fCidades);
            if(c != '!'){
                if(c == '.') break;
                if(c == '\n')
                    c = fgetc(fCidades);
                palavra[counter] = c;
                counter++;
                while((c = fgetc(fCidades)) != '\n'){
                    if(c == '\n') break;
                    palavra[counter] = c;
                    counter++;
                }
                palavra[counter] = '\0';
                strcpy(cidades[cityAtual].name, palavra);
                fscanf(fCidades, "%i", &qtdCity);
                cidades[cityAtual].qtdVizinhos = qtdCity;
                fgetc(fCidades);
                for(int i = 0; i < qtdCity; i++){
                    counter = 0;
                    while((c = fgetc(fCidades)) != '\n'){
                        if(c == '\n') break;
                        palavra[counter] = c;
                        counter++;
                    }
                    palavra[counter] = '\0';
                    strcpy(cidades[cityAtual].vizinhos[i].name, palavra);
                }
                for(int i = 0; i < qtdCity; i++){
                    fscanf(fCidades, "%i", &distancia);
                    cidades[cityAtual].vizinhos[i].dist = distancia;
                }
                fgetc(fCidades);
            }
            else{
                cityAtual++;
            }
        }
        fclose(fCidades);
    }
        organizarVetor(cidades);
}
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
