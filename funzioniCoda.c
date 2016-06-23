#include "funzioniCoda.h"

void inCoda(informazioni x) {
	struct nodo* temp;
	temp = (struct nodo*)malloc(sizeof(struct nodo));
	temp->info = x;
	temp->next = NULL;

	//Se front e rear sono vuoti
	if (front == NULL && rear == NULL) {
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void outCoda() {
	struct nodo* temp = front;
	if (front == NULL) {
		printf("La coda e' vuota\n");
		return;
	}
	if (front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
}

int Front() {
	if (front == NULL) {
		printf("La coda e' vuota");
		return;
	}
	return front->info.identificativo;
}

void stampaCoda() {
	struct nodo* temp = front;
	while (temp != NULL) {
		printf("%s\n", temp->info.identificativo);
		temp = temp->next;
	}
}