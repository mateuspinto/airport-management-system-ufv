/* Define o TAD e os prototipos das funcoes caso eles ainda nao tenham sido
definidos */
#ifndef HORARIO_H_INCLUDED
#define HORARIO_H_INCLUDED

// Incluindo bibliotecas necessárias e/ou TADs auxiliares.
#include <stdlib.h>

// Definindo struct do TAD e o declarando como um tipo.
typedef struct {
  unsigned short int hora;
  unsigned short int minuto;
  unsigned short int dia;
  unsigned short int mes;
  unsigned short int ano;
} horario;

// Definindo protótipo da função inicializa que elimina lixo de memória.
int horario_inicializa(horario *ponteiro);

// Definindo o protótipo das funções set. Retornam 1 se der certo.
int horario_setHora(horario *ponteiro, unsigned short int hora);
int horario_setMinuto(horario *ponteiro, unsigned short int minuto);
int horario_setDia(horario *ponteiro, unsigned short int dia);
int horario_setMes(horario *ponteiro, unsigned short int mes);
int horario_setAno(horario *ponteiro, unsigned short int ano);

// Definindo o protótipo das funções get. Retornam o dado requisitado
unsigned short int horario_getHora(horario *ponteiro);
unsigned short int horario_getMinuto(horario *ponteiro);
unsigned short int horario_getDia(horario *ponteiro);
unsigned short int horario_getMes(horario *ponteiro);
unsigned short int horario_getAno(horario *ponteiro);

// Fim do define
#endif // HOARIO_H_INCLUDED
