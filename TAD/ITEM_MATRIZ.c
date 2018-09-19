#include <stdio.h>
#include <stdlib.h>
#include "ITEM_MATRIZ.h"
#include "LISTA_DE_VOOS.h"
#include "../TAD_AUXILIAR/horario.h"
#include "VOO.h"

// Inicializa o TAD ITEM_MATRIZ
int ITEM_MATRIZ_inicializa(ITEM_MATRIZ *ponteiro){
    LISTA_DE_VOOS_criaLista(&(ponteiro->item));
    ponteiro->numVoos=0;
    horario_inicializaHorario(&(ponteiro->ultimaAtualizacao));
    return 0;
}

//Define os valores do TAD ITEM_MATRIZ
int ITEM_MATRIZ_setItemMatriz(ITEM_MATRIZ *ponteiro, LISTA_DE_VOOS *item, horario *ultimaAtualizacao){
    ponteiro->item=*item;
    ponteiro->numVoos=item->numItens;
    ponteiro->ultimaAtualizacao=*ultimaAtualizacao;
    
    return 0;
}

// Definindo o protótipo das funções set. Retornam 0 se der certo.
int ITEM_MATRIZ_LISTA_DE_VOOS_VOO_setHorarioDecolagem(ITEM_MATRIZ *ponteiro, unsigned int vid, horario *horario){
    ITEM_LISTA_DE_VOOS *swapItemMatriz=ponteiro->item.primeiroPtr;
    while(swapItemMatriz->proximo!=NULL && swapItemMatriz->item.VID!=vid){
        swapItemMatriz=swapItemMatriz->proximo;
    }
    VOO_setHorarioDecolagem(&(swapItemMatriz->proximo->item), horario);
	return 0;
}

int ITEM_MATRIZ_LISTA_DE_VOOS_VOO_setHorarioPouso(ITEM_MATRIZ *ponteiro, unsigned int vid, horario *horario){
	return 0;
}

int ITEM_MATRIZ_LISTA_DE_VOOS_VOO_setAeroportoDecolagem(ITEM_MATRIZ *ponteiro, unsigned int vid, char *aeroporto){
	return 0;
}

int ITEM_MATRIZ_LISTA_DE_VOOS_VOO_setAeroportoPouso(ITEM_MATRIZ *ponteiro, unsigned int vid, char *aeroporto){
	return 0;
}

int ITEM_MATRIZ_LISTA_DE_VOOS_VOO_setIdentificadorPistaDecolagem(ITEM_MATRIZ *ponteiro, unsigned int vid, unsigned int identificador){
	return 0;
}

/* Definindo o protótipo das funções get. Retornam o dado caso seja de um tipo
   primitivo, retorna void e permite entrar com um ponteiro para armazenar o
   dado, caso não seja de um tipo primitivo */
unsigned int ITEM_MATRIZ_LISTA_DE_VOOS_VOO_getVID(ITEM_MATRIZ *ponteiro){
	return 0;
}

void ITEM_MATRIZ_LISTA_DE_VOOS_VOO_getHorarioDecolagem(ITEM_MATRIZ *ponteiro, unsigned int vid, horario *horario){

}

void ITEM_MATRIZ_LISTA_DE_VOOS_VOO_getHorarioPouso(ITEM_MATRIZ *ponteiro, unsigned int vid, horario *horario){
	
}


void ITEM_MATRIZ_LISTA_DE_VOOS_VOO_getAeroportoDecolagem(ITEM_MATRIZ *ponteiro, unsigned int vid, char *aeroporto){
	
}


void ITEM_MATRIZ_LISTA_DE_VOOS_VOO_getAeroportoPouso(ITEM_MATRIZ *ponteiro, unsigned int vid, char *aeroporto){
	
}


int ITEM_MATRIZ_LISTA_DE_VOOS_VOO_getIdentificadorPistaDecolagem(ITEM_MATRIZ *ponteiro, unsigned int vid){
	return 0;
}

