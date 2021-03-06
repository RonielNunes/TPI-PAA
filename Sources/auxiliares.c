/*
*   Programa: PROBLEMA DO LABIRINTO
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "../Headers/includes.h"

// ================ texto colorido ================

// Algoritmo para texto colorido retirado do site: https://www.clubedohardware.com.br/topic/1307510-programa-em-c-ou-c-com-texto-colorido-como-criar-estou-usando-dev-c/

/*             0     1    2     3   4      5      6      7         8  */
typedef enum
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY, /* nome das cores */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
} COLORS;
/*  9         10         11        12        13         14    15 */

static int __BACKGROUND = 15 /*BLACK*/; /*pode ser o numero ou o nome da cor*/
static int __FOREGROUND = LIGHTGRAY;

void textcolor(int letras, int fundo)
{ /*para mudar a cor de fundo mude o background*/
    __FOREGROUND = letras;
    __BACKGROUND = fundo;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            letras + (__BACKGROUND << 4));
}

// fim do algoritmo referenciado

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
    puts("1 - Carregar novo arquivo de dados\n2 - Processar Labirinto e Exibir Resposta\n3 - Exibir o caminho feito ate a saida\n0 - Finalizar o Programa\n");
    linha();
    printf("Sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

void leituraArquivo(TipoApontador *apLabirinto)
{
    int i, j, linha, coluna, chave;

    char nomeArquivo[20], caminhoArquivo[40] = "./arquivos/";

    FILE *arquivo;

    printf("Entre com o nome do arquivo: ");

    scanf("%s", nomeArquivo);

    strcat(caminhoArquivo, nomeArquivo);

    arquivo = fopen(caminhoArquivo, "r");

    if (arquivo == NULL)
    {
        puts("Erro de abertura!");
        pausaPrograma();
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

void pausaPrograma()
{
#ifdef OS_Windows
    system("pause");
#else
    puts("Pressione qualquer tecla para continuar. . .");
    getchar();
    getchar();
#endif
}