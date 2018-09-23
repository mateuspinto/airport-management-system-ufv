// Incluindo bibliotecas necessárias e/ou TADs auxiliares.
#include "horario.h"

int horario_inicializa(horario *ponteiro){
	ponteiro -> hora = 0;
	ponteiro -> min = 0;

  return 0;
}

/* Define se os horarios estao em ordem crescente. Tem como entrada dois
ponteiros para os TADS. Retorna 1 se forem, 0 se não. É uma versao simplfiicada
da horario_compararHorarios */
int horario_ehFuturo(horario *ponteiro1, horario *ponteiro2){
	int horario1, horario2;
	horario1 = 60* ponteiro1-> hora + ponteiro1 -> min;
	horario2 = 60* ponteiro2-> hora + ponteiro2 -> min;
  if(horario1 < horario2){
      return 1;
    } else {
      return 0;
    }
}

/* Preenche o TAD horario com dia, mes e etc. Tem como entrada um ponteiro
para o TAD, int para segundos, int para minutos, int para horas, int para dia,
int para mes e int para ano. Retorna 0 se for bem sucedido */
int horario_setHorario(horario *ponteiro, unsigned int hora, unsigned int min){
    ponteiro -> hora = hora;
    ponteiro -> min = min;

    return 0;
}

void horario_showHorario(horario *ponteiro){
  printf("%d:%d", ponteiro->hora, ponteiro->min);
}