#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "TAD_AUXILIAR/horario.h"
#include "TAD_AUXILIAR/lista_encadeada_random.h"

#include "TAD/VOO.h"
#include "TAD/LISTA_DE_VOOS.h"
#include "TAD/ITEM_MATRIZ.h"
#include "TAD/MATRIZ_VOOS.h"

void printarRetorno(int retorno){
	if(retorno==0){
		printf("########################################################################################################\n");
		printf("#                                              Feito!                                                  #\n");
		printf("########################################################################################################\n");
	} else {
		printf("########################################################################################################\n");
		printf("#                                         Erro. Tente novamente.                                       #\n");
		printf("########################################################################################################\n");
	}
}

int main(){

	MATRIZ_VOOS matriz;
	MATRIZ_VOOS *ponteiroMatriz = &matriz;

	char input = ' ';
	char swapString1[30], swapString2[30];
	unsigned int swapUnsInt1, swapUnsInt2, swapUnsInt3, swapUnsInt4, swapUnsInt5;
	VOO * swapVoo;
	horario *swapHorario1, *swapHorario2;
	int retorno = 1;
	
	MATRIZ_VOOS_inicializa(ponteiroMatriz);

	printf("########################################################################################################\n");
	printf("#                                       Seja-bem vindo ao xAero Airport System                         #\n");
	printf("#                                                                                                      #\n");
	printf("#                                                       !                                              #\n");                     
    printf("#                                                       !                                              #\n");
    printf("#                                                      /_\\                                             #\n");
    printf("#                                               =====/` - '\\=====                                      #\n");
    printf("#                                                   ( ( O ) )                                          #\n");
    printf("#                            --______-------________/\\  -  /\\_______--------______--                   #\n");
    printf("#                                 ---------____***___/`---'\\__***____--------                          #\n");
    printf("#                                                                                                      #\n");
	printf("########################################################################################################\n");

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

	printf("########################################################################################################\n");


	printf("Digite alguma opcao: ");

	while(1){
		scanf("%c", &input);
		printf("\n");

		switch(input){
		case 'a':
			retorno = MATRIZ_VOOS_inicializa(ponteiroMatriz);
			printarRetorno(retorno);
			break;

		case 'b':
		
			printf("Digite o VOO nesse formato: XX:XX YY:YY AEROPORTO_DECOL AEROPORTO_POUSO IDENTIFICADOR_PIST :\n");
			scanf("%d:%d %d:%d %s %s %d", &swapUnsInt1, &swapUnsInt2, &swapUnsInt3, &swapUnsInt4, swapString1, swapString2, &swapUnsInt5);

			printf("\n");

			swapHorario1 = malloc(sizeof(horario));
			horario_inicializa(swapHorario1);
			horario_setHorario(swapHorario1, swapUnsInt1, swapUnsInt2);


			swapHorario2 = malloc(sizeof(horario));
			horario_inicializa(swapHorario2);
			horario_setHorario(swapHorario1, swapUnsInt3, swapUnsInt4);

			swapVoo = malloc(sizeof(VOO));
			VOO_inicializa(swapVoo);

			VOO_setHorarioDecolagem(swapVoo, swapHorario1);
			VOO_setHorarioPouso(swapVoo, swapHorario2);

			retorno = MATRIZ_VOOS_setVoo(ponteiroMatriz,swapVoo);

			free(swapVoo);
			free(swapHorario1);
			free(swapHorario2);

			printarRetorno(retorno);

			break;
		
		case 'c':

			printf("Digite um VID: ");
			swapUnsInt1=0;
			scanf("%d", &swapUnsInt1);

			retorno = MATRIZ_VOOS_delVoo(ponteiroMatriz, &swapUnsInt1);

			printarRetorno(retorno);
			break;
		
		case 'd':

			printf("Digite um VID: ");
			swapUnsInt1=0;
			scanf("%d", &swapUnsInt1);

			retorno = MATRIZ_VOOS_getVoo(ponteiroMatriz, &swapUnsInt1);
			printarRetorno(retorno);
			
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