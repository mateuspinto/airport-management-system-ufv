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
  ITEM_LISTA_DE_VOOS *itemVoo=malloc(sizeof(ITEM_LISTA_DE_VOOS));
  (*itemVoo).item=*itemInserido;
  (*itemVoo).proximo=NULL;
  ITEM_LISTA_DE_VOOS *itemLista=lista->primeiroPtr;

  printf("primeiro == %p\n", itemLista);

  while((*itemLista).proximo!=NULL){
    itemLista=(*itemLista).proximo;
  }

  (*itemVoo).proximo=(*itemLista).proximo;
  (*itemLista).proximo=itemVoo;

  printf("ponteiro ==%p\n", itemLista);
  printf("proximo == %p\n", itemLista->proximo);

  return 0;
}

int LISTA_DE_VOOS_removeVoo(LISTA_DE_VOOS *lista, unsigned int VID){
    return 0;
}

int LISTA_DE_VOOS_getVoo(LISTA_DE_VOOS *lista, unsigned int VID, VOO *voo){
  return 0;
}
