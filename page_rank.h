// Recebe o grafo de adjacência (quem aponta pra quem) e calcula o Page Rank.

#ifndef PAGE_RANK_H
#define PAGE_RANK_H

#include "grafo.h"

#define ALPHA 0.85

double *calcula_pagerank(Graph *grafo);

#endif