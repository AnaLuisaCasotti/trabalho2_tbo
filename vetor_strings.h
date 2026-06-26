#ifndef VETOR_STRINGS_H
#define VETOR_STRINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vetorStr VetorStr;

VetorStr *cria_vetor();

void insere_vetor(VetorStr *v, char *string);

int compara_string(const void *a, const void *b);

void ordena_vetor(VetorStr *v);

int find_index(VetorStr *v, char *string, int inicio, int fim);

char *get_string_vetor(VetorStr *v, int i);

int get_tam_vetor(VetorStr *v);

void imprime_vetor(VetorStr *v);

void free_vetor(VetorStr *v);

#endif