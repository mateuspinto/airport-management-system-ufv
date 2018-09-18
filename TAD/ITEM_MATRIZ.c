#include <stdio.h>
#include <stdlib.h>
#include "ITEM_MATRIZ.h"
#include "LISTA_DE_VOOS.h"
#include "../TAD_AUXILIAR/horario.h"

int ITEM_MATRIZ_inicializa(ITEM_MATRIZ *ponteiro){
    (*ponteiro).numVoos=0;
}


int ITEM_MATRIZ_setItemMatriz(ITEM_MATRIZ *ponteiro, LISTA_DE_VOOS *item, horario *ultimaAtualizacao){
    (*ponteiro).item=*item;
    (*ponteiro).numVoos=(*item).numItens;
    (*ponteiro).ultimaAtualizacao=*ultimaAtualizacao;
}

