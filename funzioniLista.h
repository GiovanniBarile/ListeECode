#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_lista {
	char codiceCliente[5];
	char codiceArt[10];
	int pezzi;
	float prezzo;
}t_lista;

typedef struct s_nodo {
	t_lista info;
	struct s_nodo *next;
}t_nodo;

typedef t_nodo *puntaNodo;


//Prototipi;
void inserisciInLista(puntaNodo *lista, t_lista elem);
void stampaLista(puntaNodo lista);
float calcolaAcquisti(puntaNodo lista);
int acquistoMaggiore(puntaNodo lista);
void salvaFile(puntaNodo lista, char * FILENAME);
//fine prototipi;