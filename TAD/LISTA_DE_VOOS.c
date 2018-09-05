#include <stdlib.h>
#include "LISTA_DE_VOOS.h"

int LISTA_DE_VOOS_criaLista(LISTA_DE_VOOS *ponteiro){
    ponteiro -> primeiroPtr = NULL;
    ponteiro -> ultimoPtr = NULL;
    ponteiro -> numItens = 0;
    return 0;
}

int LISTA_DE_VOOS_insereVoo(LISTA_DE_VOOS *lista, VOO *item){
    int horarioComparar = horario_getHorarioAbsoluto(item-> &horarioDecolagem);
    ITEM_LISTAS_DE_VOOS * itemAnalisado = lista -> primeiroPtr ;
    int horarioItem;

    horarioItem = horario_getHorarioAbsoluto(itemAnalisado -> ITEM_LISTAS_DE_VOOS -> &horarioDecolagem);

    while(horarioComparar<horarioItem){
      itemAnalisado = itemAnalisado -> proximo;
      horarioItem = horario_getHorarioAbsoluto(itemAnalisado -> ITEM_LISTAS_DE_VOOS -> &horarioDecolagem);
    }
}

int LISTA_DE_VOOS_removeVoo(LISTA_DE_VOO *lista, unsigned int VID);
VOO * LISTA_DE_VOOS_procuraVooVID(LISTA_DE_VOO *lista, unsigned int VID);
