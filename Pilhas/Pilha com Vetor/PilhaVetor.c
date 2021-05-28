#define N 5
#include <stdio.h>
#include <stdlib.h>
#include "PilhaVetor.h"

struct pilha
{
	int topo;

	char vet[N];
};

Pilha* pilhaCria(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = 0;
	return p;
}

void pilhaPush(Pilha* p, char v){
	if(pilhaCheia(p)){
		printf("A pilha esta cheia\n");
		return;
	}
	p->vet[p->topo] = v;
	p->topo++;
}

char pilhaPop(Pilha* p){
	if(pilhaVazia(p)){
		printf("A pilha esta vazia\n");
		exit(1);
	}
	char v = p->vet[p->topo - 1];
	p->topo--;
	return v;
}

int pilhaVazia(Pilha* p){
	return (p->topo == 0);
}

int pilhaCheia(Pilha* p){
	if(p->topo == N){
		return 1;
	}
	return 0;
}

void liberaPilha(Pilha* p){
	free(p);
}

char leTopo(Pilha* p){
	return p->vet[p->topo-1];
}