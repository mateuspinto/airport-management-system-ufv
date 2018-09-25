/* Define o TAD e os protótipos das funções caso eles ainda não tenham sido
definidos */
#ifndef MATRIZ_VOOS_H
#define MATRIZ_VOOS_H
// Incluindo bibliotecas padrões necessárias
#include "ITEM_MATRIZ.h"
#include "VOO.h"

// Define a matriz MATRIZ_VOOS
typedef struct{
    ITEM_MATRIZ item_matriz[24][24];
    horario data;
    unsigned int totalVoos;
}MATRIZ_VOOS;

// Inicializa o TAD MATRIZ_VOOS
int MATRIZ_VOOS_inicializa(MATRIZ_VOOS *ponteiro);

// Definindo o protótipo das funções
int MATRIZ_VOOS_setVoo(MATRIZ_VOOS *ponteiro, VOO *voo);
int MATRIZ_VOOS_setData(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_delVoo(MATRIZ_VOOS *ponteiro, unsigned int *VID);
int MATRIZ_VOOS_getVoo(MATRIZ_VOOS *ponteiro, unsigned int *VID);
int MATRIZ_VOOS_showVoosDecolagemPouso(MATRIZ_VOOS *ponteiro, horario *decolagem, horario *pouso);
int MATRIZ_VOOS_showVoosDecolagem(MATRIZ_VOOS *ponteiro, horario *decolagem);
int MATRIZ_VOOS_showVoosPouso(MATRIZ_VOOS *ponteiro, horario *pouso);
int MATRIZ_VOOS_showVoos(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_showHorarioMaisVoos(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_showHorarioMenosVoos(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_showListaAlteracaoMaisRecente(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_showListaAlteracaoMenosRecente(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_verificarMatrizEsparca(MATRIZ_VOOS *ponteiro);
int MATRIZ_VOOS_salvarMatriz(MATRIZ_VOOS *ponteiro, FILE *salvar);

#endif
