#include "vetor_strings.h"

struct vetorStr {
    char **vetor;
    int qtd;
    int cap;
};

VetorStr *cria_vetor(){
    
    VetorStr *v = (VetorStr*) calloc(1, sizeof(VetorStr));

    v->vetor = (char**) calloc(1, sizeof(char*)); // inicialmente, aloca um vetor de tamanho 1
    v->cap = 1;
    v->qtd = 0; // começa vazio

    return v;
}

void insere_vetor(VetorStr *v, char *string){

    if (v->qtd == v->cap){
        v->cap *= 2;
        v->vetor = (char**) realloc(v->vetor, v->cap*sizeof(char*));
    }

    v->vetor[v->qtd] = strdup(string);
    v->qtd++;
}

int compara_string(const void *a, const void *b){
    char *string_1 = *(char**)a;
    char *string_2 = *(char**)b;

    return strcmp(string_1, string_2);
}

void ordena_vetor(VetorStr *v){
    qsort(v->vetor, v->qtd, sizeof(char*), compara_string);
}

// faz busca binária para achar o índice da string passada
int find_index(VetorStr *v, char *string, int inicio, int fim){

    if (inicio >= fim) return -1;

    int meio = inicio + (fim - inicio) / 2;
    int comp = strcmp(string, v->vetor[meio]);

    if (comp == 0) return meio;
    else if (comp > 0) return find_index(v, string, meio+1, fim); // se a string for maior que a do meio, busca na segunda metade
    else return find_index(v, string, inicio, meio); // se a string for menor que a do meio, busca na primeira metada
}

char *get_string_vetor(VetorStr *v, int i){

    return v->vetor[i];
}

int get_tam_vetor(VetorStr *v){

    return v->qtd;
}

void imprime_vetor(VetorStr *v){

    for (int i = 0; i < v->qtd; i++){
        printf("%s\n", v->vetor[i]);
    }
}

void free_vetor(VetorStr *v){

    if (v == NULL) return;

    for (int i = 0; i < v->qtd; i++){
        free(v->vetor[i]);
    }

    free(v->vetor);
    free(v);
}