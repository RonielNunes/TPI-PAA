/*
*   Programa: PROBLEMA DO LABIRINTO
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "../Headers/includes.h"

void linha (){
    for(int i = 0; i < 40; i++)
        printf("=");
    puts("");
}

void textoInicial (){
    linha();
    puts("\tLABIRINTO SECRETO");
    linha();
}

int escolhaUsuario (){
    int escolha;

    puts("Escolha uma das opcoes abaixo:");
    linha(); puts("1 - Carregar novo arquivo de dados\n2 - Processar e Exibir resposta\n0 - Finalizar o Programa\n");
    linha(); printf("Sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}
