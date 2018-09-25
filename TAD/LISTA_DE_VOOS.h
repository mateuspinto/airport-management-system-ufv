/* Define o TAD e os protótipos das funções caso eles ainda não tenham sido
definidos */
#ifndef LISTA_VOO_H
#define LISTA_VOO_H
// Incluindo bibliotecas padrões necessárias
#include "VOO.h"

// Define o tipo ITEM_LISTA_DE_VOOS e a própria LISTA_DE_VOOS
typedef struct ITEM_LISTA_DE_VOOS {
    VOO item;
    struct ITEM_LISTA_DE_VOOS *proximo;
} ITEM_LISTA_DE_VOOS;

typedef struct {
    ITEM_LISTA_DE_VOOS *primeiroPtr;
    ITEM_LISTA_DE_VOOS *ultimoPtr;
    unsigned int numItens;
} LISTA_DE_VOOS;

// Define o protótipo das funções de operações que serão realizadas na lista
int LISTA_DE_VOOS_criaLista(LISTA_DE_VOOS *ponteiro);
int LISTA_DE_VOOS_insereVoo(LISTA_DE_VOOS *lista, VOO *item);
int LISTA_DE_VOOS_removeVoo(LISTA_DE_VOOS *lista, unsigned int VID);
int LISTA_DE_VOOS_getVoo(LISTA_DE_VOOS *lista, unsigned int VID, VOO **voo);
void LISTA_DE_VOOS_showVoo(LISTA_DE_VOOS *lista, unsigned int VID);


#endif //LISTA_VOO_H
