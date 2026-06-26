#ifndef UTILS_H
#define UTILS_H

#include "grafo.h"
#include "vetor_strings.h"

#define MAX_PATH 500

FILE *abre_arquivo(char *nome_diretorio, char *nome_arquivo);

void le_index(FILE *index, VetorStr **docs);

void le_graph(FILE *graph, Graph **grafo, VetorStr *docs);

#endif