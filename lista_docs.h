#ifndef LISTA_DOCS_H
#define LISTA_DOCS_H

#include <stdio.h>
#include <stdlib.h>
#include "vetor_strings.h"

// OBS: passar structs para o .c depois para a estrutura ficar opaca.

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

void print_com_nomes(DocList *l, VetorStr *docs);

void print_com_pr(DocList *l, double *pr);

int compara_pr(const void *a, const void *b);

void ordena_doclist(DocList *l, double *pr);

void free_doclist(DocList *l);

#endif