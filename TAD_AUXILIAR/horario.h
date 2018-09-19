/* Define o TAD e os prototipos das funcoes caso eles ainda nao tenham sido
definidos */
#ifndef HORARIO_H_INCLUDED
#define HORARIO_H_INCLUDED

// Incluindo bibliotecas necessárias e/ou TADs auxiliares.
#include <stdlib.h>
#include <string.h>

// Definindo struct do TAD e o declarando como um tipo.
typedef struct {
  unsigned int hora;
  unsigned int min;
} horario;

// Prototipos das funções
int horario_inicializaHorario(horario *ponteiro);
int horario_ehFuturo(horario *ponteiro1, horario *ponteiro2);
int horario_setHorario(horario *ponteiro, int min, int hora);

// Fim do define
#endif // HOARIO_H_INCLUDED
