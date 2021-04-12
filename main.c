/*
*   Programa: PROBLEMA DO LABIRINTO
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "./Headers/includes.h"

int main(int argc, char const *argv[])
{
    /* code */
    TipoApontador labirinto;
    labirinto->labirinto = NULL;
    int escolhaMenu, escolhaSubMenu;
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
            break;

        case 2:
            limpaTela();
            if (labirinto->labirinto == NULL)
            {
                puts("Voce precisa entrar com um arquivo valido primeiro!");
                pausaPrograma();
                break;
            }
            movimenta_estudante(&labirinto);
            pausaPrograma();
            limpaTela();
            break;

        case 3:
            limpaTela();
            if (labirinto->labirinto == NULL)
            {
                puts("Voce precisa entrar com um arquivo valido primeiro!");
                pausaPrograma();
                break;
            }
            mostraLabirinto(&labirinto);
            pausaPrograma();
            limpaTela();
            break;

        case 0:
            limpaTela();
            puts("Obrigado por utilizar!");
            break;

        default:
            limpaTela();
            puts("Valor invalido! Poderia inserir outro?!");
            pausaPrograma();
            break;
        }

        puts(""); // quebra de linha entre uma execucao e outra

    } while (escolhaMenu != 0);

    return 0;
}