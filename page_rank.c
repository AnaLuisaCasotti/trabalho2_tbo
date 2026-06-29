#include "page_rank.h"

double *calcula_pagerank(Graph *grafo){

    int num_paginas = get_num_paginas_grafo(grafo);

    // vetor de double pra guardar os pageranks
    // pr[i] = pagerank da página com id = i
    double *pr = (double*) calloc(num_paginas, sizeof(double));

    for (int i = 0; i < num_paginas; i++){
        pr[i] = 0.0;
    }

    /// calcula pagerank ///

    return pr;
}