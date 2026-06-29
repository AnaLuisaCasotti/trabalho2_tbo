// Representação do grafo de links com uma lista de vetores.
/* vetor[i] aponta para um lista de todos os documentos/páginas 
   que são apontadas pelo documento de índice i. */

#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct graphNode GraphNode;

typedef struct graph Graph;

/**
 * @brief inicializa um grafo vazio e aloca os campos necessários
 * @param n número de páginas que serão adicionadas no grafo
 * @return grafo inicializado
 */
Graph *cria_grafo(int n);

/**
 * @brief insere um novo link ao grafo
 * @param g grafo a ser modificado
 * @param i id (índice) da página fonte
 * @param j id (índice) da página destino
 * @note página i tem um link que aponta para a página j
 */
void insere_grafo(Graph *g, int i, int j);

/**
 * @brief retorna o número de páginas no grafo
 * @param g grafo
 * @return número de páginas no grafo
 */
int get_num_paginas_grafo(Graph *g);


/**
 * @brief desaloca um grafo
 */
void free_grafo(Graph *g);


#endif