#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "TAD_AUXILIAR/horario.h"
#include "TAD_AUXILIAR/lista_encadeada_random.h"

#include "TAD/VOO.h"
#include "TAD/LISTA_DE_VOOS.h"
#include "TAD/ITEM_MATRIZ.h"
#include "TAD/MATRIZ_VOOS.h"

int main(){

	char input = ' ';
	char swapString[30];
	unsigned int swapUnsInt1, swapUnsInt2, swapUnsInt3;
	

	printf("##############################################################\n");
	printf("#        Seja-bem vindo ao xAero Airport System              #\n");
	printf("##############################################################\n\n");

	printf("O que voce deseja fazer?\n\n");
	printf("a- Inicializar\n");
	printf("b- Inserir voo\n");
	printf("c- Remover voo\n");
	printf("d- Procurar voo\n");
	printf("e- Imprimir voos\n");
	printf("f- Imprimir voos\n");
	printf("g- Imprimir voos\n");
	printf("h- Imprimir toda a matriz\n");
	printf("i- Encontrar faixa de horario de decolagem e previsao de pouso com maior numero de voos cadastrados.\n");
	printf("j- Encontrar faixa de horario de decolagem e previsão de pouso com menor numero de voos cadastrados.\n");
	printf("k- Encontrar lista de voos mais recentemente alterada. \n");
	printf("l- Encontrar lista de voos menos recentemente alterada\n");
	printf("m- Verificar se matriz e esparca\n");
	printf("9- MODO ARQUIVO\n");
	printf("0- Sair do programa\n\n");

	printf("Digite alguma opcao ");

	while(1){
		scanf("%c", &input);
		printf("\n");

		switch(input){
		case 'a':

			break;

		case 'b':

			break;
		
		case 'c':

			break;
		
		case 'd':

			break;
		
		case 'e':

			break;
		
		case 'f':

			break;
		
		case 'g':

			break;
		
		case 'h':

			break;
		
		case 'i':

			break;
		
		case 'j':

			break;
		
		case 'k':

			break;
		
		case 'l':

			break;
		
		case 'm':

			break;
		
		case '9':

			break;
		
		case '0': 
			return 0;

		default: 
			printf("Digite novamente");
	}
	
	}

	
	system("pause");
	return 0;
}