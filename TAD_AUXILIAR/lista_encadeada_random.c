int lista_encadeada_random_criaLista(lista_encadeada_random *ponteiro){
    ponteiro -> primeiroPtr = malloc(sizeof(lista_encadeada_random_item));
    ponteiro -> ultimoPtr = ponteiro -> primeiroPtr ;
    ponteiro -> primeiroPtr -> proximo = NULL;
    return 0;
}

int lista_encadeada_random_insereVID(lista_encadeada_random *lista, unsigned int VID){
	return 0;
}

int lista_encadeada_random_removeVoo(lista_encadeada_random *lista, unsigned int VID){
	return 0;
}