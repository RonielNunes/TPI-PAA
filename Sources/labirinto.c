/*
*   Programa: PROBLEMA DO LABIRINTO
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "../Headers/includes.h"


Labirinto inicializaLabirinto(int linha, int coluna){
    Labirinto labirintoExterno;
    
    labirintoExterno = (int**)calloc((linha+1),sizeof(int*));
    for (int i = 0; i < linha; i++)
    {
        labirintoExterno[i] = (int*)calloc((coluna+1),sizeof(int));
    }
    
    return labirintoExterno;
}

void mostraLabirinto(int linha, int coluna, Labirinto labirinto){
    for (int i = 0; i < linha; i++){
        printf("\n");
        for (int j = 0; j < coluna; j++){
            printf("%d ",labirinto[i][j]);
        }
    }
    printf("\n");
}

void getPosicaoInicialEstudante(int *x, int *y, int linha, int coluna, Labirinto labirinto){
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            if(labirinto[i][j] == 0){
                (*x) = i;
                (*y) = j;
            }   
        }
    }
}

