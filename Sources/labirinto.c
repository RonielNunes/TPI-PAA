/*
*   Programa: PROBLEMA DO LABIRINTO
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "../Headers/includes.h"

void inicializaLabirinto(TipoApontador *apLabirinto, int linha, int coluna, int chave)
{

    (*apLabirinto)->qtLinhas = linha;
    (*apLabirinto)->qtColunas = coluna;
    (*apLabirinto)->qtChaves = chave;

    (*apLabirinto)->labirinto = (int **)calloc(((*apLabirinto)->qtLinhas + 1), sizeof(int *));
    for (int i = 0; i < (*apLabirinto)->qtLinhas; i++)
    {
        (*apLabirinto)->labirinto[i] = (int *)calloc(((*apLabirinto)->qtColunas + 1), sizeof(int));
    }

    return;
}

void mostraLabirinto(TipoApontador *apLabirinto)
{
    for (int i = 0; i < (*apLabirinto)->qtLinhas; i++)
    {
        printf("\n");
        for (int j = 0; j < (*apLabirinto)->qtColunas; j++)
        {
            printf("%d ", (*apLabirinto)->labirinto[i][j]);
        }
    }
    printf("\n");
}

// retorna 1 se encontrar posicao, 0 caso contrario
int getPosicaoInicialEstudante(int *x, int *y, TipoApontador *apLabirinto)
{
    for (int i = 0; i < (*apLabirinto)->qtLinhas; i++)
    {
        for (int j = 0; j < (*apLabirinto)->qtColunas; j++)
        {
            if ((*apLabirinto)->labirinto[i][j] == 0)
            {
                (*x) = i;
                (*y) = j;
                return 1;
            }
        }
    }

    printf("i: %d, j: %d", *x, *y);

    return 0;
}
