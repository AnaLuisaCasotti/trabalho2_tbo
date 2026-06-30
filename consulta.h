// Processador de consultas

// Lê termos da query, ignora stop words
// Intersecta listas de docs de cada termo
// Ordena resultado por PageRank (decrescente), desempate lexicográfico
#ifndef CONSULTA_H
#define CONSULTA_H
#include "page_rank.h"
#include "TST.h"
#include "vetor_strings.h"
#include "lista_docs.h"
#include "utils.h"

void ler_consultas(VetorStr *docs, TST *palavras_tst, TST *stopwords_tst, Graph *grafo);

DocList* fazer_consulta(char* consulta, TST *palavras_tst, TST *stopwords_tst);

#endif