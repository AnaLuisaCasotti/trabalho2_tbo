#include "grafo.h"

struct graphNode {
   int dest; // índice da página de destino
   struct graphNode *prox;
};

struct graph {
   int n;             // num de páginas
   GraphNode **out;   // vetor de listas. out[i] aponta para a lista de páginas apontadas pela página de índice i
   int *qtd_out;      /* vetor de inteiros. qtd_out[i] é a qtd de páginas apontadas 
                         pela página de índice i (tam da lista em out[i])*/
};

Graph *cria_grafo(int n){

    Graph *g = (Graph*) calloc(1, sizeof(Graph));
    g->out = (GraphNode**) calloc(n, sizeof(GraphNode*));
    g->qtd_out = (int*) calloc(n, sizeof(int));

    g->n = n;

    return g;
}

// pag i aponta para pag j (i é a fonte, j é o destino)
void insere_grafo(Graph *g, int i, int j){

    GraphNode *novo = (GraphNode*) calloc(1, sizeof(GraphNode));
    novo->dest = j;

    novo->prox = g->out[i]; // insere no início da lista
    g->out[i] = novo;

    g->qtd_out[i]++;
}

int get_num_paginas_grafo(Graph *g){
    return g->n;
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

    free(g->out);
    free(g->qtd_out);
    free(g);
}