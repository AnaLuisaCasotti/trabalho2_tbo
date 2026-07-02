#ifndef LISTA_DOCS_H
#define LISTA_DOCS_H

#include <stdio.h>
#include <stdlib.h>
#include "vetor_strings.h"

typedef struct DocNode DocNode;
typedef struct DocList DocList;

/**
 * @brief inicializa uma lista de documentos
 * @return a lista inicializada
 */
DocList *cria_doclist();

/**
 * @brief verifica se a lista está vazia
 * @param l a lista
 * @return 1 se está vazia, 0 caso contrário
 */
int vazia_doclist(DocList *l);

/**
 * @brief retorna o tamanho da lista
 * @param l a lista
 * @return o tamanho da lista
 */
int get_tamanho_doclist(DocList *l);

/**
 * @brief insere um documento na lista de documentos
 * @param l a lista
 * @param doc_id o índice (id) do documento/página
 */
void insere_doclist(DocList *l, int doc_id);

/**
 * @brief imprime os índices (ids) dos documentos/páginas
 * @param l a lista
 */
void print_doclist(DocList *l);

/**
 * @brief encontra a interseção entre duas listas de documentos
 * @param l1 lista 1
 * @param l2 lista 2
 * @return nova lista com a interseção (documentos em comum)
 */
DocList *encontra_intersecao(DocList *l1, DocList *l2);

/**
 * @brief cria um cópia de uma lista
 * @param l lista
 * @return nova lista igual à passada como parâmetro
 */
DocList *clona_doclist(DocList *l);

/**
 * @brief imprime os nomes dos documentos/páginas
 * @param l a lista de documentos
 * @param docs vetor que guarda os nomes dos documentos
 */
void print_com_nomes(DocList *l, VetorStr *docs);

/**
 * @brief imprime os pageranks dos documentos/páginas
 * @param l a lista de documentos
 * @param pr vetor que guarda os pageranks dos documentos
 */
void print_com_pr(DocList *l, double *pr);

/**
 * @brief compara dois pageranks
 * @param a página 1
 * @param b página 2
 * @return -1 se pr_1 > pr_2, 1 se pr_1 < pr_2.
 *          caso sejam iguais, retorna a diferença entre os ids de cada página
 */
int compara_pr(const void *a, const void *b);

/**
 * @brief ordena uma lista de documentos/páginas em ordem decrescente de pageranks
 * @param l lista de documentos
 * @param pr vetor com os pageranks
 */
void ordena_doclist(DocList *l, double *pr);

/**
 * @brief desaloca uma lista de documentos/páginas
 * @param l a lista de documentos
 */
void free_doclist(DocList *l);

#endif