#ifndef PAGE_RANK_H
#define PAGE_RANK_H

#include "grafo.h"
#include <stdlib.h>
#include <math.h>

#define ALFA 0.85
#define BETA 0.15
#define EPS 1e-6

/**
 * @brief calcula o pagerank de todas as páginas
 * @param grafo o grafo
 * @return vetor com os pageranks. vetor[i] guarda o pagerank da página com id = i
 */
double *calcula_pagerank(Graph *grafo);

#endif