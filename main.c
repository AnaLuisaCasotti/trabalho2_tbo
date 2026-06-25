#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 500

FILE *abre_arquivo(char *nome_diretorio, char *nome_arquivo){
    
    char caminho[MAX_PATH];

    snprintf(caminho, sizeof(caminho), "%s/%s", nome_diretorio, nome_arquivo);
    printf("%s\n", caminho);

    return fopen(caminho, "r");
}

int main(int argc, char *argv[])
{
    char *nome_diretorio, teste[200];
    char **docs; // vetor de strings com os nomes dos documentos

    if (argc < 2){
        printf("Quantidade insuficiente de argumentos!\n");
        exit(1);
    }

    FILE *graphs, *index, *searches, *stopwords;

    nome_diretorio = argv[1];
    
    graphs = abre_arquivo(nome_diretorio, "graph.txt");

    fscanf(graphs, "%[\n]", teste);
    printf("%s\n", teste);

    fclose(graphs);
    
    return 0;
}