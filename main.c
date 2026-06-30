#include "vetor_strings.h"
#include "lista_docs.h"
#include "grafo.h"
#include "utils.h"
#include "TST.h"
#include "consulta.h"

int main(int argc, char *argv[])
{
    char *nome_diretorio;
    VetorStr *docs; // vetor de strings com os nomes dos documentos
    Graph *grafo; // estrtura que guarda os links entre os documentos/páginas
    TST *palavras_tst, *stopwords_tst;

    if (argc < 2){
        printf("Quantidade insuficiente de argumentos!\n");
        exit(1);
    }

    nome_diretorio = argv[1];

    le_index(nome_diretorio, &docs); // preenche o vetor com o nome de cada documento/página
    ordena_vetor(docs);

    //imprime_vetor(docs); // TESTE

    le_graph(nome_diretorio, &grafo, docs); // le graph.txt e cria a estrutura de links entre os documentos/páginas

    le_stopwords(nome_diretorio, &stopwords_tst); // le stopwords.h e cria uma tst para as stopwords

    le_diretorio_pages(docs, &palavras_tst, stopwords_tst);

    ler_consultas(docs, palavras_tst, stopwords_tst, grafo);
    
    free_vetor(docs);
    free_grafo(grafo);
    desaloca_tst(stopwords_tst);
    desaloca_tst(palavras_tst);
    
    return 0;
}