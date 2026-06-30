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
 * @brief retorna o vetor de inteiros qtd_out[].
 *        cada posição qtd_out[i] gaurda a quantidade de páginas apontadas pela página de índice i
 * @param g grafo
 * @return vetor de inteiros (qtd_out[])
 */
int *get_qtd_out(Graph *g);

/**
 * @brief retorna o vetor de listas in[].
 *        cada posição in[i] aponta para a lista de páginas que apontam para a página de índice i
 * @param g grafo
 * @return vetor de listas
 */
GraphNode **get_in(Graph *g);

/**
 * @brief verifica se uma página j tem link para uma página i
 * @param g grafo
 * @param i índice (id) da página destino
 * @param j índice (id) da página fonte
 * @return 1 se j tem link para i; 0 caso contrário
 */
int tem_link_para_i(Graph *g, int i, int j);

/**
 * @brief calcula somatório do pagerank da página i
 * @param g grafo
 * @param i índice (id) da página
 * @param antigo_pr pagerank anterior
 * @return o pagerank
 */
double sum_page_rank(Graph *g, int i, double *antigo_pr);

/**
 * @brief desaloca um grafo
 */
void free_grafo(Graph *g);


#endif