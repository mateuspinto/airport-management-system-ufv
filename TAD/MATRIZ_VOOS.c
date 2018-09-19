#include "ITEM_MATRIZ.h"
#include "MATRIZ_VOOS.h"
#include "VOO.h"
#include "LISTA_DE_VOOS.h"
#include <stdlib.h>
#include <stdio.h>
#include "../TAD_AUXILIAR/horario.h"

int MATRIZ_VOOS_inicializa(MATRIZ_VOOS *ponteiro){
    for(int i=0; i<24; i++){
        for(int j=0; j<24; j++){
            ITEM_MATRIZ_inicializa(&(ponteiro->item_matriz[i][j]));
        }
    }
    ponteiro->totalVoos=0;
    horario_inicializa(&(ponteiro->data));

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
                return 0;
            }
        }
    }
    return 1;
}
int MATRIZ_VOOS_getVoo(MATRIZ_VOOS *ponteiro, unsigned int *VID){
    VOO *voo=NULL;
    for(int i=0; i<24; i++){
        for(int j=0; j<24; j++){
            if(LISTA_DE_VOOS_getVoo(&(ponteiro->item_matriz[i][j].item), *VID, voo)==0){
                i=24;
                j=24;
            }
        }
    }
    if(voo!=NULL){
        printf("----------------------------------------------------");
        printf("VID : %d\n", voo->VID);
        printf("Aeroporto de decolagem: %s\n", voo->aeroportoDecolagem);
        printf("Aeroporto de Pouso: %s\n", voo->aeroportoPouso);
        printf("Horário de decolagem: %d : %d\n", voo->horarioDecolagem.hora, voo->horarioDecolagem.min);
        printf("Horário de Pouso: %d : %d\n", voo->horarioPouso.hora, voo->horarioPouso.min);
        printf("Identificador da Pista de Decolagem: %d\n", voo->identificadorPistaDecolagem);
        printf("----------------------------------------------------");

        return 0;
    }
    return 1;
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
            if(ponteiro->item_matriz[i][j].item.numItens>0){
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
    }
    return 0;
}
int MATRIZ_VOOS_showHorarioMaisVoos(MATRIZ_VOOS *ponteiro){
    int m=0;
    int n=0;
    int maiorNumero=0;
    for(int i=0; i<24; i++){
        for(int j=0; j<24; j++){
            if(ponteiro->item_matriz[i][j].numVoos>maiorNumero){
                maiorNumero=ponteiro->item_matriz[i][j].numVoos;
                m=i;
                n=j;
            }
        }
    }
    printf("Linha: %d\n:", m);
    printf("Coluna: %d\n:", n);
    printf("Quantidade de voos: %d\n:", maiorNumero);
    return 0;
}

int MATRIZ_VOOS_showHorarioMenosVoos(MATRIZ_VOOS *ponteiro){
    int m=0;
    int n=0;
    int menorNumero=0;
    for(int i=0; i<24; i++){
        for(int j=0; j<24; j++){
            if(ponteiro->item_matriz[i][j].numVoos<menorNumero){
                menorNumero=ponteiro->item_matriz[i][j].numVoos;
                m=i;
                n=j;
            }
        }
    }
    printf("Linha: %d\n:", m);
    printf("Coluna: %d\n:", n);
    printf("Quantidade de voos: %d\n:", menorNumero);
    return 0;
}

int MATRIZ_VOOS_showListaAlteracaoMaisRecente(MATRIZ_VOOS *ponteiro){
    int m=0;
    int n=0;
    int maiorMinuto=0;
    for(int i=0; i<24; i++){
        for(int j=0; j<24; j++){
            int minutos=60*(ponteiro->item_matriz[i][j].ultimaAtualizacao.hora)+(ponteiro->item_matriz[i][j].ultimaAtualizacao.min);
            if(minutos>maiorMinuto){
                maiorMinuto=minutos;
                m=i;
                n=j;
            }
        }
    }
    printf("Linha: %d\n:", m);
    printf("Coluna: %d\n:", n);
    return 0;
}

int MATRIZ_VOOS_verificarMatrizEsparca(MATRIZ_VOOS *ponteiro){
    int celulasVazia=0;
    int celulasPreenchidas=0;
    for(int i=0; i<24; i++){
        for(int j=0; j<24; j++){
            if(ponteiro->item_matriz[i][j].numVoos!=0){
                celulasPreenchidas+=1;
            }else{
                celulasVazia+=1;
            }
        }
    }
    if(celulasVazia>=(celulasPreenchidas*2)){
        printf("A Matriz é esparça!");
    }else{
        printf("A Matriz não é esparça!");
    }
    
    return 0;
}