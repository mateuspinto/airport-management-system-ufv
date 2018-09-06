#include "horario.h"
#include <string.h>

long int horario_getHorarioAbsoluto(horario *ponteiro){
    return ponteiro -> horarioAbsoluto;
}

int horario_setHorarioAbosluto(horario *ponteiro, long int horario){
    ponteiro -> horarioAbsoluto = horario;
    return 0;
}

int horario_compararHorarios(horario *ponteiro1, horario *ponteiro2){
    if((ponteiro1 -> horarioAbsoluto) < (ponteiro2 -> horarioAbsoluto)){
        return 1;
    } else if((ponteiro1 -> horarioAbsoluto) == (ponteiro2 -> horarioAbsoluto)){
        return 0;
    } else {
        return -1;
    }
}

int horario_ehFuturo(horario *ponteiro1, horario *ponteiro2){
  if((ponteiro1 -> horarioAbsoluto) < (ponteiro2 -> horarioAbsoluto)){
      return 1;
    } else {
      return 0;
    }
}

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

int horario_getHorarioString(horario *ponteiro, char *string){
    struct tm swap;
    char *stringswap;

    gmtime_r(&(ponteiro-> horarioAbsoluto), &swap);
    stringswap = asctime(&swap);

    strcpy(string, stringswap);
}
