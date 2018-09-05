//
// Created by vburi on 05/09/2018.
//

#ifndef XAERO_TP1AEDS_LISTA_VOO_H
#define XAERO_TP1AEDS_LISTA_VOO_H

#include "VOO.h"

typedef struct ITEM_LISTAS_DE_VOOS {
    VOO item;
    struct ITEM_LISTAS_DE_VOOS *proximoPtr;
} ITEM_LISTAS_DE_VOOS;

typedef struct {
    ITEM_LISTAS_DE_VOOS *primeiroPtr;
    ITEM_LISTAS_DE_VOOS *ultimoPtr;
    unsigned int numItens;
} LISTA_DE_VOOS;

int LISTA_DE_VOOS_criaLista(LISTA_DE_VOOS *ponteiro);


#endif //XAERO_TP1AEDS_LISTA_VOO_H
