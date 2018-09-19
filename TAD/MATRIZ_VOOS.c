#include "ITEM_MATRIZ.h"
#include "MATRIZ_VOOS.h"
#include "VOO.h"
#include "LISTA_DE_VOOS.h"
#include <stdlib.h>
#include <stdio.h>
#include "../TAD_AUXILIAR/horario.h"

int MATRIZ_VOOS_inicializa(MATRIZ_VOOS *ponteiro){
    ITEM_MATRIZ_inicializa(&(ponteiro->item_matriz));
    ponteiro->totalVoos=0;
    //horario_inicializaHorario(&(ponteiro->data));

    return 0;
}
int MATRIZ_VOOS_setVoo(MATRIZ_VOOS *ponteiro, VOO *voo){
    LISTA_DE_VOOS_insereVoo(&(ponteiro->item_matriz[voo->horarioDecolagem.hora][voo->horarioPouso.hora].item), voo);
    return 0;
}
int MATRIZ_VOOS_delVoo(MATRIZ_VOOS *ponteiro, unsigned int *VID){
    for(int i=0; i<24; i++){
        for(int j=0; j<24; j++){
            if(LISTA_DE_VOOS_removeVoo(&(ponteiro->item_matriz[0][0].item), *VID)==0){
                i=24;
                j=24;
            }
        }
    }
    return 0;
}
int MATRIZ_VOOS_getVoo(MATRIZ_VOOS *ponteiro, unsigned int *VID, VOO *voo){
    for(int i=0; i<24; i++){
        for(int j=0; j<24; j++){
            if(LISTA_DE_VOOS_getVoo(&(ponteiro->item_matriz[0][0].item), *VID, voo)==0){
                i=24;
                j=24;
            }
        }
    }
    return 0;
}
int MATRIZ_VOOS_showVoosDecolagemPouso(MATRIZ_VOOS *ponteiro, horario *decolagem, horario *pouso){
    ITEM_LISTA_DE_VOOS *swapListaDeVoos=ponteiro->item_matriz[decolagem->hora][pouso->hora].item.primeiroPtr;
    printf("----------------------------------------------------");
    while(swapListaDeVoos->proximo!=NULL){
        printf("VID : %d\n", swapListaDeVoos->item.VID);
        printf("Aeroporto de decolagem: %s\n", swapListaDeVoos->item.aeroportoDecolagem);
        printf("Aeroporto de Pouso: %s\n", swapListaDeVoos->item.aeroportoPouso);
        printf("Horário de decolagem: %d : %d\n", swapListaDeVoos->item.horarioDecolagem.hora, swapListaDeVoos->item.horarioDecolagem.min);
        printf("Horário de Pouso: %d : %d\n", swapListaDeVoos->item.horarioPouso.hora, swapListaDeVoos->item.horarioPouso.min);
        printf("Identificador da Pista de Decolagem: %d\n", swapListaDeVoos->item.identificadorPistaDecolagem);
        printf("----------------------------------------------------");
        swapListaDeVoos=swapListaDeVoos->proximo;
    }
    return 0;
}
int MATRIZ_VOOS_showVoosDecolagem(MATRIZ_VOOS *ponteiro, horario *decolagem){
    for(int i=0; i<24; i++){
        ITEM_LISTA_DE_VOOS *swapListaDeVoos=ponteiro->item_matriz[decolagem->hora][i].item.primeiroPtr;
        printf("----------------------------------------------------");
        while(swapListaDeVoos->proximo!=NULL){
            printf("VID : %d\n", swapListaDeVoos->item.VID);
            printf("Aeroporto de decolagem: %s\n", swapListaDeVoos->item.aeroportoDecolagem);
            printf("Aeroporto de Pouso: %s\n", swapListaDeVoos->item.aeroportoPouso);
            printf("Horário de decolagem: %d : %d\n", swapListaDeVoos->item.horarioDecolagem.hora, swapListaDeVoos->item.horarioDecolagem.min);
            printf("Horário de Pouso: %d : %d\n", swapListaDeVoos->item.horarioPouso.hora, swapListaDeVoos->item.horarioPouso.min);
            printf("Identificador da Pista de Decolagem: %d\n", swapListaDeVoos->item.identificadorPistaDecolagem);
            printf("----------------------------------------------------");
            swapListaDeVoos=swapListaDeVoos->proximo;
        }
    }
    return 0;
}
int MATRIZ_VOOS_showVoosPouso(MATRIZ_VOOS *ponteiro, horario *pouso){
    printf("----------------------------------------------------");
    for(int i=0; i<24; i++){
        ITEM_LISTA_DE_VOOS *swapListaDeVoos=ponteiro->item_matriz[i][pouso->hora].item.primeiroPtr;
        while(swapListaDeVoos->proximo!=NULL){
            printf("VID : %d\n", swapListaDeVoos->item.VID);
            printf("Aeroporto de decolagem: %s\n", swapListaDeVoos->item.aeroportoDecolagem);
            printf("Aeroporto de Pouso: %s\n", swapListaDeVoos->item.aeroportoPouso);
            printf("Horário de decolagem: %d : %d\n", swapListaDeVoos->item.horarioDecolagem.hora, swapListaDeVoos->item.horarioDecolagem.min);
            printf("Horário de Pouso: %d : %d\n", swapListaDeVoos->item.horarioPouso.hora, swapListaDeVoos->item.horarioPouso.min);
            printf("Identificador da Pista de Decolagem: %d\n", swapListaDeVoos->item.identificadorPistaDecolagem);
            printf("----------------------------------------------------");
            swapListaDeVoos=swapListaDeVoos->proximo;
        }
    }
    return 0;
}
int MATRIZ_VOOS_showVoos(MATRIZ_VOOS *ponteiro){
    printf("----------------------------------------------------");
    for(int i=0; i<24; i++){
        for(int j=0; j<24; j++){
            ITEM_LISTA_DE_VOOS *swapListaDeVoos=ponteiro->item_matriz[i][j].item.primeiroPtr;
            while(swapListaDeVoos->proximo!=NULL){
                printf("VID : %d\n", swapListaDeVoos->item.VID);
                printf("Aeroporto de decolagem: %s\n", swapListaDeVoos->item.aeroportoDecolagem);
                printf("Aeroporto de Pouso: %s\n", swapListaDeVoos->item.aeroportoPouso);
                printf("Horário de decolagem: %d : %d\n", swapListaDeVoos->item.horarioDecolagem.hora, swapListaDeVoos->item.horarioDecolagem.min);
                printf("Horário de Pouso: %d : %d\n", swapListaDeVoos->item.horarioPouso.hora, swapListaDeVoos->item.horarioPouso.min);
                printf("Identificador da Pista de Decolagem: %d\n", swapListaDeVoos->item.identificadorPistaDecolagem);
                printf("----------------------------------------------------");
                swapListaDeVoos=swapListaDeVoos->proximo;
            }
        }
    }
    return 0;
}
int MATRIZ_VOOS_showHorarioMaisVoos(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_showHorarioMenosVoos(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_showListaAlteracaoMaisRecente(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_verificarMatrizEsparca(MATRIZ_VOOS *ponteiro);