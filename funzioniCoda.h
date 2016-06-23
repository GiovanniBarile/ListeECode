#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s {
	char identificativo[6];
}informazioni;

struct nodo {
	informazioni info;
	struct nodo *next;
};

struct nodo* front ;
struct nodo* rear;
//Variabili per inizio e fine coda;


//Inizio prototipi;;
void inCoda(informazioni x);
void outCoda();
int Front();
void stampaCoda();