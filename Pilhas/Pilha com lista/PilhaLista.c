#include <stdio.h>
#include <stdlib.h>
#include "PilhaLista.h"
#include "Lista.h"

struct pilha
{
	Lista* topo;
};

Pilha* pilhaCria(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

int pilhaVazia(Pilha* p){
	return (p->topo == NULL);
}

void pilhaPush(Pilha* p, char v){
	Lista* n = (Lista*) malloc(sizeof(Lista));
	n->valor = v;
	n->prox  = p->topo;
	p->topo = n;
}

char pilhaPop(Pilha* p){
	if(pilhaVazia(p)){
		printf("A pilha esta vazia\n");
		exit(1);
	}
	Lista* l;
	char v;
	l = p->topo;
	v = l->valor;
	p->topo = l->prox;
	free(l);
	return v;
}

void pilhaLibera(Pilha* p){
	if(p->topo == NULL){
		return;
	}
	else{
		pilhaLibera(p->topo.prox);
		free(p->topo);
	}
}

char leTopo(Pilha* p){
	return (p->topo.valor);
}
