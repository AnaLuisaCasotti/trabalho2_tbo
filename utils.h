#ifndef UTILS_H
#define UTILS_H

#include "grafo.h"
#include "vetor_strings.h"
#include "TST.h"
#include <ctype.h>
#include <dirent.h>

#define MAX_PATH 500

/**
 * @brief abre um arquivo
 * @param nome_diretorio nome do diretório em que está o arquivo
 * @param nome_arquivo nome do arquivo a ser aberto
 * @return o arquivo aberto
 */
FILE *abre_arquivo(char *nome_diretorio, char *nome_arquivo);

/**
 * @brief lê index.txt
 * @param nome_diretorio nome do diretório em que está o arquivo
 * @param docs ponteiro para o vetor que guardará os nomes dos documentos/páginas
 */
void le_index(char *nome_diretorio, VetorStr **docs);

/**
 * @brief le graph.txt e cria a estrutura de links entre os documentos/páginas
 * @param nome_diretorio nome do diretório em que está o arquivo
 * @param graph ponteiro para a estrutura de grafo que guarda os links entre as páginas
 * @param docs vetor que guarda os nomes dos documentos/páginas
 */
void le_graph(char *nome_diretorio, Graph **grafo, VetorStr *docs);

/**
 * @brief le stopwords.txt e cria uma tst para as stopwords
 * @param nome_diretorio nome do diretório em que está o arquivo
 * @param stopwords_tst ponteiro para a tst que guardará as stopwords
 */
void le_stopwords(char *nome_diretorio, TST **stopwords_tst);

/**
 * @brief converte todos os caracteres de uma string para minúsculo
 * @param string string que será modificada
 */
void padronizar_string(char *string);

/**
 * @brief lê uma página
 * @param page o arquivo .txt da página
 * @param page_name nome da página
 * @param docs vetor que guarda os nomes dos documentos/páginas
 * @param palavras_tst ponteiro para a tst que guarda todas as palavras lidas das páginas de entrada
 * @param stopwords_tst tst que guarda as stopwords
 */
void le_pagina(FILE *page, char *page_name, VetorStr *docs, TST **palavras_tst, TST *stopwords_tst);

/**
 * @brief lê o conteúdo do diretório "pages"
 * @param nome_diretorio nome do diretório em que está o "pages"
 * @param docs vetor que guarda os nomes dos documentos/páginas
 * @param palavras_tst ponteiro para a tst que guarda todas as palavras lidas das páginas de entrada
 * @param stopwords_tst tst que guarda as stopwords
 */
void le_diretorio_pages(char *nome_diretorio, VetorStr *docs, TST **palavras_tst, TST *stopwords_tst);

#endif