#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TAD_AUXILIAR/horario.h"

int main(){
    horario irineu, irineu2;
    long int a;
    char * string;

    horario_setHorarioAbosluto(&irineu2, 900);

    horario_setHorario(&irineu, 0, 30, 13, 25, 5, 118);

    a = horario_getHorarioAbsoluto(&irineu);
    printf("%ld\n", a);

    horario_getHorarioString(&irineu, string);

    for(int i=0; i<27; i++){
      printf("%c", string[i]);
    }
}
