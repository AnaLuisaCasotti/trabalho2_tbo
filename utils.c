#include "utils.h"

FILE *abre_arquivo(char *nome_diretorio, char *nome_arquivo){
    
    char caminho[MAX_PATH];

    snprintf(caminho, sizeof(caminho), "%s/%s", nome_diretorio, nome_arquivo);

    return fopen(caminho, "r");
}

void le_index(char *nome_diretorio, VetorStr **docs){

    FILE *index = abre_arquivo(nome_diretorio, "index.txt");

    char nome_doc[200];
    *docs = cria_vetor();

    while(fscanf(index, "%[^\n]\n", nome_doc) != EOF){
        insere_vetor(*docs, nome_doc);
    }

    fclose(index);
}

// essa função usa muitos loops e buscas em vetor. Deve influenciar na eficiência
void le_graph(char *nome_diretorio, Graph **grafo, VetorStr *docs){

    FILE *graph = abre_arquivo(nome_diretorio, "graph.txt");

    char doc_fonte[100], doc_dest[100];
    
    *grafo = cria_grafo(get_tam_vetor(docs));

    while(fscanf(graph, "%s%*c", doc_fonte) != EOF){
        //printf("doc fonte: %s, ", doc_fonte); // TESTE

        int indx_doc_fonte = find_index(docs, doc_fonte, 0, get_tam_vetor(docs)); // busca o índice do documento lido
        int qtd_links = 0;

        //printf("indx: %d, ", indx_doc_fonte); // TESTE

        fscanf(graph, "%d%*c", &qtd_links);
        //printf("qtd links: %d\n", qtd_links); // TESTE

        //printf("docs dest:\n"); // TESTE
        for (int i = 0; i < qtd_links; i++){
            fscanf(graph, "%s%*c", doc_dest);
            //printf("%s\n", doc_dest); // TESTE

            int indx_doc_dest = find_index(docs, doc_dest, 0, get_tam_vetor(docs));

            insere_grafo(*grafo, indx_doc_fonte, indx_doc_dest);
        }

        //printf("\n"); // TESTE

    }

    fclose(graph);
}

void le_stopwords(char *nome_diretorio, TST **stopwords_tst){

    FILE *stopwords = abre_arquivo(nome_diretorio, "stopwords.txt");

    char palavra[100];
    *stopwords_tst = cria_tst();

    while(fscanf(stopwords, "%s%*c", palavra) != EOF){
        
        padronizar_string(palavra);
        *stopwords_tst = TST_insert(*stopwords_tst, palavra, -1); // coloquei doc_id como -1 pq as stopwords não precisam estar associadas a nenhum documento
    }

    fclose(stopwords);
}

void padronizar_string(char *string){

    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] = tolower(string[i]);
    }
}

void le_pagina(FILE *page, char *page_name, VetorStr *docs, TST **palavras_tst, TST *stopwords_tst){

    char palavra[100];

    while(fscanf(page, "%s%*c", palavra) != EOF){
        
        padronizar_string(palavra);

        if (TST_search(stopwords_tst, palavra) == NULL) continue; // se é stopword, continua

        *palavras_tst = TST_insert(*palavras_tst, palavra, find_index(docs, page_name, 0, get_tam_vetor(docs))); // se não, insere na tst (tabela de símbolos)
    }
}

void le_diretorio_pages(VetorStr *docs, TST **palavras_tst, TST *stopwords_tst){

    *palavras_tst = cria_tst();

    char *pasta = "exemplo/pages";

    DIR *diretorio = opendir(pasta);

    if (diretorio == NULL){
        printf("Erro ao abrir o diretório\n");
        exit(1);
    }

    struct dirent *entrada;

    while ((entrada = readdir(diretorio)) != NULL){

        // ignora "." e ".."
        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0)
            continue;

        char page_name[MAX_PATH], caminho[MAX_PATH];

        // guarda o nome da página atual
        snprintf(page_name, sizeof(page_name), "%s", entrada->d_name);

        FILE *page = abre_arquivo("exemplo/pages", page_name);
        le_pagina(page, page_name, docs, palavras_tst, stopwords_tst);
        fclose(page);
    }

    closedir(diretorio);
}