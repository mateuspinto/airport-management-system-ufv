#include "horario.h"

int inicializa (horario *ponteiro) {
  ponteiro -> hora = 0;
  ponteiro -> minuto = 0;
  ponteiro -> dia = 0;
  ponteiro -> mes = 0;
  ponteiro -> ano = 0;

  return 0;
}
