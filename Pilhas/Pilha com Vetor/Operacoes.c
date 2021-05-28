#include <stdio.h>
#include <stdlib.h>
#include "Operacoes.h"

void imprime(Pilha* p){
	Pilha* aux = pilhaCria();
	char x;
	while(!pilhaVazia(p)){
		x = pilhaPop(p);
		printf("%c\n", x);
		pilhaPush(aux, x);
	}
	while(!pilhaVazia(aux)){
		x = pilhaPop(aux);
		pilhaPush(p, x);	
	}
	liberaPilha(aux);
}

void imprimeReversa(Pilha* p){
	Pilha* aux = pilhaCria();
	char x;
	while(!pilhaVazia(p)){
		x = pilhaPop(p);
		pilhaPush(aux, x);
	}
	imprime(aux);
	while(!pilhaVazia(aux)){
		x = pilhaPop(aux);
		pilhaPush(p, x);	
	}
	liberaPilha(aux);
}

int palindrome(Pilha* p){
	Pilha* aux = p;
	char x;
	while(!pilhaVazia(p)){
		x = pilhaPop(p);
		pilhaPush(aux, x);
	}
}

void elimina(Pilha* p, char v){
	Pilha* aux = pilhaCria();
	char x;
	while(!pilhaVazia(p)){
		x = pilhaPop(p);
		if(x != v){
			pilhaPush(aux, x);
		}
	}
	while(!pilhaVazia(aux)){
		x = pilhaPop(aux);
		pilhaPush(p, x);	
	}
	liberaPilha(aux);
}

void maiusculoMinusculo();