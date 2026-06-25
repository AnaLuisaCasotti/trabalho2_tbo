#include "TST.h"

// OBS: passar structs para o .c depois para a estrutura ficar opaca.

struct tst
{
    unsigned char c;
    bool final; // 1 se for o último caracter da palavra, 0 caso contrário
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
    // nova->final = false; nao eh necessario, pode-se verificar se o no eh um "fim" pelo docklist

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

// MODIFICAR PARA O CASO DE TENTAR INSERIR UMA PALAVRA QUE JA ESTA NA TST
// NESTE CASO, MODIFICAR A DOCKLIST DESTA ARVORE, VALUE EH O DOCUMENTO ATUAL DE ORIGEM DESSA PALAVRA
static TST *rec_insert(TST *t, char *key)
{
    unsigned char c = *key; // se key = "ana\0" -> *key = 'a' (primeiro caracter)

    if (t == NULL)
    {
        t = create_node();
        t->c = c;
    }

    if (c < t->c)
    {
        t->esq = rec_insert(t->esq, key);
    }

    else if (c > t->c)
    {
        t->dir = rec_insert(t->dir, key);
    }

    else if (*(key + 1) != '\0')
    {
        t->meio = rec_insert(t->meio, key + 1);
    }
    else
        t->docs = cria_doclist();

    return t;
}

TST *TST_insert(TST *t, char *key)
{
    return rec_insert(t, key);
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