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

TST *create_node()
{
    TST *nova = (TST *)calloc(1, sizeof(TST));

    nova->esq = NULL;
    nova->meio = NULL;
    nova->dir = NULL;
    nova->docs = cria_doclist();
    nova->final = false;

    return nova;
}
// key = "ana\0"
// key = key + 1 = "na\0"
// key = key + 1 = "a\0"
// key = "\0"

TST *rec_insert(TST *t, char *key)
{
    unsigned char c = *key; // key[d]
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

    else if (*(key + 1) == '\0')
        t->final = true;
    else
        t->meio = rec_insert(t->meio, key + 1);

    return t;
}

TST *TST_insert(TST *t, char *key)
{
    return rec_insert(t, key);
}