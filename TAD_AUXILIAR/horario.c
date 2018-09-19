// Incluindo bibliotecas necessárias e/ou TADs auxiliares.
#include "horario.h"
#include <string.h>

/* Retorna um long int que define o horario. Tem como entrada um ponteiro para
o TAD. Retorna o long int se for bem sucedido. */
long int horario_getHorarioAbsoluto(horario *ponteiro){
    return ponteiro -> horarioAbsoluto;
}

/* Define o horario a partir do horario absoluto. Tem como entrada um ponteiro
para o TAD e um long int do horario absoluto. Retorna 0 se for bem sucedido. */
int horario_setHorarioAbosluto(horario *ponteiro, long int horario){
    ponteiro -> horarioAbsoluto = horario;
    return 0;
}

/* Define se os horarios sao iguais, futuro ou passado. Tem como entrada dois
ponteiros para os TADs. Retorna 1 se o primeiro for passado, -1 o contrario e
0 se forem iguais. */
int horario_compararHorarios(horario *ponteiro1, horario *ponteiro2){
    if((ponteiro1 -> horarioAbsoluto) < (ponteiro2 -> horarioAbsoluto)){
        return 1;
    } else if((ponteiro1 -> horarioAbsoluto) == (ponteiro2 -> horarioAbsoluto)){
        return 0;
    } else {
        return -1;
    }
}

/* Define se os horarios estao em ordem crescente. Tem como entrada dois
ponteiros para os TADS. Retorna 1 se forem, 0 se não. É uma versao simplfiicada
da horario_compararHorarios */
int horario_ehFuturo(horario *ponteiro1, horario *ponteiro2){
  if((horario_getHorarioAbsoluto(ponteiro1)) < (horario_getHorarioAbsoluto(ponteiro2))){
      return 1;
    } else {
      return 0;
    }
}

/* Preenche o TAD horario com dia, mes e etc. Tem como entrada um ponteiro
para o TAD, int para segundos, int para minutos, int para horas, int para dia,
int para mes e int para ano. Retorna 0 se for bem sucedido */
int horario_setHorario(horario *ponteiro, int seg, int min, int hora, int dia,
                      int mes, int ano){
    struct tm swap;
    swap.tm_sec = seg;
    swap.tm_min = min;
    swap.tm_hour = hora;
    swap.tm_mday = dia;
    swap.tm_mon = mes;
    swap.tm_year = ano;
    ponteiro -> horarioAbsoluto = mktime(&swap);

    return 0;
}

/* Retorna um string com o horario formatado. Tem como entrada um ponteiro
para o TAD e um ponteiro para char que armazenará o resultado */
void horario_getHorarioString(horario *ponteiro, char *string){
    struct tm swap;
    char *stringswap;

    gmtime_r(&(ponteiro-> horarioAbsoluto), &swap);
    stringswap = asctime(&swap);

    strcpy(string, stringswap);
}
