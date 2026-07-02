#include "page_rank.h"

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
            double sum = sum_page_rank(grafo, i, antigo_pr);
            
            /*for(int j=0; j < num_paginas; j++){ 
                if(tem_link_para_i(grafo, i, j)){
                    sum += antigo_pr[j] / out[j];
                }
            }*/
           
            sum *= ALFA;
            pr[i] += sum;
        }

        if(calcula_E(num_paginas, pr, antigo_pr) < EPS){
            break;
        }
        k++;
    }

    free(antigo_pr);

    // arredonda os valores para 17 casas decimais
    /*for (int i = 0; i < num_paginas; i++){
        pr[i] = round(pr[i] * 1e17) / 1e17;
    }*/

    return pr;
}
