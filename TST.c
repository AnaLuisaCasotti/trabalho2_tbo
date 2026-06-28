#include "TST.h"

struct tst
{
    unsigned char c;
    TST *esq;
    TST *meio;
    TST *dir;
    DocList *docs;
};

static TST *create_node()
{
    TST *nova = (TST *)calloc(1, sizeof(TST));

    nova->esq = NULL;
    nova->meio = NULL;
    nova->dir = NULL;
    nova->docs = NULL;

    return nova;
}

// key = "ana\0"           (na primeira chamada)
// key' = key + 1 = "na\0" (na segunda chamada)
// key'' = key + 1 = "a\0" (na terceira chamada)
// key''' = "\0"           (na ultima chamada)

TST *cria_tst()
{
    return NULL;
}

static TST *rec_insert(TST *t, char *key, int doc_id)
{
    unsigned char c = *key; // se key = "ana\0" -> *key = 'a' (primeiro caracter)

    // caso tenha encontrado um noh nulo, faz-se um novo noh e o processo de insercao continua
    if (t == NULL)
    {
        t = create_node();
        t->c = c;
    }

    // caso o caracter a ser inserido seja menor do que o caracter do noh atual, continua a insersao no noh filho a esquerda
    if (c < t->c)
    {
        t->esq = rec_insert(t->esq, key, doc_id);
    }

    // caso o caracter a ser inserido seja maior do que o caracter do noh atual, continua a insersao no noh filho a direita
    else if (c > t->c)
    {
        t->dir = rec_insert(t->dir, key, doc_id);
    }

    // se o proximo caracter da string for diferente de '\0' continua recursivamente para o noh filho do meio
    else if (*(key + 1) != '\0')
    {
        t->meio = rec_insert(t->meio, key + 1, doc_id);
    }
    else
    {
        /*se a lista de documentos nesse noh for nula, significa que essa palavra
        nao fazia parte da tst ainda, apenas adiciona-se o doc_id na lista de documentos
         ja existente */
        if (t->docs == NULL)
            t->docs = cria_doclist();

        insere_doclist(t->docs, doc_id);
    }

    return t;
}

TST *TST_insert(TST *t, char *key, int doc_id)
{
    return rec_insert(t, key, doc_id);
}

static TST *rec_search(TST *t, char *key)
{
    if (t == NULL)
    {
        return NULL;
    }

    unsigned char c = *key;

    if (c < t->c)
    {
        return rec_search(t->esq, key);
    }
    else if (c > t->c)
    {
        return rec_search(t->dir, key);
    }
    else if (*(key + 1) != '\0')
    {
        return rec_search(t->meio, key + 1);
    }
    else
    {
        return t;
    }
}

DocList *TST_search(TST *t, char *key)
{
    t = rec_search(t, key);

    if (t == NULL)
    {
        return NULL;
    }

    return t->docs;
}

static TST *rec_desloca(TST *t)
{
    if (t == NULL)
    {
        return NULL;
    }

    t->esq = rec_desloca(t->esq);
    t->dir = rec_desloca(t->dir);
    t->meio = rec_desloca(t->meio);

    free_doclist(t->docs);

    return NULL;
}

TST *desaloca_tst(TST *t)
{
    return rec_desloca(t);
}