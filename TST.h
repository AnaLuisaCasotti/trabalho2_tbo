#ifndef TST_H
#define TST_H

#include "lista_docs.h"
#include <stdbool.h>

typedef struct tst TST;

/**
 * @brief inicializa uma tst nula
 * @return NULL
 */
TST *cria_tst();

/**
 * @brief insere um chave (string/palavra) na tst
 * @param t trie a ser modificada
 * @param key string a ser adcionada na arvore
 * @return tst atualizada
 */
TST *TST_insert(TST *t, char *key);

/**
 * @brief busca uma string/palavra em uma tst
 * @param t arvore a ser concatenada
 * @param key palavra a ser buscada
 * @return se for encontrada: a lista de documentos onde esta palavra aparece; se não for encontrada: NULL
 */
DocList *TST_search(TST *t, char *key);

/**
 * @brief desaloca uma tst
 * @return tst atualizada (NULL)
 */
TST *desaloca_tst(TST *t);

#endif