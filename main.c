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
    int escolhaMenu;

    do
    {
        limpaTela();
        escolhaMenu = escolhaUsuario();

        switch (escolhaMenu)
        {
        case 1:
            limpaTela();
            leituraArquivo(labirinto);
            break;

        case 2:
            limpaTela();
            puts("processar matriz");
            system("pause");
            break;

        case 0:
            limpaTela();
            puts("Obrigado por utilizar!");
            system("pause");
            break;

        default:
            limpaTela();
            puts("Valor invalido! Poderia inserir outro?!");
            break;
        }

        puts(""); // quebra de linha entre uma execucao e outra

    } while (escolhaMenu != 0);

    return 0;
}