#include <stdio.h>
#include <stdlib.h>
#include "LISTA_DE_VOOS.h"
#include "../TAD_AUXILIAR/horario.h"
#include "VOO.h"
#include "ITEM_MATRIZ.h"

// Inicializa o TAD ITEM_MATRIZ
int ITEM_MATRIZ_inicializa(ITEM_MATRIZ *ponteiro){
    LISTA_DE_VOOS_criaLista(&(ponteiro->item));
    ponteiro->numVoos=0;
    horario_inicializa(&(ponteiro->ultimaAtualizacao));
    return 0;
}

//Define os valores do TAD ITEM_MATRIZ
int ITEM_MATRIZ_setItemMatriz(ITEM_MATRIZ *ponteiro, LISTA_DE_VOOS *item, horario *ultimaAtualizacao){
    ponteiro->item=*item;
    ponteiro->numVoos+=item->numItens;
    ponteiro->ultimaAtualizacao=*ultimaAtualizacao;
    
    return 0;
}

// Definindo o horário de decolagem do Voo
int ITEM_MATRIZ_LISTA_DE_VOOS_VOO_setHorarioDecolagem(ITEM_MATRIZ *ponteiro, unsigned int vid, horario *horario){
    ITEM_LISTA_DE_VOOS *swapItemMatriz=ponteiro->item.primeiroPtr;
    while(swapItemMatriz->proximo!=NULL && swapItemMatriz->item.VID!=vid){
        swapItemMatriz=swapItemMatriz->proximo;
    }
    if(swapItemMatriz->item.VID==vid){
        VOO_setHorarioDecolagem(&(swapItemMatriz->proximo->item), horario);
        return 0;
    }
    
	return 1;
}

//Define o horário de pouso do voo
int ITEM_MATRIZ_LISTA_DE_VOOS_VOO_setHorarioPouso(ITEM_MATRIZ *ponteiro, unsigned int vid, horario *horario){
    ITEM_LISTA_DE_VOOS *swapItemMatriz=ponteiro->item.primeiroPtr;
    while(swapItemMatriz->proximo!=NULL && swapItemMatriz->item.VID!=vid){
        swapItemMatriz=swapItemMatriz->proximo;
    }
    if(swapItemMatriz->item.VID==vid){
        VOO_setHorarioPouso(&(swapItemMatriz->proximo->item), horario);
        return 0;
    }

	return 1;
}

//Define o aeroporto de decolagem do voo
int ITEM_MATRIZ_LISTA_DE_VOOS_VOO_setAeroportoDecolagem(ITEM_MATRIZ *ponteiro, unsigned int vid, char *aeroporto){
	ITEM_LISTA_DE_VOOS *swapItemMatriz=ponteiro->item.primeiroPtr;
    while(swapItemMatriz->proximo!=NULL && swapItemMatriz->item.VID!=vid){
        swapItemMatriz=swapItemMatriz->proximo;
    }
    if(swapItemMatriz->item.VID==vid){
        VOO_setAeroportoDecolagem(&(swapItemMatriz->proximo->item), aeroporto);
        return 0;
    }

	return 1;
}

//Define o aerporpoto de pouso do voo
int ITEM_MATRIZ_LISTA_DE_VOOS_VOO_setAeroportoPouso(ITEM_MATRIZ *ponteiro, unsigned int vid, char *aeroporto){
	ITEM_LISTA_DE_VOOS *swapItemMatriz=ponteiro->item.primeiroPtr;
    while(swapItemMatriz->proximo!=NULL && swapItemMatriz->item.VID!=vid){
        swapItemMatriz=swapItemMatriz->proximo;
    }
    if(swapItemMatriz->item.VID==vid){
        VOO_setAeroportoPouso(&(swapItemMatriz->proximo->item), aeroporto);
        return 0;
    }

	return 1;
}

//Define o identificador da pista de decolagem do voo
int ITEM_MATRIZ_LISTA_DE_VOOS_VOO_setIdentificadorPistaDecolagem(ITEM_MATRIZ *ponteiro, unsigned int vid, unsigned int identificador){
	ITEM_LISTA_DE_VOOS *swapItemMatriz=ponteiro->item.primeiroPtr;
    while(swapItemMatriz->proximo!=NULL && swapItemMatriz->item.VID!=vid){
        swapItemMatriz=swapItemMatriz->proximo;
    }
    if(swapItemMatriz->item.VID==vid){
        VOO_setIdentificadorPistaDecolagem(&(swapItemMatriz->proximo->item), identificador);
        return 0;
    }

	return 1;
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

// void ITEM_MATRIZ_LISTA_DE_VOOS_VOO_showVID(ITEM_MATRIZ *ponteiro){

// }

//Mostra o horário de decolagem do voo
void ITEM_MATRIZ_LISTA_DE_VOOS_VOO_showHorarioDecolagem(ITEM_MATRIZ *ponteiro, unsigned int vid){
    ITEM_LISTA_DE_VOOS *swapItemListaVoos=ponteiro->item.primeiroPtr;
    while(swapItemListaVoos->proximo!=NULL && swapItemListaVoos->item.VID!=vid){
        swapItemListaVoos=swapItemListaVoos->proximo;
    }

    if(swapItemListaVoos->item.VID==vid){
        VOO_showHorarioDecolagem(&(swapItemListaVoos->item));
    }
}

//Mostra o horario de pouso do voo
void ITEM_MATRIZ_LISTA_DE_VOOS_VOO_showHorarioPouso(ITEM_MATRIZ *ponteiro, unsigned int vid){
    ITEM_LISTA_DE_VOOS *swapItemListaVoos=ponteiro->item.primeiroPtr;
    while(swapItemListaVoos->proximo!=NULL && swapItemListaVoos->item.VID!=vid){
        swapItemListaVoos=swapItemListaVoos->proximo;
    }

    if(swapItemListaVoos->item.VID==vid){
        VOO_showAeroportoPouso(&(swapItemListaVoos->item));
    }
}

//Mostra o aeroporto de decolagem do voo
void ITEM_MATRIZ_LISTA_DE_VOOS_VOO_showAeroportoDecolagem(ITEM_MATRIZ *ponteiro, unsigned int vid){
    ITEM_LISTA_DE_VOOS *swapItemListaVoos=ponteiro->item.primeiroPtr;
    while(swapItemListaVoos->proximo!=NULL && swapItemListaVoos->item.VID!=vid){
        swapItemListaVoos=swapItemListaVoos->proximo;
    }

    if(swapItemListaVoos->item.VID==vid){
        VOO_showAeroportoDecolagem(&(swapItemListaVoos->item));
    }
}

//Mostra o aeroporto de pouso do voo
void ITEM_MATRIZ_LISTA_DE_VOOS_VOO_showAeroportoPouso(ITEM_MATRIZ *ponteiro, unsigned int vid){
    ITEM_LISTA_DE_VOOS *swapItemListaVoos=ponteiro->item.primeiroPtr;
    while(swapItemListaVoos->proximo!=NULL && swapItemListaVoos->item.VID!=vid){
        swapItemListaVoos=swapItemListaVoos->proximo;
    }

    if(swapItemListaVoos->item.VID==vid){
        VOO_showAeroportoPouso(&(swapItemListaVoos->item));
    }
}

//Mostra o identificador da pista de decolagem do voo
void ITEM_MATRIZ_LISTA_DE_VOOS_VOO_showIdentificadorPistaDecolagem(ITEM_MATRIZ *ponteiro, unsigned int vid){
    ITEM_LISTA_DE_VOOS *swapItemListaVoos=ponteiro->item.primeiroPtr;
    while(swapItemListaVoos->proximo!=NULL && swapItemListaVoos->item.VID!=vid){
        swapItemListaVoos=swapItemListaVoos->proximo;
    }

    if(swapItemListaVoos->item.VID==vid){
        VOO_showIdentificadorPistaDecolagem(&(swapItemListaVoos->item));
    }
}

//Mostra todos os parâmetros do voo
void ITEM_MATRIZ_LISTA_DE_VOOS_VOO_showVoo(ITEM_MATRIZ *ponteiro, unsigned int vid){
    ITEM_LISTA_DE_VOOS *swapListaDeVoos=ponteiro->item.primeiroPtr;
    do{
        swapListaDeVoos=swapListaDeVoos->proximo;
        if(swapListaDeVoos->item.VID==vid){
            VOO_showVoo(&(swapListaDeVoos->item));
        }
        printf("----------------------------------------------------\n");
    }while(swapListaDeVoos->proximo!=NULL);
}
