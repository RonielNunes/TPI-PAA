/*
*   Programa: PROBLEMA DO LABIRINTO
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

// ================ header das funcoes principais ================

#ifndef LABIRINTO_H
#define LABIRINTO_H

#include "includes.h"
#define QT_MOV 4
#define ANALISE 0 // 0 - modo normal, 1 - modo análise

typedef int **Labirinto;

typedef struct
{

    Labirinto labirinto;
    int qtLinhas, qtColunas, qtChaves;

} TipoLabirinto;

typedef TipoLabirinto *TipoApontador;

// ================ declaracao de funcoes ================

void inicializaLabirinto(TipoApontador *apLabirinto, int linha, int coluna, int chave);
void mostraLabirinto(TipoApontador *apLabirinto);
int getPosicaoInicialEstudante(int *x, int *y, TipoApontador *apLabirinto);
void movimenta_estudante(TipoApontador *apLabirinto);
int movimenta_estudante_interno(TipoApontador *apLabirinto, int x0, int y0, int *movimentoLinha, int *movimentoColuna, int *qtMovimento, int *qtTentativas, int *posFinal);
int verificaPosicao(TipoApontador *apLabirinto, int linha, int coluna);

#endif