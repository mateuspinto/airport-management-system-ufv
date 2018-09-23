#include "ITEM_MATRIZ.h"
#include "VOO.h"

typedef struct{
    ITEM_MATRIZ item_matriz[24][24];
    horario data;
    unsigned int totalVoos;
}MATRIZ_VOOS;

int MATRIZ_VOOS_inicializa(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_setVoo(MATRIZ_VOOS *ponteiro, VOO *voo);
int MATRIZ_VOOS_delVoo(MATRIZ_VOOS *ponteiro, unsigned int *VID);
int MATRIZ_VOOS_showVoo(MATRIZ_VOOS *ponteiro, unsigned int *VID);
int MATRIZ_VOOS_showVoosDecolagemPouso(MATRIZ_VOOS *ponteiro, horario *decolagem, horario *pouso);
int MATRIZ_VOOS_showVoosDecolagem(MATRIZ_VOOS *ponteiro, horario *decolagem);
int MATRIZ_VOOS_showVoosPouso(MATRIZ_VOOS *ponteiro, horario *pouso);
int MATRIZ_VOOS_showVoos(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_showHorarioMaisVoos(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_showHorarioMenosVoos(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_showListaAlteracaoMaisRecente(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_verificarMatrizEsparca(MATRIZ_VOOS *ponteiro);