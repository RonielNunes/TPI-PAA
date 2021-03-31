/*
*   Programa: PROBLEMA DO LABIRINTO
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "../Headers/includes.h"

void linha()
{
    for (int i = 0; i < 40; i++)
        printf("=");
    puts("");
}

void textoInicial()
{
    linha();
    puts("\tLABIRINTO SECRETO");
    linha();
}

int escolhaUsuario()
{
    int escolha;

    textoInicial();

    puts("Escolha uma das opcoes abaixo:");
    linha();
    puts("1 - Carregar novo arquivo de dados\n2 - Processar e Exibir resposta\n0 - Finalizar o Programa\n");
    linha();
    printf("Sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

void leituraArquivo(TipoApontador *apLabirinto)
{
    int i, j, linha, coluna, chave;

    char nomeArquivo[20], caminhoArquivo[20];

    FILE *arquivo;

    printf("Entre com o nome do arquivo: ");

    scanf("%s", nomeArquivo);

    sprintf(caminhoArquivo, "./arquivos/%s", nomeArquivo); // funcao que compoe uma string, armazena no 1º parametro o 2º concatenado com o 3º

    arquivo = fopen(caminhoArquivo, "r");

    if (arquivo == NULL)
    {
        puts("Erro de abertura!");
        system("pause");
        return;
    }

    fscanf(arquivo, "%d %d %d", &linha, &coluna, &chave);

    inicializaLabirinto(&(*apLabirinto), linha, coluna, chave);

    char stringLinha[(*apLabirinto)->qtColunas]; // variavel que armazenara cada linha a partir da 2ª linha do arquivo

    for (i = 0; i < ((*apLabirinto)->qtLinhas); i++)
    {
        fscanf(arquivo, "%s", &stringLinha);
        for (j = 0; j < ((*apLabirinto)->qtColunas); j++)
        {
            (*apLabirinto)->labirinto[i][j] = stringLinha[j] - '0';
        }
    }

    fclose(arquivo);

    system("pause"); //descomentar essa linha caso descomente as linhas dos prints

    return;
}

void limpaTela()
{
#ifdef OS_Windows
    system("cls");
#else
    system("clear");
#endif
}