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

/**
 * @brief lê o conteúdo de searches.txt
 * @param nome_diretorio nome do diretório em que está o arquivo
 * @param docs vetor que guarda os nomes dos documentos/páginas
 * @param palavras_tst tst que guarda todas as palavras lidas das páginas de entrada
 * @param stopwords_tst tst que guarda as stopwords
 * @param grafo o grafo
 */
void ler_consultas(char *nome_diretorio, VetorStr *docs, TST *palavras_tst, TST *stopwords_tst, Graph *grafo);

/**
 * @brief recebe uma linha de consulta e encontra os documentos em que que todos os termos da consulta aparecem
 * @param palavras_tst ponteiro para a tst que guarda todas as palavras lidas das páginas de entrada
 * @param stopwords_tst tst que guarda as stopwords
 * @return uma lista com os documentos em que todos os termos da consulta aparecem
 */
DocList* fazer_consulta(char* consulta, TST *palavras_tst, TST *stopwords_tst);

#endif