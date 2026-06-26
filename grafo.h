// Representação do grafo de links com uma lista de vetores.
/* vetor[i] aponta para um lista de todos os documentos/páginas 
   que são apontadas pelo documento de índice i. */

#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct graphNode GraphNode;

typedef struct graph Graph;

Graph *cria_grafo(int n);

void insere_grafo(Graph *g, int i, int j); // pag i aponta para pag j

void free_grafo(Graph *g);


#endif