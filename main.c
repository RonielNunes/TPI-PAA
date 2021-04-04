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
    TipoApontador labirinto;
    labirinto->labirinto = NULL;
    int escolhaMenu;
    int x, y;

    textcolor(15, 0); /*primeiro cor letra, segundo cor fundo */

    do
    {
        limpaTela();
        escolhaMenu = escolhaUsuario();

        switch (escolhaMenu)
        {
        case 1:
            limpaTela();
            leituraArquivo(&labirinto);
            //getPosicaoInicialEstudante(&x,&y,&labirinto);
            break;

        case 2:
            limpaTela();
            if (labirinto->labirinto == NULL)
            {
                puts("Voce precisa entrar com um arquivo valido primeiro!");
                system("pause");
                break;
            }
            movimenta_estudante(&labirinto);
            system("pause");
            break;

        case 3:

            mostraLabirinto(&labirinto); //print da matriz para verificar leitura do arquivo - retirar antes de entregar

            // printf("linhas: %d\ncolunas: %d\nchaves: %d\n", labirinto->qtLinhas, labirinto->qtColunas, labirinto->qtChaves);

            // printf("%d", getPosicaoInicialEstudante(&x, &y, &labirinto));

            // printf("%d", posValida(&labirinto, 9, 5));

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
            system("pause");
            break;
        }

        puts(""); // quebra de linha entre uma execucao e outra

    } while (escolhaMenu != 0);

    return 0;
}