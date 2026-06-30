#ifndef LISTA_DOCS_H
#define LISTA_DOCS_H

#include <stdio.h>
#include <stdlib.h>
#include "vetor_strings.h"

// OBS: passar structs para o .c depois para a estrutura ficar opaca.

typedef struct DocNode DocNode;
typedef struct DocList DocList;

DocList *cria_doclist();

int vazia_doclist(DocList *l);

int get_tamanho_doclist(DocList *l);

void insere_doclist(DocList *l, int doc_id);

void print_doclist(DocList *l);

void free_doclist(DocList *l);

DocList *encontra_intersecao(DocList *l1, DocList *l2);

DocList *clona_doclist(DocList *l);

void print_com_nomes(DocList *l, VetorStr *docs);

void print_com_pr(DocList *l, double *pr);

int compara_pr(const void *a, const void *b);

void ordena_doclist(DocList *l, double *pr);

#endif