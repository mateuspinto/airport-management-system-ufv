#ifndef VOO_H_INCLUDED
#define VOO_H_INCLUDED

#include <stdlib.h>
#include "../TAD_AUXILIAR/horario.h"

typedef struct {
  unsigned int VID;
  horario horarioDecolagem;
  horario horarioPouso;
  char aeroportoDecolagem[30];
  char aeroportoPouso[30];
  unsigned int identificadorPistaDecolagem;
} VOO;

int VOO_inicializa(VOO *ponteiro);
int VOO_setVID(VOO *ponteiro, unsigned int VID);
int VOO_setHorarioDecolagem(VOO *ponteiro, horario *horario);
int VOO_setHorarioPouso(VOO *ponteiro, horario *horario);
int VOO_setAeroportoDecolagem(VOO *ponteiro, char *aeroporto);
int VOO_setAeroportoPouso(VOO *ponteiro, char *aeroporto);
int VOO_setIdentificadorPistaDecolagem(VOO *ponteiro, unsigned int identificador);

int VOO_getVID(VOO *ponteiro);
void VOO_getHorarioDecolagem(VOO *ponteiro, horario *horario);
void VOO_getHorarioPouso(VOO *ponteiro, horario *horario);
void VOO_getAeroportoDecolagem(VOO *ponteiro, char *aeroporto);
void VOO_getAeroportoPouso(VOO *ponteiro, char *aeroporto);
int VOO_getIdentificadorPistaDecolagem(VOO *ponteiro);


#endif // VOO_H_INCLUDED
