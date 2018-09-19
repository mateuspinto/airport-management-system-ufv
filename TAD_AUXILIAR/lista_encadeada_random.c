#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada_random.h"

int lista_encadeada_random_criaLista(lista_encadeada_random *ponteiro){
    ponteiro -> primeiroPtr = malloc(sizeof(item_lista_encadeada_random));
    ponteiro -> ultimoPtr = ponteiro -> primeiroPtr ;
    ponteiro -> primeiroPtr -> proximo = NULL;
    return 0;
}

int lista_encadeada_random_insereVID(lista_encadeada_random *lista, unsigned int VID){
    item_lista_encadeada_random *itemRandom=malloc(sizeof(item_lista_encadeada_random));
    (*itemRandom).VID=VID;
    (*itemRandom).proximo=NULL;
    item_lista_encadeada_random *itemLista=lista->primeiroPtr;

    printf("primeiro == %p\n", itemLista);

    while((*itemLista).proximo!=NULL){
      itemLista=(*itemLista).proximo;
    }

    (*itemRandom).proximo=(*itemLista).proximo;
    (*itemLista).proximo=itemRandom;

    printf("ponteiro ==%p\n", itemLista);
    printf("proximo == %p\n", itemLista->proximo);
    return 0;
}

int lista_encadeada_random_removeVID(lista_encadeada_random *lista, unsigned int VID){
    item_lista_encadeada_random *ponteiro = lista -> primeiroPtr ->proximo;
    item_lista_encadeada_random *swap = NULL;

    return 0;
}
