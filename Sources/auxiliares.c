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

Labirinto leituraArquivo(int *qtLinhas, int *qtColunas, int *qtChaves)
{
    int i, j;

    Labirinto labirinto;

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
        return NULL;
    }

    fscanf(arquivo, "%d %d %d", qtLinhas, qtColunas, qtChaves);

    labirinto = inicializaLabirinto(*qtLinhas, *qtColunas);

    char stringLinha[*qtColunas]; // variavel que armazenara cada linha a partir da 2ª linha do arquivo

    for (i = 0; i < (*qtLinhas); i++)
    {
        fscanf(arquivo, "%s", &stringLinha);
        for (j = 0; j < (*qtColunas); j++)
        {
            labirinto[i][j] = stringLinha[j] - '0';
        }
    }
    
    //printf("Quantidade de linhas: %d, quantidade de colunas: %d e quantidade de chaves: %d\n", qtLinhas, qtColunas, qtChaves); //print dos dados do arquivo para verificar leitura - retirar antes de entregar

    fclose(arquivo);

    system("pause");//descomentar essa linha caso descomente as linhas dos prints

    return labirinto;
}

void limpaTela(){
    #ifdef OS_Windows
        system("cls");
    #else
        system("clear");
    #endif  
}