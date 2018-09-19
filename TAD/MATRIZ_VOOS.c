#include "ITEM_MATRIZ.h"
#include "MATRIZ_VOOS.h"
#include "VOO.h"
#include "LISTA_DE_VOOS.h"
#include <stdlib.h>
#include "../TAD_AUXILIAR/horario.h"

int MATRIZ_VOOS_inicializa(MATRIZ_VOOS *ponteiro){
    ITEM_MATRIZ_inicializa(&(ponteiro->item_matriz));
    ponteiro->totalVoos=0;
    //horario_inicializaHorario(&(ponteiro->data));

    return 0;
}
int MATRIZ_VOOS_setVoo(MATRIZ_VOOS *ponteiro, VOO *voo){
    LISTA_DE_VOOS_insereVoo(&(ponteiro->item_matriz[voo->horarioDecolagem][voo->horarioPouso].item), voo);
    return 0;
}
int MATRIZ_VOOS_delVoo(MATRIZ_VOOS *ponteiro, unsigned int *VID){
    
}
int MATRIZ_VOOS_getVoo(MATRIZ_VOOS *ponteiro, unsigned int *VID);
int MATRIZ_VOOS_showVoosDecolagemPouso(MATRIZ_VOOS *ponteiro, horario *decolagem, horario *pouso);
int MATRIZ_VOOS_showVoosDecolagem(MATRIZ_VOOS *ponteiro, horario *decolagem);
int MATRIZ_VOOS_showVoosPouso(MATRIZ_VOOS *ponteiro, horario *pouso);
int MATRIZ_VOOS_showVoos(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_showHorarioMaisVoos(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_showHorarioMenosVoos(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_showListaAlteracaoMaisRecente(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_verificarMatrizEsparca(MATRIZ_VOOS *ponteiro);