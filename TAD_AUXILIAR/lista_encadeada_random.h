typedef struct lista_encadeada_random_item_t {
	unsigned int numero;
	struct lista_encadeada_random_t * proximo;
} lista_encadeada_random_item;

typedef struct {
    lista_encadeada_random_item *primeiroPtr;
    lista_encadeada_random_item *ultimoPtr;
} lista_encadeada_random;

int lista_encadeada_random_criaLista(lista_encadeada_random *ponteiro);
int lista_encadeada_random_insereVID(lista_encadeada_random *lista, unsigned int VID);
int lista_encadeada_random_removeVoo(lista_encadeada_random *lista, unsigned int VID);