#ifndef TST_H
#define TST_H

#include "lista_docs.h"

// OBS: passar structs para o .c depois para a estrutura ficar opaca.

typedef struct TSTNode {
    struct TSTNode *esq;
    struct TSTNode *meio;
    struct TSTNode *dir;
    DocList *docs;
} TSTNode;

#endif