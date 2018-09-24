//Incluindo bibliotecas padroes necessárias
#include <stdio.h>
#include <stdlib.h>

//Incluindo TADs auxiliares
#include "TAD_AUXILIAR/horario.h"

//Incluindo TADs Globais
#include "TAD/VOO.h"
#include "TAD/LISTA_DE_VOOS.h"
#include "TAD/ITEM_MATRIZ.h"
#include "TAD/MATRIZ_VOOS.h"

//Definindo variáveis globais para a matriz struct e um ponteiro para a matriz
//O uso de variáveis globais é justificado aqui para poupar sintaxe e desempenho, visto que sao variavéis que nunca sofrerão
//mudanças de endereço e etc.
MATRIZ_VOOS matriz;
MATRIZ_VOOS *ponteiroMatriz;

//Função que imprime se o retorno das funcoes foi positivo ou negativo. Feita pra poupar retrabalho.
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

//Semelhante a primeira, porém com uma mensagem de erro diferente.
void printarRetornoVID(int retorno){
	if(retorno==0){
		printf("########################################################################################################\n");
		printf("#                                              Feito!                                                  #\n");
		printf("########################################################################################################\n");
	} else {
		printf("########################################################################################################\n");
		printf("#                                      Erro. VID nao encontrado.                                       #\n");
		printf("########################################################################################################\n");
	}
}

//Aqui foram criadas funções iguais para o MODO ARQUIVO e o interativo, para poupar re-trabalho. Nessas funcoes, sao usadas
//as variáveis globais.

//Incializa a matriz usando a função MATRIZ_VOOS_inicializa
int opcaoA(){
		return MATRIZ_VOOS_inicializa(ponteiroMatriz);
}

//Cria dois TADS auxiliares horários e um VOO com malloc, o aloca na matriz e libera espaço dos mallocs. A função usada foi
//MATRIZ_VOOS_setVoo
int opcaoB(unsigned int *horaDeco, unsigned int *minDeco, unsigned int *horaPouso, unsigned int *minPouso, char *aeroDeco, char *aeroPouso, unsigned int *pis){

	// Criando ponteiros e um int pra guardar retorno;
	int retorno;
	VOO * swapVoo=NULL;
	horario *swapHorario1=NULL, *swapHorario2=NULL;

	// Reservando memoria para guardar horario de decolagem e usando funcoes do TAD horario pra definir hora e minuto
	swapHorario1 = malloc(sizeof(horario));
	horario_inicializa(swapHorario1);
	horario_setHorario(swapHorario1, *horaDeco, *minDeco);

	// Reservando memoria para guardar horario de pouso e usando funcoes do TAD horario pra definir hora e minuto
	swapHorario2 = malloc(sizeof(horario));
	horario_inicializa(swapHorario2);
	horario_setHorario(swapHorario2, *horaPouso, *minPouso);

	// Reservando memoria para guardar VOO para alocar.
	swapVoo = malloc(sizeof(VOO));
	VOO_inicializa(swapVoo);

	// Definindo parametros do VOO com as funcoes feitas para tal
	VOO_setHorarioDecolagem(swapVoo, swapHorario1);
	VOO_setHorarioPouso(swapVoo, swapHorario2);
	VOO_setAeroportoDecolagem(swapVoo, aeroDeco);
	VOO_setAeroportoPouso(swapVoo, aeroPouso);
	VOO_setIdentificadorPistaDecolagem(swapVoo, *pis);

	// Guardando retorno
	retorno = MATRIZ_VOOS_setVoo(ponteiroMatriz,swapVoo);

	// Liberando memoria usada nos mallocs
	free(swapVoo);
	free(swapHorario1);
	free(swapHorario2);

	return retorno;
}

//Remove um VOO a partir do VID usando a MATRIZ_VOOS_delVoo
int opcaoC(unsigned int *VID){
	return MATRIZ_VOOS_delVoo(ponteiroMatriz, VID);
}

//Procura um VOO a partir do VID usando a MATRIZ_VOOS_getVoo
int opcaoD(unsigned int *VID){
	return MATRIZ_VOOS_getVoo(ponteiroMatriz, VID);
}

int opcaoE(unsigned int *horaDeco, unsigned int *minDeco, unsigned int *horaPouso, unsigned int *minPouso){
	int retorno;
	horario *swapHorario1, *swapHorario2;

	// Reservando memoria para guardar horario de decolagem e usando funcoes do TAD horario pra definir hora e minuto
	swapHorario1 = malloc(sizeof(horario));
	horario_inicializa(swapHorario1);
	horario_setHorario(swapHorario1, *horaDeco, *minDeco);

	// Reservando memoria para guardar horario de pouso e usando funcoes do TAD horario pra definir hora e minuto
	swapHorario2 = malloc(sizeof(horario));
	horario_inicializa(swapHorario2);
	horario_setHorario(swapHorario2, *horaPouso, *minPouso);


	retorno = MATRIZ_VOOS_showVoosDecolagemPouso(ponteiroMatriz, swapHorario1, swapHorario2);

	free(swapHorario1);
	free(swapHorario2);

	return retorno;
}

int opcaoF(unsigned int *horaDeco, unsigned int *minDeco){
	int retorno;
	horario *swapHorario1;

	// Reservando memoria para guardar horario de decolagem e usando funcoes do TAD horario pra definir hora e minuto
	swapHorario1 = malloc(sizeof(horario));
	horario_inicializa(swapHorario1);
	horario_setHorario(swapHorario1, *horaDeco, *minDeco);

	retorno = MATRIZ_VOOS_showVoosDecolagem(ponteiroMatriz, swapHorario1);

	free(swapHorario1);

	return retorno;
}

int opcaoG(){
	return 0;
}

//Imprime todos os VOOs da matriz usando a MATRIZ_VOOS_showVoos
int opcaoH(){
	return MATRIZ_VOOS_showVoos(ponteiroMatriz);
}

int opcaoI(){
	return MATRIZ_VOOS_showHorarioMaisVoos(ponteiroMatriz);
}

int opcaoJ(){
	return MATRIZ_VOOS_showHorarioMenosVoos(ponteiroMatriz);
}

int opcaoK(){
	return 0;
}

int opcaoL(){
	return 0;
}

//Diz se a matriz e esparca ou nao usando a MATRIZ_VOOS_verificarMatrizEsparca
int opcaoM(){
	return MATRIZ_VOOS_verificarMatrizEsparca(ponteiroMatriz);
}

int main(){

	//Colocando endereço da matriz global no ponteiro global
	ponteiroMatriz = &matriz;

	//Criando algumas areas de memoria de troca para o resto do programa
	char swapString1[30], swapString2[30], opcaoArquivo;
	unsigned int swapUnsInt1, swapUnsInt2, swapUnsInt3, swapUnsInt4, swapUnsInt5;

	//Definindo input padrao, caso a pessoa nao digite nada e criando a variavel em si
	char input = ' ';

	//Definindo retorno padrao de funcoes como erro
	int retorno = 1;

	//Criando um ponteiro para arquivo
	FILE * arquivo = NULL;

	//Inicializando a matriz automaticamente, caso o usuário se esqueça
	MATRIZ_VOOS_inicializa(ponteiroMatriz);

	//Printando Menu do programa
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

	printf("a- Inicializar.\n");
	printf("b- Inserir voo.\n");
	printf("c- Remover voo.\n");
	printf("d- Procurar voo.\n");
	printf("e- Imprimir voos.\n");
	printf("f- Imprimir voos.\n");
	printf("g- Imprimir voos.\n");
	printf("h- Imprimir toda a matriz\n");
	printf("i- Encontrar faixa de horario de decolagem e previsao de pouso com maior numero de voos cadastrados.\n");
	printf("j- Encontrar faixa de horario de decolagem e previsao de pouso com menor numero de voos cadastrados.\n");
	printf("k- Encontrar lista de voos mais recentemente alterada. \n");
	printf("l- Encontrar lista de voos menos recentemente alterada.\n");
	printf("m- Verificar se matriz e esparca.\n");
	printf("9- MODO ARQUIVO\n");
	printf("0- Sair do programa.\n\n");


	printf("Digite alguma opcao: ");

	//While eterno, até que a pessoa digite 0 para sair do programa
	while(1){

		//Escaneia o que o usuário digitar.
		scanf("%c", &input);
		printf("\n");

		//Pega o que o usuário digitar e trata, usando memória de troca criada e as funções previamente estabelecidas.
		switch(input){

		case 'a':
			retorno = opcaoA();
			printarRetorno(retorno);
			break;

		case 'b':

			printf("Digite o VOO nesse formato: XX:XX YY:YY AEROPORTO_DECOL AEROPORTO_POUSO IDENTIFICADOR_PIST :\n");
			scanf("%d:%d %d:%d %s %s %d", &swapUnsInt1, &swapUnsInt2, &swapUnsInt3, &swapUnsInt4, swapString1, swapString2, &swapUnsInt5);

			retorno = opcaoB(&swapUnsInt1, &swapUnsInt2, &swapUnsInt3, &swapUnsInt4, swapString1, swapString2, &swapUnsInt5);
			printarRetorno(retorno);

			break;

		case 'c':

			printf("Digite um VID: ");
			swapUnsInt1=0;
			scanf("%d", &swapUnsInt1);

			retorno = opcaoC(&swapUnsInt1);

			printarRetorno(retorno);
			break;

		case 'd':

			printf("Digite um VID: ");
			swapUnsInt1=0;
			scanf("%d", &swapUnsInt1);

			retorno = opcaoD(&swapUnsInt1);
			printarRetorno(retorno);

			break;

		case 'e':

			printf("Digite o horario de decolagem e de pouso no padrão XX:XX YY:YY\n");
			scanf("%d:%d %d:%d", &swapUnsInt1, &swapUnsInt2, &swapUnsInt3, &swapUnsInt4);
			retorno = opcaoE(&swapUnsInt1, &swapUnsInt2, &swapUnsInt3, &swapUnsInt4);
			printarRetorno(retorno);

			break;

		case 'f':

			printf("Digite o horario de decolagem no padrão XX:XX\n");
			scanf("%d:%d", &swapUnsInt1, &swapUnsInt2);
			retorno = opcaoF(&swapUnsInt1, &swapUnsInt2);
			printarRetorno(retorno);


			break;

		case 'g':

			break;

		case 'h':
			retorno = opcaoH();
			printarRetorno(retorno);
			break;

		case 'i':
			opcaoI();
			break;

		case 'j':
			opcaoJ();
			break;

		case 'k':

			break;

		case 'l':

			break;

		case 'm':
			opcaoM();

			break;

		// O caso 9 é o MODO ARQUIVO, que lê algum arquivo e executa suas instruções
		case '9':

			printf("Digite o nome do arquivo e a extensao. Exemplo TESTE.txt : ");

			//Pega o nome do arquivo
			scanf("%s",swapString1);

			//Tratando caso em que o usuário digita o nome errado do arquivo
			if((arquivo = fopen(swapString1, "r"))==NULL){
				printf("Arquivo nao encontrado. Tente novamente mais tarde.\n");


			} else {
				//Percorrendo todo o arquivo com um while
				while(!feof(arquivo)){

					//Pegando o primeiro caractere de cada linha do arquivo e armazenando numa varíavel de area de troca
					fscanf(arquivo,"%c", &opcaoArquivo);

					//Um switch escolhe a funcao certa, e a cada caso, as informacoes da linha sao armazenadas em areas de troca e a funcao
					//correspondente é chamada
					switch(opcaoArquivo){

						case 'a':
							retorno = opcaoA();
							printarRetorno(retorno);

							break;

						case 'b':
							fscanf(arquivo,"%d:%d %d:%d %s %s %d", &swapUnsInt1, &swapUnsInt2, &swapUnsInt3, &swapUnsInt4, swapString1, swapString2, &swapUnsInt5);
							retorno = opcaoB(&swapUnsInt1, &swapUnsInt2, &swapUnsInt3, &swapUnsInt4, swapString1, swapString2, &swapUnsInt5);
							printarRetorno(retorno);

							break;

						case 'c':
							swapUnsInt1=0;
							fscanf(arquivo, "%d", &swapUnsInt1);
							retorno = opcaoC(&swapUnsInt1);
							printarRetornoVID(retorno);

							break;

						case 'd':

							swapUnsInt1=0;
							fscanf(arquivo, "%d", &swapUnsInt1);
							retorno = opcaoD(&swapUnsInt1);
							printarRetorno(retorno);

							break;

						case 'e':

							fscanf(arquivo, "%d:%d %d:%d", &swapUnsInt1, &swapUnsInt2, &swapUnsInt3, &swapUnsInt4);
							retorno = opcaoE(&swapUnsInt1, &swapUnsInt2, &swapUnsInt3, &swapUnsInt4);
							printarRetorno(retorno);

							break;

						case 'f':
						//	retorno = opcaoF();
							printarRetorno(retorno);

							break;

						case 'g':
							retorno = opcaoG();
							printarRetorno(retorno);

							break;

						case 'h':
							retorno = opcaoH();
							printarRetorno(retorno);

							break;

						case 'i':
							retorno = opcaoI();
							printarRetorno(retorno);

							break;

						case 'j':
							retorno = opcaoJ();
							printarRetorno(retorno);

							break;

						case 'k':
							retorno = opcaoK();
							printarRetorno(retorno);

							break;

						case 'l':
							retorno = opcaoL();
							printarRetorno(retorno);

							break;

						case 'm':
							opcaoM();
							break;


						default:
							break;
					}

				}







			//Fecha o arquivo garantindo assim que ele nao será corrompido e etc
			fclose(arquivo);
			}

			break;

		//O caso 0 engloba o que acontece quando o usário pede pra sair do programa
		case '0':
			printf("########################################################################################################\n");
			printf("#                        Muito obrigado por usar o xAero Airport System s2                             #\n");
			printf("########################################################################################################\n\n");
			system("pause");
			return 0;

		default:
			printf("Digite outra opcao : ");
	}

	}


}
