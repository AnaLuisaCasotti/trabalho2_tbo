#ifndef LISTA_DOCS_H
#define LISTA_DOCS_H

#include <stdio.h>
#include <stdlib.h>

// OBS: passar structs para o .c depois para a estrutura ficar opaca.

typedef struct DocNode DocNode;
typedef struct DocList DocList;

DocList *cria_doclist();

int vazia_doclist(DocList *l);

int get_tamanho_doclist(DocList *l);

void insere_doclist(DocList *l, int doc_id);

void print_doclist(DocList *l);

void free_doclist(DocList *l);

#endif