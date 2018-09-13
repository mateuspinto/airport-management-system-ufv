#include <stdio.h>
#include <stdlib.h>
#include "LISTA_DE_VOOS.h"

int LISTA_DE_VOOS_criaLista(LISTA_DE_VOOS *ponteiro){
    ponteiro -> primeiroPtr = malloc(sizeof(ITEM_LISTA_DE_VOOS));
    ponteiro -> ultimoPtr = ponteiro -> primeiroPtr ;
    ponteiro -> primeiroPtr -> proximo = NULL;
    ponteiro -> numItens = 0;
    return 0;
}

int LISTA_DE_VOOS_insereVoo(LISTA_DE_VOOS *lista, VOO *itemInserido){

  

}

int LISTA_DE_VOOS_removeVoo(LISTA_DE_VOOS *lista, unsigned int VID){
    return 0;
}
