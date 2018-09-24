// Incluindo header do TAD e/ou bibliotecas necessárias
#include "ITEM_MATRIZ.h"
#include "MATRIZ_VOOS.h"
#include "VOO.h"
#include "LISTA_DE_VOOS.h"
#include <stdlib.h>
#include <stdio.h>
#include "../TAD_AUXILIAR/horario.h"

//Inicializa a matriz de voos
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

//Insere e printa um voo na matriz dado endereco da matriz e do voo
int MATRIZ_VOOS_setVoo(MATRIZ_VOOS *ponteiro, VOO *voo){
    VOO_showVoo(voo);
    ponteiro->item_matriz[voo->horarioDecolagem.hora][voo->horarioPouso.hora].item.numItens+=1;
    ponteiro->item_matriz[voo->horarioDecolagem.hora][voo->horarioPouso.hora].numVoos+=1;
    ponteiro->totalVoos+=1;
    LISTA_DE_VOOS_insereVoo(&(ponteiro->item_matriz[voo->horarioDecolagem.hora][voo->horarioPouso.hora].item), voo);
    return 0;
}

//Remove um voo na matriz dado endereco da matriz e do voo
int MATRIZ_VOOS_delVoo(MATRIZ_VOOS *ponteiro, unsigned int *VID){
    for(int i=0; i<24; i++){
        for(int j=0; j<24; j++){
            if(LISTA_DE_VOOS_removeVoo(&(ponteiro->item_matriz[i][j].item), *VID)==0){
                ponteiro->item_matriz[i][j].item.numItens-=1;
                i=24;
                j=24;
                return 0;
            }
        }
    }
    return 1;
}

//Mostra um VOO dado endereco da matriz e o endereco do VID dele
int MATRIZ_VOOS_getVoo(MATRIZ_VOOS *ponteiro, unsigned int *VID){
    printf("----------------------------------------------------\n");
    for(int i=0; i<24; i++){
        for(int j=0; j<24; j++){
            if(ponteiro->item_matriz[i][j].item.numItens>0){
                ITEM_MATRIZ_LISTA_DE_VOOS_VOO_showVoo(&(ponteiro->item_matriz[i][j]), *VID);
            }
        }
    }
    return 0;
}

//Mostra VOOs dado o endereco da matriz e o endereco de um horario de decolagem e de pouso deles
int MATRIZ_VOOS_showVoosDecolagemPouso(MATRIZ_VOOS *ponteiro, horario *decolagem, horario *pouso){
    printf("----------------------------------------------------\n");
    if(ponteiro->item_matriz[decolagem->hora][pouso->hora].item.numItens>0){
        ITEM_LISTA_DE_VOOS *swapListaDeVoos=ponteiro->item_matriz[decolagem->hora][pouso->hora].item.primeiroPtr;
        do{
            swapListaDeVoos=swapListaDeVoos->proximo;
            VOO_showVoo(&(swapListaDeVoos->item));
            printf("----------------------------------------------------\n");
        }while(swapListaDeVoos->proximo!=NULL);
    }
    return 0;
}

//Mostra VOOs dado o endereco da matriz e o endereco de um horario de decolagem
int MATRIZ_VOOS_showVoosDecolagem(MATRIZ_VOOS *ponteiro, horario *decolagem){
  for(int i=0; i<24; i++){
      if(ponteiro->item_matriz[decolagem->hora][i].numVoos>0){
        ITEM_LISTA_DE_VOOS *swapListaDeVoos=ponteiro->item_matriz[decolagem->hora][i].item.primeiroPtr;
        do{
            swapListaDeVoos=swapListaDeVoos->proximo;
            VOO_showVoo(&(swapListaDeVoos->item));
            printf("----------------------------------------------------\n");
        }while(swapListaDeVoos->proximo!=NULL);
      }
  }
  return 0;
}

//Mostra VOOs dado o endereco da matriz e o endereco de um horario de pouso deles
int MATRIZ_VOOS_showVoosPouso(MATRIZ_VOOS *ponteiro, horario *pouso){
    for(int i=0; i<24; i++){
        if(ponteiro->item_matriz[i][pouso->hora].numVoos>0){
          ITEM_LISTA_DE_VOOS *swapListaDeVoos=ponteiro->item_matriz[i][pouso->hora].item.primeiroPtr;
          do{
              swapListaDeVoos=swapListaDeVoos->proximo;
              VOO_showVoo(&(swapListaDeVoos->item));
              printf("----------------------------------------------------\n");
          }while(swapListaDeVoos->proximo!=NULL);
        }
    }
    return 0;
}

//Mostra todos os VOOS da matriz
int MATRIZ_VOOS_showVoos(MATRIZ_VOOS *ponteiro){
    printf("----------------------------------------------------\n");
    for(int i=0; i<24; i++){
        for(int j=0; j<24; j++){
            if(ponteiro->item_matriz[i][j].item.numItens>0){
                ITEM_LISTA_DE_VOOS *swapListaDeVoos=ponteiro->item_matriz[i][j].item.primeiroPtr;
                do{
                    swapListaDeVoos=swapListaDeVoos->proximo;
                    VOO_showVoo(&(swapListaDeVoos->item));
                    printf("----------------------------------------------------\n");
                }while(swapListaDeVoos->proximo!=NULL);
            }
        }
    }
    return 0;
}

//Mostra os indices da matriz com o maior numero de VOOs
int MATRIZ_VOOS_showHorarioMaisVoos(MATRIZ_VOOS *ponteiro){
    int m=0;
    int n=0;
    int maiorNumero=ponteiro->item_matriz[0][0].numVoos;
    for(int i=0; i<24; i++){
        for(int j=0; j<24; j++){
            if(ponteiro->item_matriz[i][j].numVoos>maiorNumero){
                maiorNumero=ponteiro->item_matriz[i][j].numVoos;
                m=i;
                n=j;
            }
        }
    }
    printf("\nLinha: %d\n", m);
    printf("Coluna: %d\n", n);
    printf("Quantidade de voos: %d\n", maiorNumero);
    return 0;
}

//Mostra os indices da matriz com o menor numero de VOOs
int MATRIZ_VOOS_showHorarioMenosVoos(MATRIZ_VOOS *ponteiro){
    int m=0;
    int n=0;
    int menorNumero=ponteiro->item_matriz[0][0].numVoos;
    for(int i=0; i<24; i++){
        for(int j=0; j<24; j++){
            if(ponteiro->item_matriz[i][j].numVoos<menorNumero){
                menorNumero=ponteiro->item_matriz[i][j].numVoos;
                m=i;
                n=j;
            }
        }
    }
    printf("\nLinha: %d\n", m);
    printf("Coluna: %d\n", n);
    printf("Quantidade de voos: %d\n", menorNumero);
    return 0;
}

//Mostra os indices da matriz com a alteração mais recente
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

//Mostra se a matriz é esparça
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
        printf("");
        printf("########################################################################################################\n");
		printf("#                                          A Matriz e esparca!                                         #\n");
		printf("########################################################################################################\n");
    }else{
        printf("########################################################################################################\n");
		printf("#                                        A Matriz nao e esparca!                                       #\n");
		printf("########################################################################################################\n");
    }

    return 0;
}
int MATRIZ_VOOS_salvarMatriz(MATRIZ_VOOS *ponteiro, FILE *salvar){
  unsigned int vid, horaDeco, minDeco, horaPouso, minPouso, pista;
  char aeroDeco[30], aeroPouso[30];
  fprintf(salvar, "a\n");
  for(int i=0; i<24; i++){
      for(int j=0; j<24; j++){
          if(ponteiro->item_matriz[i][j].item.numItens>0){
              ITEM_LISTA_DE_VOOS *swapListaDeVoos=ponteiro->item_matriz[i][j].item.primeiroPtr;
              do{
                  swapListaDeVoos=swapListaDeVoos->proximo;
                  vid = VOO_getVID(&(swapListaDeVoos->item));
                  VOO_getAeroportoDecolagem(&(swapListaDeVoos->item), aeroDeco);
                  VOO_getAeroportoPouso(&(swapListaDeVoos->item), aeroPouso);
                  horaDeco = (swapListaDeVoos->item).horarioDecolagem.hora;
                  minDeco = (swapListaDeVoos->item).horarioDecolagem.min;
                  horaPouso = (swapListaDeVoos->item).horarioPouso.hora;
                  minPouso = (swapListaDeVoos->item).horarioPouso.min;
                  pista = VOO_getIdentificadorPistaDecolagem(&(swapListaDeVoos->item));
                  fprintf(salvar, "b %02d:%02d %02d:%02d %s %s %d\n", horaDeco, minDeco, horaPouso, minPouso, aeroDeco, aeroPouso, pista);
                  } while(swapListaDeVoos->proximo!=NULL);
          }
      }
  }
  return 0;
}
