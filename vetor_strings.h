#ifndef VETOR_STRINGS_H
#define VETOR_STRINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vetorStr VetorStr;

/**
 * @brief inicializa um vetor de strings
 * @return o vetor inicializado
 */
VetorStr *cria_vetor();

/**
 * @brief insere uma string em um vetor de strings
 * @param v o vetor
 * @param string a string
 */
void insere_vetor(VetorStr *v, char *string);

/**
 * @brief compara duas strings
 * @param a string 1
 * @param b string 2
 * @return -1 se a < b, 1 se a > b, 0 se a = b.
 */
int compara_string(const void *a, const void *b);

/**
 * @brief ordena um vetor de strings em ordem alfabética crescente
 * @param v o vetor
 */
void ordena_vetor(VetorStr *v);

/**
 * @brief faz busca binária para achar o índice no vetor da string passada
 * @param v o vetor
 * @param string a string
 * @param inicio posição de início do vetor
 * @param fim posição de fim do vetor
 * @return -1 se a string não estiver no vetor, caso contrário, o índice dela no vetor
 */
int find_index(VetorStr *v, char *string, int inicio, int fim);

/**
 * @brief retorna a string guardada na posição passada como parâmetro
 * @param v o vetor de strings
 * @param i o índice/posição no vetor
 * @return a string na posição i
 */
char *get_string_vetor(VetorStr *v, int i);

/**
 * @brief retorna o tamanho do vetor
 * @param v o vetor
 * @return tamanho do vetor
 */
int get_tam_vetor(VetorStr *v);

/**
 * @brief imprime um vetor de strings
 * @param v o vetor
 */
void imprime_vetor(VetorStr *v);

/**
 * @brief desaloca um vetor de strings
 * @param v o vetor
 */
void free_vetor(VetorStr *v);

#endif