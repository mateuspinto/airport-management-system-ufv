// Incluindo header do TAD e/ou bibliotecas necessárias
#include "horario.h"

/* Limpa a memória para um TAD. Tem como entrada um ponteiro para o TAD e
   retorna 0 se for bem sucedido */
int horario_inicializa (horario *ponteiro) {
  ponteiro -> hora = 0;
  ponteiro -> minuto = 0;
  ponteiro -> dia = 0;
  ponteiro -> mes = 0;
  ponteiro -> ano = 0;

  return 0;
}

/* Define o dado Hora do TAD horario. Tem como entrada um ponteiro para o TAD e
   um unsigned short para a hora. Retorna 0 se for bem sucedido */
int horario_setHora(horario *ponteiro, unsigned short int hora){
  ponteiro -> hora = hora;

  return 0;
}

/* Define o dado Minuto do TAD horario. Tem como entrada um ponteiro para o TAD
   horario e um unsigned short para o minuto. Retorna 0 se for bem sucedido */
int horario_setMinuto(horario *ponteiro, unsigned short int minuto){
  ponteiro -> minuto = minuto;

  return 0;
}

/* Define o dado Dia do TAD horario. Tem como entrada um ponteiro para o TAD
   horario e um unsigned short para o dia. Retorna 0 se for bem sucedido */
int horario_setDia(horario *ponteiro, unsigned short int dia){
  ponteiro -> dia = dia;

  return 0;
}

/* Define o dado Mes do TAD horario. Tem como entrada um ponteiro para o TAD
   horario e um unsigned short para o mes. Retorna 0 se for bem sucedido */
int horario_setMes(horario *ponteiro, unsigned short int mes){
  ponteiro -> mes = mes;

  return 0;
}

/* Define o dado Ano do TAD horario. Tem como entrada um ponteiro para o TAD
   horario e um unsigned short para o ano. Retorna 0 se for bem sucedido */
int horario_setAno(horario *ponteiro, unsigned short int ano){
  ponteiro -> ano = ano;

  return 0;
}

/* Retorna o dado Hora do TAD horario. Tem como entrada um ponteiro para o TAD
   horario */
unsigned short int horario_getHora(horario *ponteiro){

    return ponteiro -> hora;
}

/* Retorna o dado Minuto do TAD horario. Tem como entrada um ponteiro para o TAD
   horario */
unsigned short int horario_getMinuto(horario *ponteiro){

    return ponteiro -> minuto;
}

/* Retorna o dado Dia do TAD horario. Tem como entrada um ponteiro para o TAD
   horario */
unsigned short int horario_getDia(horario *ponteiro){

    return ponteiro -> dia;
}

/* Retorna o dado Mes do TAD horario. Tem como entrada um ponteiro para o TAD
   horario */
unsigned short int horario_getMes(horario *ponteiro){

    return ponteiro -> mes;
}

/* Retorna o dado Ano do TAD horario. Tem como entrada um ponteiro para o TAD
   horario */
unsigned short int horario_getAno(horario *ponteiro){

    return ponteiro -> ano;
}
