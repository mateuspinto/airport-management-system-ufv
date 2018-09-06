#include <stdlib.h>
#include "LISTA_DE_VOOS.h"

int LISTA_DE_VOOS_criaLista(LISTA_DE_VOOS *ponteiro){
    ponteiro -> primeiroPtr = NULL;
    ponteiro -> ultimoPtr = NULL;
    ponteiro -> numItens = 0;
    return 0;
}

int LISTA_DE_VOOS_insereVoo(LISTA_DE_VOOS *lista, VOO *item){
/*
    horario * horarioComparar = item-> &horarioDecolagem;
    ITEM_LISTAS_DE_VOOS * itemAnalisado = lista -> primeiroPtr ;
    horario * horarioItem;

    horarioItem = horario_getHorarioAbsoluto(itemAnalisado -> proximo -> &horarioDecolagem);

    while(horario_ehFuturo(horarioComparar,horarioItem)){
      itemAnalisado = itemAnalisado -> proximo;
      horarioItem = itemAnalisado -> proximo -> &horarioDecolagem;
    } */
    return 0;
}

int LISTA_DE_VOOS_removeVoo(LISTA_DE_VOOS *lista, unsigned int VID){
    return 0;
}
