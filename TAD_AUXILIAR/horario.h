#ifndef HORARIO_H_INCLUDED
#define HORARIO_H_INCLUDED

#include <stdlib.h>

typedef struct {
  unsigned short hora;
  unsigned short minuto;
  unsigned short dia;
  unsigned short mes;
  unsigned short ano;

} horario;


int horario_inicializa(horario *ponteiro);
int horario_setHora(horario *ponteiro, unsigned short hora);
int horario_setMinuto(horario *ponteiro, unsigned short minuto);
int horario_setDia(horario *ponteiro, unsigned short dia);
int horario_setHora(horario *ponteiro, unsigned short hora);
int horario_setHora(horario *ponteiro, unsigned short hora);

int horario_setHora(horario *ponteiro, int hora);
int horario_setHora(horario *ponteiro, int hora);
int horario_setHora(horario *ponteiro, int hora);
int horario_setHora(horario *ponteiro, int hora);
int horario_setHora(horario *ponteiro, int hora);

#endif // HOARIO_H_INCLUDED
