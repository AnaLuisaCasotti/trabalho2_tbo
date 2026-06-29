#ifndef UTILS_H
#define UTILS_H

#include "grafo.h"
#include "vetor_strings.h"
#include "TST.h"
#include <ctype.h>
#include <dirent.h>

#define MAX_PATH 500

FILE *abre_arquivo(char *nome_diretorio, char *nome_arquivo);

void le_index(char *nome_diretorio, VetorStr **docs);

void le_graph(char *nome_diretorio, Graph **grafo, VetorStr *docs);

void le_stopwords(char *nome_diretorio, TST **stopwords_tst);

void padronizar_string(char *string);

void le_pagina(FILE *page, char *page_name, VetorStr *docs, TST **palavras_tst, TST *stopwords_tst);

void le_diretorio_pages(VetorStr *docs, TST **palavras_tst, TST *stopwords_tst);

#endif