#include "lista_docs.h"

struct DocNode {
    int doc_id; // id do documento é a índice dele no vetor em que eles ficam guardados
    struct DocNode *prox;
};

struct DocList {
    DocNode *inicio;
    DocNode *fim;
    int tamanho;
};

DocList *cria_doclist(){
    DocList *l = (DocList*) calloc(1, sizeof(DocList));

    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;

    return l;
}

int vazia_doclist(DocList *l){
    if (l->tamanho == 0) return 1;

    return 0;
}

int get_tamanho_doclist(DocList *l){
    return l->tamanho;
}

void insere_doclist(DocList *l, int doc_id){
    DocNode *novo = (DocNode*) calloc(1, sizeof(DocNode));

    novo->doc_id = doc_id;
    novo->prox = NULL;

    if (l->fim == NULL){ // Se fila está vazia:
        l->inicio = novo;
        l->fim = novo;
    }

    else {
        l->fim->prox = novo;
        l->fim = novo;
    }

    l->tamanho++;
}

void print_doclist(DocList *l){
    
    DocNode *atual = l->inicio;
    
    while(atual != NULL){
        printf("%d ", atual->doc_id);

        atual = atual->prox;
    }

    printf("\n");
}

void free_doclist(DocList *l){
    if (l == NULL) return;

    DocNode *atual = l->inicio;

    while(atual != NULL){
        DocNode *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    free(l);
}