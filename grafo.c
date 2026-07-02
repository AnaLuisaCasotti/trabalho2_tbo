#include "grafo.h"

struct graphNode {
   int indx; // índice da página de destino ou fonte
   struct graphNode *prox;
};

struct graph {
    int n;             // num de páginas
    GraphNode **out;   // vetor de listas. out[i] aponta para a lista de páginas apontadas pela página de índice i
    GraphNode **in;    // vetor de listas. in[i] aponta para a lista de páginas que apontam para a página de índice i
    int *qtd_out;      /* vetor de inteiros. qtd_out[i] é a qtd de páginas apontadas 
                         pela página de índice i (tam da lista em out[i])*/
    int *qtd_in;       /* vetor de inteiros. qtd_in[i] é a qtd de páginas que apontam 
                          para a página de índice i (tam da lista em in[i])*/
};

Graph *cria_grafo(int n){

    Graph *g = (Graph*) calloc(1, sizeof(Graph));
    g->out = (GraphNode**) calloc(n, sizeof(GraphNode*));
    g->in = (GraphNode**) calloc(n, sizeof(GraphNode*));
    g->qtd_out = (int*) calloc(n, sizeof(int));
    g->qtd_in = (int*) calloc(n, sizeof(int));

    g->n = n;

    return g;
}

// pag i aponta para pag j (i é a fonte, j é o destino)
void insere_grafo(Graph *g, int i, int j){

    GraphNode *novo_out = (GraphNode*) calloc(1, sizeof(GraphNode));
    novo_out->indx = j;

    novo_out->prox = g->out[i]; // insere no início da lista
    g->out[i] = novo_out;

    GraphNode *novo_in = (GraphNode*) calloc(1, sizeof(GraphNode));
    novo_in->indx = i;

    novo_in->prox = g->in[j]; // insere no início da lista
    g->in[j] = novo_in;

    g->qtd_out[i]++;
    g->qtd_in[j]++;
}

int get_num_paginas_grafo(Graph *g){
    return g->n;
}

int *get_qtd_out(Graph *g){
    return g->qtd_out;
}

GraphNode **get_in(Graph *g){
    return g->in;
}

int tem_link_para_i(Graph *g, int i, int j){
    for(GraphNode *ptr = g->out[j]; ptr != NULL; ptr = ptr->prox){
        if(ptr->indx == i) return 1;
    }
    return 0;
}

double sum_page_rank(Graph *g, int i, double *antigo_pr){
    
    double sum = 0.0;

    for(GraphNode *ptr = g->in[i]; ptr != NULL; ptr = ptr->prox){
        int j = ptr->indx;
        sum += antigo_pr[j] / (double) g->qtd_out[j];
    }
    return sum;
}

void free_grafo(Graph *g){

    if (g == NULL) return;

    // desaloca a lista apontada por cada posição do vetor
    for (int i = 0; i < g->n; i++){
        GraphNode *atual = g->out[i];

        while(atual != NULL){
            GraphNode *aux = atual;
            atual = atual->prox;
            free(aux);
        }
    }

    for (int i = 0; i < g->n; i++){
        GraphNode *atual = g->in[i];

        while(atual != NULL){
            GraphNode *aux = atual;
            atual = atual->prox;
            free(aux);
        }
    }

    free(g->out);
    free(g->in);
    free(g->qtd_out);
    free(g->qtd_in);
    free(g);
}