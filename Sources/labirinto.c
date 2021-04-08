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
            if ((*apLabirinto)->labirinto[i][j] == 4)
            {
                textcolor(0, 2); /*primeiro cor letra, segundo cor fundo */
                printf("* ");
                textcolor(15, 0); /*primeiro cor letra, segundo cor fundo */
            }
            else if ((*apLabirinto)->labirinto[i][j] == 0)
            {
                textcolor(0, 15); /*primeiro cor letra, segundo cor fundo */
                printf("  ");
                textcolor(15, 0); /*primeiro cor letra, segundo cor fundo */
            }
            else if ((*apLabirinto)->labirinto[i][j] == 2)
            {
                textcolor(0, 1); /*primeiro cor letra, segundo cor fundo */
                printf("  ");
                textcolor(15, 0); /*primeiro cor letra, segundo cor fundo */
            }
            else if ((*apLabirinto)->labirinto[i][j] == 3)
            {
                textcolor(0, 4); /*primeiro cor letra, segundo cor fundo */
                printf("  ");
                textcolor(15, 0); /*primeiro cor letra, segundo cor fundo */
            }
            else
            {
                textcolor(0, 10); /*primeiro cor letra, segundo cor fundo */
                printf("  ");
                textcolor(15, 0); /*primeiro cor letra, segundo cor fundo */
            }
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
    int x0, y0, solucao, qtMovimento = 0, qtTentativas = 0, posFinal, AuxNivelRecursao = 0, nivelRecursao;

    // possiveis movimentos - cima, direita, esquerda, baixo
    int movimentoLinha[QT_MOV] = {-1, 0, 0, 1};
    int movimentoColuna[QT_MOV] = {0, 1, -1, 0};

    if (!getPosicaoInicialEstudante(&x0, &y0, &(*apLabirinto)))
    {
        puts("O estudante nao esta no labirinto!");
        return;
    }
    solucao = movimenta_estudante_interno(&(*apLabirinto), x0, y0, movimentoLinha, movimentoColuna, &qtMovimento, &qtTentativas,&AuxNivelRecursao,&nivelRecursao, &posFinal);

    if (!solucao)
    {
        printf("O estudante se movimentou %d vezes e percebeu que o labirinto nao tem saida.\n", qtMovimento);

        if (ANALISE)
            printf("Quantidade de chamadas recursivas: %d.\nNivel maximo: %d\n", qtTentativas, nivelRecursao);
    }
    else
    {
        printf("O estudante se movimentou %d vezes e chegou na coluna %d da primeira linha\n", qtMovimento, posFinal);

        if (ANALISE)
            printf("Quantidade de chamadas recursivas: %d.\nNivel maximo: %d\n", qtTentativas,nivelRecursao);
    }
    return;
}

int movimenta_estudante_interno(TipoApontador *apLabirinto, int x0, int y0, int *movimentoLinha, int *movimentoColuna, int *qtMovimento, int *qtTentativas, int *AuxNivelRecursao,int *nivelRecursao, int *posFinal)
{
    //sleep(2);
    int registroTentativa = 0; 
    int aux;

    (*qtTentativas)++;

    if (verificaPosicao(&(*apLabirinto), x0, y0))
    {
        (*qtMovimento)++;
        (*AuxNivelRecursao)++;
        if ((*apLabirinto)->labirinto[x0][y0] == 3)
        {
            (*apLabirinto)->labirinto[x0][y0] = 3;
        }
        else if ((*apLabirinto)->labirinto[x0][y0] == 0)
        {
            (*apLabirinto)->labirinto[x0][y0] = 0;
        }
        else
        {
            (*apLabirinto)->labirinto[x0][y0] = 4;
        }

        printf("Linha: %d Coluna: %d\n", x0, y0);
        if (x0 == 0)
        {
            (*nivelRecursao) = (*AuxNivelRecursao);
            *posFinal = y0;
            registroTentativa = 1;

            return registroTentativa;
        }
        else
            {
            for (int i = 0; i < QT_MOV; i++){
                if (!registroTentativa)
                {
                    registroTentativa = movimenta_estudante_interno(&(*apLabirinto),
                                                                    x0 + movimentoLinha[i],
                                                                    y0 + movimentoColuna[i],
                                                                    movimentoLinha,
                                                                    movimentoColuna,
                                                                    qtMovimento,
                                                                    qtTentativas,
                                                                    AuxNivelRecursao,
                                                                    nivelRecursao,
                                                                    posFinal);

                }
            }
            if ((*apLabirinto)->labirinto[x0][y0] == 3)
            {
                (*apLabirinto)->qtChaves++;

            }
        }
    (*AuxNivelRecursao)--;
    }
    
    return registroTentativa;
}

// retorna 1 se a movimentacao e possivel e 0, caso contrario
int verificaPosicao(TipoApontador *apLabirinto, int linha, int coluna)
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
            (*apLabirinto)->qtChaves--;
            return 1;
        }
    }

    return 0;
}