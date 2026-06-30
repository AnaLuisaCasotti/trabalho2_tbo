#include "lista_docs.h"

struct DocNode {
    int doc_id; // id do documento é a índice dele no vetor em que eles ficam guardados
    struct DocNode *prox;
};

struct DocList {
    DocNode *inicio;
    DocNode *fim;
    int tamanho;
};

DocList *cria_doclist(){
    DocList *l = (DocList*) calloc(1, sizeof(DocList));

    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;

    return l;
}

int vazia_doclist(DocList *l){
    if (l->tamanho == 0) return 1;

    return 0;
}

int get_tamanho_doclist(DocList *l){
    return l->tamanho;
}

void insere_doclist(DocList *l, int doc_id){
    DocNode *novo = (DocNode*) calloc(1, sizeof(DocNode));

    novo->doc_id = doc_id;
    novo->prox = NULL;

    if (l->fim == NULL){ // Se fila está vazia:
        l->inicio = novo;
        l->fim = novo;
    }

    else {
        l->fim->prox = novo;
        l->fim = novo;
    }

    l->tamanho++;
}

void print_doclist(DocList *l){
    
    DocNode *atual = l->inicio;
    
    while(atual != NULL){
        printf("%d ", atual->doc_id);

        atual = atual->prox;
    }

    printf("\n");
}

void free_doclist(DocList *l){
    if (l == NULL) return;

    DocNode *atual = l->inicio;

    while(atual != NULL){
        DocNode *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    free(l);
}

DocList *encontra_intersecao(DocList *l1, DocList *l2) {
    DocList *intersecao = cria_doclist();
    if (intersecao == NULL) return NULL;

    if (l1 == NULL || l2 == NULL || l1->tamanho == 0 || l2->tamanho == 0) {
        return intersecao; 
    }

    DocNode *p1 = l1->inicio;
    DocNode *p2 = l2->inicio;

    
    while (p1 != NULL && p2 != NULL) {
        if (p1->doc_id == p2->doc_id) {
            insere_doclist(intersecao, p1->doc_id); 
            p1 = p1->prox;
            p2 = p2->prox;
        } 
        else if (p1->doc_id < p2->doc_id) {
            p1 = p1->prox;
        } 
        else {
            p2 = p2->prox;
        }
    }

    return intersecao;
}

DocList* clona_doclist(DocList *l) {
    DocList *nova = cria_doclist(); 
    if (nova == NULL || l == NULL) return nova;

    DocNode* atual = l->inicio;
    while (atual != NULL) {
        insere_doclist(nova, atual->doc_id); 
        atual = atual->prox;
    }
    return nova;
}

void print_com_nomes(DocList *l, VetorStr *docs){
    DocNode *atual = l->inicio;
    while(atual != NULL){
      printf("%s", get_string_vetor(docs, atual->doc_id));
      if(atual->prox != NULL) printf(" ");
      atual = atual->prox;
    }
}

void print_com_pr(DocList *l, double *pr){
    DocNode *atual = l->inicio;
    while(atual != NULL){
      printf("%.17g", pr[atual->doc_id]);
      if(atual->prox != NULL) printf(" ");
      atual = atual->prox;
    }
}

typedef struct aux{
  DocNode *no;
  double pr;
}Aux;

int compara_pr(const void *a, const void *b){
  Aux *aux1 = (Aux*) a;
  Aux *aux2 = (Aux*) b;

  if(aux1->pr > aux2->pr) return -1;
  if(aux1->pr < aux2->pr) return 1;
  else return aux1->no->doc_id - aux2->no->doc_id;
}

void ordena_doclist(DocList *l, double *pr){
    int tam = l->tamanho;

    Aux* aux = (Aux*)malloc(tam * sizeof(Aux));
    if (aux == NULL) return;

    DocNode *atual = l->inicio;
    
    for (int i = 0; i < tam; i++) {
        aux[i].no = atual;
        aux[i].pr = pr[atual->doc_id];
        atual = atual->prox;
    }

    qsort(aux, tam, sizeof(Aux), compara_pr);

    l->inicio = aux[0].no;
    
    for (int i = 0; i < tam - 1; i++) {
        aux[i].no->prox = aux[i+1].no;
    }
    
    aux[tam - 1].no->prox = NULL; 
    l->fim = aux[tam - 1].no; 

    free(aux);
}