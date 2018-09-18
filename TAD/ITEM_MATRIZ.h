#include "LISTA_DE_VOOS.h"
#include "../TAD_AUXILIAR/horario.h"

typedef struct{
    LISTA_DE_VOOS item;
    int numVoos;
    horario ultimaAtualizacao;
} ITEM_MATRIZ;

int ITEM_MATRIZ_inicializa(ITEM_MATRIZ *ponteiro);
int ITEM_MATRIZ_setItemMatriz(ITEM_MATRIZ *ponteiro, LISTA_DE_VOOS *item, horario *ultimaAtualizacao);
