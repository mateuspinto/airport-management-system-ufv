#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "TAD_AUXILIAR/horario.h"
#include "TAD_AUXILIAR/lista_encadeada_random.h"

#include "TAD/VOO.h"
#include "TAD/LISTA_DE_VOOS.h"
#include "TAD/ITEM_MATRIZ.h"
#include "TAD/MATRIZ_VOOS.h"

int main(){
    lista_encadeada_random mateus;
    item_lista_encadeada_random *ponteiro;

    lista_encadeada_random_criaLista(&mateus);

    lista_encadeada_random_insereVID(&mateus, 200);
    lista_encadeada_random_insereVID(&mateus, 2100);
    lista_encadeada_random_insereVID(&mateus, 200);

    ponteiro = mateus.primeiroPtr->proximo;
    while(ponteiro!=NULL){
      printf("%d\n", ponteiro->VID);
      ponteiro = ponteiro->proximo;
    }

    lista_encadeada_random_removeVoo(&mateus, 200);

    ponteiro = mateus.primeiroPtr->proximo;
    while(ponteiro!=NULL){
      printf("%d\n", ponteiro->VID);
      ponteiro = ponteiro->proximo;
    }
    
    system("pause");
    return 0;
}
