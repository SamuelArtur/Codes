#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
Lista* cria();
Lista* insereInicio(Lista *l, char i);
void imprime(Lista *l);
int vazia(Lista *l);
Lista* busca(Lista *l, char v);
Lista* retira(Lista *l, char v);
void libera(Lista *l);
int contaCell(Lista *l);
Lista* concatenar(Lista *l1, Lista* l2);