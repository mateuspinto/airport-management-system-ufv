/* Define o TAD e os prototipos das funcoes caso eles ainda nao tenham sido
definidos */
#ifndef HORARIO_H_INCLUDED
#define HORARIO_H_INCLUDED

// Incluindo bibliotecas necessárias e/ou TADs auxiliares.
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Definindo struct do TAD e o declarando como um tipo.
typedef struct {
  time_t horarioAbsoluto;
} horario;


long int horario_getHorarioAbsoluto(horario *ponteiro);
int horario_setHorarioAbosluto(horario *ponteiro, long int horario);
int horario_compararHorarios(horario *ponteiro1, horario *ponteiro2);
int horario_ehFuturo(horario *ponteiro1, horario *ponteiro2);
int horario_setHorario(horario *ponteiro, int seg, int min, int hora, int dia,
                      int mes, int ano);
int horario_getHorarioString(horario *ponteiro, char *string);

// Fim do define
#endif // HOARIO_H_INCLUDED
