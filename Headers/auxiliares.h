/*
*   Programa: PROBLEMA DO LABIRINTO
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

// ================ header de funcoes auxiliares ================

#ifndef AUXILIARES_H
#define AUXILIARES_H

#include "includes.h"

// ================ declaracao de funcoes ================

void linha ();
void textoInicial ();
int escolhaUsuario ();
Labirinto leituraArquivo(int *qtLinhas, int *qtColunas, int *qtChaves);
void limpaTela();

#endif