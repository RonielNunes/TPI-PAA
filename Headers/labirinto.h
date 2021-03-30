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

//Estrutura??

typedef int ** Labirinto;

// ================ declaracao de funcoes ================

Labirinto inicializaLabirinto(int linha, int coluna);
void mostraLabirinto(int linha, int coluna, Labirinto labirinto);
void getPosicaoInicialEstudante(int *x, int *y, int linha, int coluna, Labirinto labirinto);

#endif