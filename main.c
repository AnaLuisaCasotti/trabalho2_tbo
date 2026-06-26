#include "vetor_strings.h"
#include "grafo.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    char *nome_diretorio;
    VetorStr *docs; // vetor de strings com os nomes dos documentos
    Graph *grafo; // estrtura que guarda os links entre os documentos/páginas

    if (argc < 2){
        printf("Quantidade insuficiente de argumentos!\n");
        exit(1);
    }

    FILE *graph, *index, *searches, *stopwords;

    nome_diretorio = argv[1];

    index = abre_arquivo(nome_diretorio, "index.txt");
    le_index(index, &docs); // preenche o vetor com o nome de cada documento/página
    ordena_vetor(docs);

    imprime_vetor(docs); // TESTE

    graph = abre_arquivo(nome_diretorio, "graph.txt");
    le_graph(graph, &grafo, docs); // le graph.txt e cria a estrutura de links entre os documentos/páginas

    fclose(graph);
    fclose(index);
    free_vetor(docs);
    free_grafo(grafo);
    
    return 0;
}