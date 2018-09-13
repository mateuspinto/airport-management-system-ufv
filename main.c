#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TAD/LISTA_DE_VOOS.h"

int main(){
    LISTA_DE_VOOS mateus;
    VOO joao, joander;
    ITEM_LISTA_DE_VOOS *ponteiro = NULL;
    unsigned int vid;



    LISTA_DE_VOOS_criaLista(&mateus);

    ponteiro = mateus.primeiroPtr;

    VOO_inicializa(&joao);
    VOO_inicializa(&joander);

    VOO_setVID(&joao, 599);
    VOO_setVID(&joander, 399);

    LISTA_DE_VOOS_insereVoo(&mateus, &joao);
    LISTA_DE_VOOS_insereVoo(&mateus, &joander);
    LISTA_DE_VOOS_insereVoo(&mateus, &joao);

    while((*ponteiro).proximo!=NULL){
      ponteiro=(*ponteiro).proximo;
      vid = VOO_getVID(&(ponteiro->item));
      printf("BOCETA %d\n", vid);
    }
}
