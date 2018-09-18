#include <stdio.h>
#include <stdlib.h>
#include "ITEM_MATRIZ.h"
#include "LISTA_DE_VOOS.h"
#include "../TAD_AUXILIAR/horario.h"


// Inicializa o TAD ITEM_MATRIZ
int ITEM_MATRIZ_inicializa(ITEM_MATRIZ *ponteiro){
    LISTA_DE_VOOS_criaLista(&(ponteiro->item));
    ponteiro->numVoos=0;
    //criar função zera horario
    return 0;
}

//Define os valores do TAD ITEM_MATRIZ
int ITEM_MATRIZ_setItemMatriz(ITEM_MATRIZ *ponteiro, LISTA_DE_VOOS *item, horario *ultimaAtualizacao){
    ponteiro->item=*item;
    ponteiro->numVoos=item->numItens;
    ponteiro->ultimaAtualizacao=*ultimaAtualizacao;
    return 0;
}

