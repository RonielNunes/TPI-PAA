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
     
    FILE *arquivo = NULL;
    int linha, coluna, nChaves;
    int i = 0,j = 0;

    textoInicial ();

    do{
        escolhaMenu = escolhaUsuario ();

        switch(escolhaMenu){
            case 1:
                puts("abrir e ler arquivo");


                //LEITURA DE ARQUIVO IMPROVISADO, TESTANDO.
                arquivo = fopen("./arquivos/labirinto1.txt","r");
                if (arquivo == NULL){
                    printf("ERRO!\n");
                }else{
                    fscanf(arquivo,"%d %d %d",&linha,&coluna,&nChaves);
                    labirinto = inicializaLabirinto(linha,coluna);
                    char reader[coluna];
                    char auxChar;
                    //printf("%d %d %d \n",linha,coluna,nChaves);
                    while (!feof(arquivo)){
                        fscanf(arquivo,"%s",&reader);
                        for ( j = 0; j < coluna; j++){
                            auxChar = reader[j];
                            labirinto[i][j] = atoi(&auxChar);
                        }
                        i++;
                    }
                    mostraLabirinto(linha,coluna,labirinto);
                }
                fclose(arquivo);
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