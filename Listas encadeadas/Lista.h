#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
Lista* cria();
Lista* insereInicio(Lista *l, int i);
void imprime(Lista *l);
int vazia(Lista *l);
Lista* busca(Lista *l, int v);
Lista* retira(Lista *l, int v);
void libera(Lista *l);
int cellMinima(Lista *l);
Lista* removeMaximo(Lista *l);
int cellMaxima(Lista *l);
Lista* removeMinimo(Lista* l);
int contaCell(Lista *l);
Lista* concatenar(Lista *l1, Lista* l2);
Lista* removeK(Lista *l, int k);
Lista* removeX(Lista *l, int x);