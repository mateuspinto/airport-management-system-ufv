// Incluindo header do TAD e/ou bibliotecas necessárias
#include "VOO.h"
#include <time.h>

int randomizer = 0;
/* Limpa a memória para um TAD. Tem como entrada um ponteiro para o TAD e
   retorna 0 se for bem sucedido */
int VOO_inicializa(VOO *ponteiro){
    ponteiro -> VID = 0;

    for(int i = 0; i < 30; i++){
        ponteiro -> aeroportoDecolagem[i] = ' ';
        ponteiro -> aeroportoPouso[i] = ' ';
    }
    ponteiro -> identificadorPistaDecolagem = 0;

    srand(time(NULL));
    ponteiro -> VID = (rand() % 10000) + randomizer*randomizer;
    randomizer++;

    printf("########################################################################################################\n");
    printf("#                                             VID %d                                                 #\n", ponteiro -> VID);

    return 0;
}

/* Define o dado Identificador de Voo do TAD VOO. Tem como entrada um ponteiro para o TAD e
   um unsigned int para o VID. Retorna 0 se for bem sucedido. */
int VOO_setVID(VOO *ponteiro, unsigned int VID){

    ponteiro -> VID = VID;

    return 0;
}

/* Define o dado Horario de Decolagem do TAD VOO. Tem como entrada um ponteiro para o TAD e
   um int para o horario. Retorna 0 se for bem sucedido. */
int VOO_setHorarioDecolagem(VOO *ponteiro, horario *horario){
    ponteiro->horarioDecolagem=*horario;
    return 0;
}

/* Define o dado Horario de Pouso do TAD VOO. Tem como entrada um ponteiro para o TAD e
   um int para o horario. Retorna 0 se for bem sucedido. */
int VOO_setHorarioPouso(VOO *ponteiro, horario *horario){
    ponteiro->horarioPouso=*horario;
    return 0;
}

/* Define o dado Aeroporto de Decolagem do TAD VOO. Tem como entrada um ponteiro para o TAD e
   um char para o aeroporto. Retorna 0 se for bem sucedido. */
int VOO_setAeroportoDecolagem(VOO *ponteiro, char *aeroporto){
    for(int i = 0; i < 30; i++) {
        ponteiro -> aeroportoDecolagem[i] = aeroporto[i];
    }
    return 0;
}

/* Define o dado Aeroporto de Pouso do TAD VOO. Tem como entrada um ponteiro para o TAD e
   um char para o aeroporto. Retorna 0 se for bem sucedido. */
int VOO_setAeroportoPouso(VOO *ponteiro, char *aeroporto){
    for(int i = 0; i < 30; i++) {
        ponteiro -> aeroportoPouso[i] = aeroporto[i];
    }
    return 0;
}

/* Define o dado Pista de Decolagem do TAD VOO. Tem como entrada um ponteiro para o TAD e
   um unsigned int para a pista. Retorna 0 se for bem sucedido. */
int VOO_setIdentificadorPistaDecolagem(VOO *ponteiro, int identificador){
    ponteiro -> identificadorPistaDecolagem = identificador;
    return 0;
}

/* Retorna o dado VID do TAD VOO. Tem como entrada um ponteiro para o TAD
   VOO. */
unsigned int VOO_getVID(VOO *ponteiro){
    return ponteiro -> VID;
}

/* Retorna o dado Horario de Decolagem do TAD VOO. Tem como entrada um ponteiro para o TAD
   VOO. */
void VOO_getHorarioDecolagem(VOO *ponteiro, horario *horario){
    ponteiro -> horarioDecolagem = *horario;
}

/* Retorna o dado Horario de Pouso do TAD VOO. Tem como entrada um ponteiro para o TAD
   VOO. */
void VOO_getHorarioPouso(VOO *ponteiro, horario *horario){
    ponteiro -> horarioDecolagem = *horario;
}

/* Retorna o dado Aeroporto de Decolagem do TAD VOO. Tem como entrada um ponteiro para o TAD
   VOO. */
void VOO_getAeroportoDecolagem(VOO *ponteiro, char *aeroporto){
    for(int i = 0; i < 30; i++) {
        aeroporto[i] = ponteiro -> aeroportoDecolagem[i];
    }
}

/* Retorna o dado Aeroporto de Pouso do TAD VOO. Tem como entrada um ponteiro para o TAD
   VOO. */
void VOO_getAeroportoPouso(VOO *ponteiro, char *aeroporto){
    for(int i = 0; i < 30; i++) {
        aeroporto[i] = ponteiro -> aeroportoPouso[i];
    }
}

/* Retorna o dado Pista de Decolagem do TAD VOO. Tem como entrada um ponteiro para o TAD
   VOO. */
int VOO_getIdentificadorPistaDecolagem(VOO *ponteiro){
    return ponteiro -> identificadorPistaDecolagem;
}

// Printa o VID de um VOO dado endereco dele
void VOO_showVID(VOO *ponteiro){
    printf("VID : %d\n", ponteiro->VID);
}

// Printa o horario de decolagem de um VOO dado endereco dele
void VOO_showHorarioDecolagem(VOO *ponteiro){
    printf("Decolagem - ");
    horario_showHorario(&(ponteiro->horarioDecolagem));
}

// Printa o horario de pouso de um VOO dado endereco dele
void VOO_showHorarioPouso(VOO *ponteiro){
  printf("Pouso - ");
    horario_showHorario(&(ponteiro->horarioPouso));
}

// Printa o aeroporto de decolagem de um VOO dado endereco dele
void VOO_showAeroportoDecolagem(VOO *ponteiro){
    printf("Aeroporto de Descolagem: %s\n", ponteiro->aeroportoDecolagem);
}

// Printa o aeroporto de pouso de um VOO dado endereco dele
void VOO_showAeroportoPouso(VOO *ponteiro){
    printf("Aeroporto de Pouso: %s\n", ponteiro->aeroportoPouso);
}

// Printa o identificador de pista de decolagem de um VOO dado endereco dele
int VOO_showIdentificadorPistaDecolagem(VOO *ponteiro){
    printf("Identificador da Pista de Decolagem: %d\n", ponteiro->identificadorPistaDecolagem);
}

// Printa todas as informacoes de um VOO dado endereco dele usando as funcoes passadas
int VOO_showVoo(VOO *ponteiro){
    VOO_showVID(ponteiro);
    VOO_showAeroportoDecolagem(ponteiro);
    VOO_showAeroportoPouso(ponteiro);
    VOO_showIdentificadorPistaDecolagem(ponteiro);
    VOO_showHorarioDecolagem(ponteiro);
    VOO_showHorarioPouso(ponteiro);
}
