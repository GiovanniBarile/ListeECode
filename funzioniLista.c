#include "funzioniLista.h"
float somma=0;

void inserisciInLista(puntaNodo *lista, t_lista elem) {

	puntaNodo temp;
	temp =(t_nodo*)malloc(sizeof(t_nodo));

	temp->info = elem;
	temp->next = *lista;
	*lista = temp;
}

void stampaLista(puntaNodo lista) {
	int i = 1;
	printf("Clienti serviti :\n");
	if (lista != NULL) {
	
	while (lista != NULL) {

		printf("Cliente numero %d) \nCodice Cliente : %s\nCodice articolo : %s\nPezzi acquistati : %d\nPrezzo : %.2f\n", i,lista->info.codiceCliente, lista->info.codiceArt, lista->info.pezzi, lista->info.prezzo);
		lista = lista->next;
		i++;
	}
	}
	else {
		printf("La lista e' vuota\n");
	}
}
float calcolaAcquisti(puntaNodo lista) {
	while (lista != NULL) {
		somma = somma + ((lista)->info).prezzo;
		lista = lista->next;
	}
	return somma;
}
int acquistoMaggiore(puntaNodo lista) {
	int primo = lista->info.prezzo;
	int max = 0;
	while (lista != NULL) {
		if (lista->info.prezzo > primo) {
			max = lista->info.prezzo;
			lista = lista->next;
		}
		return primo;
	}
}

void salvaFile(puntaNodo lista, char * FILENAME) {
	FILE *fOut = fopen(FILENAME, "w");
	if (fOut != NULL) {
		printf("File aperto con successo\n");
		int i = 1;
		while (lista != NULL) {
		fprintf(fOut, "Cliente numero %d)\nCodice Cliente : %s\nCodice articolo : %s\nPezzi acquistati : %d\nPrezzo : %.2f\n", i,lista->info.codiceCliente, lista->info.codiceArt, lista->info.pezzi, lista->info.prezzo);
		lista = lista->next;
		i++;
		}
		printf("File scritto con successo");
		fclose(fOut);
	}
	else {
		printf("Errore nell'apertura del file\n");
	}
}