#include "horario.h"

int horario_getHorarioAbsoluto(horario *ponteiro){
    return ponteiro -> horarioAbsoluto;
}

int horario_setHorarioAbosluto(horario *ponteiro, long int horario){
    ponteiro -> horarioAbsoluto = horario;
    return 0;
}

int horario_compararHorarios(horario *ponteiro1, horario *ponteiro2){
    if(ponteiro1 -> horarioAbsoluto > ponteiro2 -> horarioAbsoluto){
        return 1;
    } else if(ponteiro1 -> horarioAbsoluto = ponteiro2 -> horarioAbsoluto){
        return 0;
    } else {
        return -1;
    }
}
