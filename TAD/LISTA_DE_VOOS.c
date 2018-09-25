#include <stdio.h>
#include <stdlib.h>
#include "LISTA_DE_VOOS.h"

//Inicializa o TAD lista de voos
int LISTA_DE_VOOS_criaLista(LISTA_DE_VOOS *ponteiro){
    ponteiro -> primeiroPtr = malloc(sizeof(ITEM_LISTA_DE_VOOS));
    ponteiro -> ultimoPtr = ponteiro -> primeiroPtr ;
    ponteiro -> primeiroPtr -> proximo = NULL;
    ponteiro -> numItens = 0;
    return 0;
}

//Insere um voo numa lista de voos
int LISTA_DE_VOOS_insereVoo(LISTA_DE_VOOS *lista, VOO *itemInserido){
  ITEM_LISTA_DE_VOOS *itemVoo=malloc(sizeof(ITEM_LISTA_DE_VOOS));
  (*itemVoo).item=*itemInserido;
  (*itemVoo).proximo=NULL;
  ITEM_LISTA_DE_VOOS *itemLista=lista->primeiroPtr;

  while((*itemLista).proximo!=NULL && (itemLista->proximo->item.horarioDecolagem.min<=itemVoo->item.horarioDecolagem.min)){
    itemLista=(*itemLista).proximo;
  }
  
  (*itemVoo).proximo=(*itemLista).proximo;
  (*itemLista).proximo=itemVoo;

  return 0;
}
//Remove o voo com o mesmo vid do parâmetro de entrada em uma lista de voos
int LISTA_DE_VOOS_removeVoo(LISTA_DE_VOOS *lista, unsigned int VID){
  ITEM_LISTA_DE_VOOS *swapItemListaVoos=lista->primeiroPtr;
  ITEM_LISTA_DE_VOOS *swapItemListaVoosAnterior=NULL; 
  while(swapItemListaVoos->proximo!=NULL && swapItemListaVoos->item.VID!=VID){
    swapItemListaVoosAnterior=swapItemListaVoos;
    swapItemListaVoos=swapItemListaVoos->proximo;
  }
  if(swapItemListaVoos->item.VID==VID){
    swapItemListaVoosAnterior->proximo=swapItemListaVoos->proximo;
    free(swapItemListaVoos);
    
    return 0;
  }

  return 1;
}

//"Retorna" o voo com o mesmo vid do parâmetro de entrada em uma lista de voos por meio do parâmetro **voo
int LISTA_DE_VOOS_getVoo(LISTA_DE_VOOS *lista, unsigned int VID, VOO **voo){
  ITEM_LISTA_DE_VOOS *swapItemListaVoos=lista->primeiroPtr;
  while(swapItemListaVoos->proximo!=NULL && swapItemListaVoos->item.VID!=VID){
    swapItemListaVoos=swapItemListaVoos->proximo;
  }
  if(swapItemListaVoos->item.VID==VID){
    *voo=&(swapItemListaVoos->item);
    return 0;
  }

  return 1;
}
//Mostra os parâmetros do voo com o mesmo vid do parâmetro de entrada em uma lista de voos
void LISTA_DE_VOOS_showVoo(LISTA_DE_VOOS *lista, unsigned int VID){
  ITEM_LISTA_DE_VOOS *swapItemListaVoos=lista->primeiroPtr;
  while(swapItemListaVoos->proximo!=NULL && swapItemListaVoos->item.VID!=VID){
    swapItemListaVoos=swapItemListaVoos->proximo;
  }
  if(swapItemListaVoos->item.VID==VID){
    VOO_showAeroportoDecolagem(&(swapItemListaVoos->item));
    VOO_showAeroportoPouso(&(swapItemListaVoos->item));
    VOO_showHorarioDecolagem(&(swapItemListaVoos->item));
    VOO_showHorarioPouso(&(swapItemListaVoos->item));
    VOO_showIdentificadorPistaDecolagem(&(swapItemListaVoos->item));
  }
}