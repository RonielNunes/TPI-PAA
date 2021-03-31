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

    //printf("i: %d, j: %d", *x, *y);

    return 0;
}

void movimenta_estudante(TipoApontador *apLabirinto)
{
    // posicoes iniciais
    int x0, y0, solucao;

    // possiveis movimentos - cima, direita, esquerda, baixo
    int movimentoLinha[QT_MOV] = {-1, 0, 0, 1};
    int movimentoColuna[QT_MOV] = {0, 1, -1, 0};

    if (!getPosicaoInicialEstudante(&x0, &y0, &(*apLabirinto)))
    {
        puts("O estudante nao esta no labirinto!");
        return;
    }
    solucao = movimenta_estudante_interno(&(*apLabirinto), x0, y0, movimentoLinha, movimentoColuna);

    if (!solucao)
        printf("O estudante se movimentou Z vezes e percebeu que o labirinto não tem saida.");

    return;
}

int movimenta_estudante_interno(TipoApontador *apLabirinto, int x0, int y0, int *movimentoLinha, int *movimentoColuna)
{
    //sleep(1);
    int registroTentativa = 0;

    if (posValida(&(*apLabirinto), x0, y0))
    {
        (*apLabirinto)->labirinto[x0][y0] = 4;
        printf("Linha: %d Coluna: %d\n", x0, y0);
        if (x0 == 0)
        {
            registroTentativa = 1;
            printf("O estudante se movimentou Z vezes e chegou na coluna %d da primeira linha\n", y0);
        }

        for (int i = 0; i < QT_MOV; i++)
        {
            if (!registroTentativa)
            {
                registroTentativa = movimenta_estudante_interno(&(*apLabirinto),
                                                                x0 + movimentoLinha[i],
                                                                y0 + movimentoColuna[i],
                                                                movimentoLinha,
                                                                movimentoColuna);
            }
        }

        (*apLabirinto)->labirinto[x0][y0] = 1;

        // while (registroTentativa == 0 && contMovimentacoes < QT_MOV)
        // {
        //     registroTentativa = movimenta_estudante_interno(&(*apLabirinto),
        //                                                     x0 + movimentoLinha[contMovimentacoes],
        //                                                     y0 + movimentoColuna[contMovimentacoes],
        //                                                     movimentoLinha,
        //                                                     movimentoColuna);
        //     contMovimentacoes++;
        // }
    }

    return registroTentativa;
}

/*int resolveLabirintoR(Labirinto lab, int lin, int col, int linDest, int colDest)
{
    int achou = 0, k = 0;
    if (posValida(lab, lin, col))
    {
        lab->pos[lin][col] = 1;
        if (lin == linDest && col == colDest)
        {
            imprimeLabirinto(lab);
            achou = 1;
        }
        while (achou == 0 && k < NUM_MOV)
        {
            achou = resolveLabirintoR(lab, lin + desLin[k], col + desCol[k], linDest, colDest);
            k++;
        }
        lab->pos[lin][col] = 0;
    }
    return achou;
}*/

// retorna 1 se a movimentacao e possivel e 0, caso contrario
int posValida(TipoApontador *apLabirinto, int linha, int coluna)
{
    // verifica limites do labirinto
    if (linha >= 0 && linha < (*apLabirinto)->qtLinhas &&
        coluna >= 0 && coluna < (*apLabirinto)->qtColunas)
    {
        // verifica se e posicao vazia
        if ((*apLabirinto)->labirinto[linha][coluna] == 1 || (*apLabirinto)->labirinto[linha][coluna] == 0)
        {
            return 1;
        }
        // verifica se e porta e se possui chave
        else if ((*apLabirinto)->labirinto[linha][coluna] == 3 && (*apLabirinto)->qtChaves > 0)
        {
            return 1;
        }
    }
    return 0;
}