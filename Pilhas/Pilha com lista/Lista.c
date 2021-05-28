#include "Lista.h"

struct lista{
	char valor;
	struct lista *prox;
};

typedef struct lista Lista;

Lista* cria(){
	return NULL;
}

Lista* concatenar(Lista *l1, Lista* l2){
	if(l1->prox == NULL){
		l1->prox = l2;
	}
	else{
		concatenar(l1->prox,l2);
	}
}

int contaCell(Lista *l){
	if(l==NULL){
		return 0;
	}
	else{
		int cont=1;
		return cont+= contaCell(l->prox);
	}
}

Lista* retira(Lista *l, char x){
	if(l==NULL){
		return NULL;
	}
	else{
		if(l->valor == x){
			Lista *aux = l;
			l = l->prox;
			free(aux);
		}
		else{
			l->prox = retira(l->prox, x);
		}
	}
	return l;
}

Lista* insereInicio(Lista* l, char x){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->valor = x;
	novo->prox = l;
	return novo;
}

void imprime(Lista *l){
	Lista *aux = l;
		if(l==NULL){
			printf("Lista vazia\n");
		}
	while(aux != NULL){
		printf("%d\n", aux->valor);
		aux = aux->prox;
	}
}

int vazia(Lista* l){
	if(l->prox == NULL){
		return 0;
	}
	else{
		return 1;
	}
}

void libera(Lista *l){
	while(l != NULL){

	Lista* aux = l;
		aux = l;
		l = l->prox;
		free(l);
	}
}

Lista* busca(Lista *l, char v){
	Lista* aux = l;
	while(aux != NULL){
		if(aux->valor == v){
			return aux;
		}
		aux = aux->prox;
	}
	printf("Valor não encontrado");
	return NULL;
}