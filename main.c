/*
*   Programa: PROBLEMA DO LABIRINTO
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "./Headers/includes.h"

//gcc -o exec main.c ./Sources/labirinto.c ./Sources/auxiliares.c
//Como rodar o makefile no windows mingw32-make <enter>  exec <enter>

int main(int argc, char const *argv[])
{
    /* code */
    Labirinto labirinto;
    int linha = 10;
    int coluna = 10;
    int escolhaMenu;

    labirinto = inicializaLabirinto(linha,coluna);
    
    /*for (int i = 0; i < linha; i++)
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
    }*/

    textoInicial ();

    do{
        escolhaMenu = escolhaUsuario ();

        switch(escolhaMenu){
            case 1:
                puts("abrir e ler arquivo");
                break;

            case 2:
                puts("processar matriz");
                break;

            case 0:
                puts("Obrigado por utilizar!");
                system("pause");
                break;

            default:
                puts("Valor invalido! Poderia inserir outro?!");
                break;
        }

        puts("");

    }while(escolhaMenu != 0);    

    return 0;
}