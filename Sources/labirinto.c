/*
*   Programa: PROBLEMA DO LABIRINTO
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "../Headers/labirinto.h"
#include <malloc.h>

Labirinto inicializaLabirinto(int linha, int coluna){
    int **labirintoExterno;
    labirintoExterno = (int**)calloc((linha+1),sizeof(int*));
    for (int i = 0; i < linha; i++)
    {
        labirintoExterno[i] = (int*)calloc((coluna+1),sizeof(int));
    }
    
    return labirintoExterno;
}