#ifndef LISTA_RANDOM_H_INCLUDED
#define LISTA_RANDOM_H_INCLUDED

typedef struct item_lista_encadeada_random_item_t {
	unsigned int VID;
	struct item_lista_encadeada_random_t * proximo;
} item_lista_encadeada_random;

typedef struct {
    item_lista_encadeada_random *primeiroPtr;
    item_lista_encadeada_random *ultimoPtr;
} lista_encadeada_random;

int lista_encadeada_random_criaLista(lista_encadeada_random *ponteiro);
int lista_encadeada_random_insereVID(lista_encadeada_random *lista, unsigned int VID);
int lista_encadeada_random_removeVoo(lista_encadeada_random *lista, unsigned int VID);

#endif
