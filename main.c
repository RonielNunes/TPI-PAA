/*
*   Programa: PROBLEMA DO LABIRINTO
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/
#include <stdlib.h>
#include <stdio.h>
#include "./Headers/labirinto.h"
//gcc -o exec main.c ./Headers/labirinto.h ./Sources/labirinto.c

int main(int argc, char const *argv[])
{
    /* code */
    Labirinto labirinto;
    int linha = 10;
    int coluna = 10;

    labirinto = inicializaLabirinto(linha,coluna);
    
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            labirinto[i][j] = 0;
        }
    }

    for (int i = 0; i < linha; i++)
    {
        printf("\n");
        for (int j = 0; j < coluna; j++)
        {
            printf("%d ",labirinto[i][j]);
        }
    }
    

    return 0;
}