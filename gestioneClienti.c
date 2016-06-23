#include "funzioniCoda.h"
#include "funzioniLista.h"

puntaNodo pInit;
int menuScelta =0;
int main(void) {
	pInit = NULL;

	do {
		menuScelta = menu();
		switch (menuScelta) {
		case 1: {
			informazioni info;
			printf("Inserisci il codice identificativo del nuovo cliente\n");
			scanf("%s", info.identificativo);
			inCoda(info);
			printf("Cliente inserito con successo\n");
			break;
		}
		case 2: {
			stampaLista(pInit);
			break;
		}

		case 3: {
			t_lista info;
			char *primoCliente;
			primoCliente = Front();
			printf("Inserisci il codice dell'articolo, il numero di pezzi e il prezzo\n");
			strcpy(info.codiceCliente, primoCliente);
			scanf("%s %d %f", info.codiceArt, &info.pezzi, &info.prezzo);
			printf("Cliente aggiunto alla lista\n");

			inserisciInLista(&pInit, info);
			break;
		}
		case 4: {

			float totale = calcolaAcquisti(pInit);
			printf("Il totale degli acquisti effettuati e' : %.2f\n", totale);
			break;
		}
		case 5: {
			int maggiore = acquistoMaggiore(pInit);
			printf("L'acquisto piu' alto e' stato di %d\n", maggiore);
			break;
		}
		case 6: {
			char FILENAME[FILENAME_MAX];
			printf("Inserisci il nome del file da salvare : ");
			scanf("%s", FILENAME);

			salvaFile(pInit, FILENAME);
			break;
		}

		}
	} while (menuScelta != 0);

}

int menu(void) {
	int k;
	printf("Scegli l'operazione\n");
	printf("1]- Inserisci un nuovo cliente in coda\n");
	printf("2]- Stampa la lista degli acquisti\n");
	printf("3]- Servi il primo cliente della coda\n");
	printf("4]- Calcola il totale degli acquisti effettuati\n");
	printf("5]- Calcola l'acquisto piu' alto\n");
	printf("6]- Salva la lista degli acquisti su file\n");
	printf("[0] Esci\n");
	printf(">>");
	scanf("%d", &k);
	return k;
}