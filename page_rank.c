#include "page_rank.h"
#include <stdlib.h>
#define ALFA 0.85
#define BETA 0.15
#define EPS 0.000001

static double calcula_E(int n, double *pr, double *antigo_pr){
    double sum = 0.0;
    for(int i=0; i < n; i++){
        sum += fabs(pr[i] - antigo_pr[i]);
    }
    return sum / (double) n;
}

double *calcula_pagerank(Graph *grafo){

    int num_paginas = get_num_paginas_grafo(grafo);

    // vetor de double pra guardar os pageranks
    // pr[i] = pagerank da página com id = i
    double *pr = (double*) calloc(num_paginas, sizeof(double));
    double *antigo_pr = (double*) calloc(num_paginas, sizeof(double));
    int *out = get_qtd_out(grafo);

    // inicialização
    for (int i = 0; i < num_paginas; i++){
        pr[i] = 1.0 / num_paginas;
    }

    /// calcula pagerank ///
    int k = 0;
    while(1){ 
        for(int i=0; i < num_paginas; i++)
            antigo_pr[i] = pr[i];

        for(int i=0; i < num_paginas; i++){
            pr[i] = BETA / (double) num_paginas;
            if(out[i] == 0){
                pr[i] += ALFA * antigo_pr[i];
            }
            double sum = 0;
            for(int j=0; j < num_paginas; j++){ 
                if(tem_link_para_i(grafo, i, j)){
                    sum += antigo_pr[j] / out[j];
                }
            }
            sum *= ALFA;
            pr[i] += sum;
        }

        if(calcula_E(num_paginas, pr, antigo_pr) < EPS){
            break;
        }
        k++;
    }

    return pr;
}
