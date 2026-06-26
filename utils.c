#include "utils.h"

FILE *abre_arquivo(char *nome_diretorio, char *nome_arquivo){
    
    char caminho[MAX_PATH];

    snprintf(caminho, sizeof(caminho), "%s/%s", nome_diretorio, nome_arquivo);

    return fopen(caminho, "r");
}

void le_index(FILE *index, VetorStr **docs){

    char nome_doc[200];
    *docs = cria_vetor();

    while(fscanf(index, "%[^\n]\n", nome_doc) != EOF){
        insere_vetor(*docs, nome_doc);
    }
}

// essa função usa muitos loops e buscas em vetor. Deve influenciar na eficiência
void le_graph(FILE *graph, Graph **grafo, VetorStr *docs){

    char doc_fonte[100], doc_dest[100];
    
    *grafo = cria_grafo(get_tam_vetor(docs));

    while(fscanf(graph, "%s%*c", doc_fonte) != EOF){
        printf("doc fonte: %s, ", doc_fonte); // TESTE

        int indx_doc_fonte = find_index(docs, doc_fonte, 0, get_tam_vetor(docs)); // busca o índice do documento lido
        int qtd_links = 0;

        printf("indx: %d, ", indx_doc_fonte); // TESTE

        fscanf(graph, "%d%*c", &qtd_links);
        printf("qtd links: %d\n", qtd_links); // TESTE

        printf("docs dest:\n"); // TESTE
        for (int i = 0; i < qtd_links; i++){
            fscanf(graph, "%s%*c", doc_dest);
            printf("%s\n", doc_dest); // TESTE

            int indx_doc_dest = find_index(docs, doc_dest, 0, get_tam_vetor(docs));

            insere_grafo(*grafo, indx_doc_fonte, indx_doc_dest);
        }

        printf("\n"); // TESTE

    }
}