// Incluindo header do TAD e/ou bibliotecas necessárias
#include "VOO.h"

/* Limpa a memória para um TAD. Tem como entrada um ponteiro para o TAD e
   retorna 0 se for bem sucedido */
int VOO_inicializa(VOO *ponteiro){
    ponteiro -> VID = 0;

    for(int i = 0; i < 30; i++){
        ponteiro -> aeroportoDecolagem[i] = ' ';
        ponteiro -> aeroportoPouso[i] = ' ';
    }
    ponteiro -> identificadorPistaDecolagem = 0;

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
    

    return 0;
}

/* Define o dado Horario de Pouso do TAD VOO. Tem como entrada um ponteiro para o TAD e
   um int para o horario. Retorna 0 se for bem sucedido. */
int VOO_setHorarioPouso(VOO *ponteiro, horario *horario){

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
int VOO_setIdentificadorPistaDecolagem(VOO *ponteiro, unsigned int identificador){

    ponteiro -> identificadorPistaDecolagem = identificador;

    return 0;
}

/* Retorna o dado VID do TAD VOO. Tem como entrada um ponteiro para o TAD
   VOO. */
int VOO_getVID(VOO *ponteiro){
    return ponteiro -> VID;
}

/* Retorna o dado Horario de Decolagem do TAD VOO. Tem como entrada um ponteiro para o TAD
   VOO. */
void VOO_getHorarioDecolagem(VOO *ponteiro, horario *horario){

}

/* Retorna o dado Horario de Pouso do TAD VOO. Tem como entrada um ponteiro para o TAD
   VOO. */
void VOO_getHorarioPouso(VOO *ponteiro, horario *horario){

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
