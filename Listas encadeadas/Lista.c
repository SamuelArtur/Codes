#include "Lista.h"

struct lista{
	int valor;
	struct lista *prox;
};

typedef struct lista Lista;

Lista* cria(){
	return NULL;
}

Lista* removeK(Lista *l, int k){
	if(l == NULL){
		return NULL;
	}
	else if(k==1){
		Lista* aux = l;
		l = l->prox;
		free(aux);
		return l;
	}
	return l = removeK(l->prox, k--);
}

Lista* removeX(Lista *l, int x){
	if(l==NULL){
		return NULL;
	}
	else{
		if(l->valor == x){
			Lista *aux = l;
			l = l->prox;
			free(aux);
		}
			l->prox = removeX(l->prox, x);
	}
	return l;
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

Lista* removeMaximo(Lista *l){
	if(l == NULL){
		return l;
	}
	else{
		retira(l, cellMaxima(l));
	}
}

Lista* removeMinimo(Lista* l){
	if(l == NULL){
		return NULL;
	}
	else{
		retira(l, cellMinima(l));
	}
}

Lista* retira(Lista *l, int x){
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

int cellMinima(Lista *l){
	Lista* aux = l;
	int menor = aux->valor;
	while(aux != NULL){
		if(aux->valor < menor){
			menor = aux->valor;
		}
		aux = aux->prox;
	}
	return menor;
}

int cellMaxima(Lista *l){
	Lista* aux = l;
	int maior = aux->valor;
	while(aux != NULL){
		if(aux->valor > maior){
			maior = aux->valor;
		}
		aux = aux->prox;
	}
	return maior;
}

Lista* insereInicio(Lista* l, int x){
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

Lista* busca(Lista *l, int v){
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