#ifndef HORARIO_H_INCLUDED
#define HORARIO_H_INCLUDED

#include <stdlib.h>

typedef struct {
  unsigned int hora;
  unsigned int minutos;
  unsigned int dia;
  unsigned int mes;
  unsigned int ano;
} horario;

int inicializa(horario *ponteiro);

#endif // HOARIO_H_INCLUDED
