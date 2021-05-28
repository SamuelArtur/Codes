#include <stdio.h>
#include <stdlib.h>
#include "Recursivas.h"

int imprimeCresce(int n)
{
    if(n < 0)
    {
        return 0;
    }
    else
    {
        imprimeCresce(n-1);
        printf("%d\n", n);
    }
}

int imprimeDecre(int n)
{
    if(n <= 0)
    {
        return 0;
    }
    else
    {
        printf("%d\n", n);
        return imprimeDecre(n-1);
    }
}

int imprimePares(int n)
{
    if(n<0)
    {
        return 0;
    }
    else
    {
        if(n%2==0)
        {
            printf("%d\n", n);
        }
        return imprimePares(n-1);
    }
}

int ePrimo(int n)
{
    int i;
    for(i=2; i<n; i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int imprimePrimos(int n)
{
    if(n<=1)
    {
        return 0;
    }
    else
    {
        if(ePrimo(n))
        {
            printf("%d\n", n);
        }
        return imprimePrimos(n-1);
    }
}

int elevar(int k, int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return k * elevar(k,n-1);
    }
}

int mdc(int x, int y)
{
    if(y == 0)
    {
        return x;
    }
    else
    {
        return mdc(x,x%y);
    }
}

int somaDigitos(int n)
{
	if(n<10){
		return n;
	}
	else{
		return n%10 + somaDigitos(n/10);
	}
}

int mult(int n1, int n2)
{
    if(n2 == 0 || n1 == 0)
    {
        return 0;
    }
    else
    {
        return n1 + mult(n1, n2-1);
    }
}

int menorElemento(int *v, int n){
	if(n==1){
		return v[0];
	}
	else{
		if(v[0] > v[n-1]){
			menorElemento(v+1,n-1);
		}
		else{
			menorElemento(v,n-2);
		}
	}
}

void inverteVetor(int *v, int n)
{
    if(n<=0)
    {
        return;
    }
    else
    {
        int aux = v[n-1];
        v[n-1] = v[0];
        v[0] = aux;
        return inverteVetor(v+1, n-2);
    }
}

void imprimeVetor(int *v,int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\n", v[i]);
    }
}

int fatorial(int n){
	if(n==0){
		return 1;
	}
	else{
		return n*fatorial(n-1);
	}
}

void inverterString(char *v, int n){
	if(n<=1){
		return;
	}
	else{
		int aux=v[0];
		v[0] = v[n-1];
		v[n-1] = aux;
		return inverterString(v+1, n-2);
	}
}

int somarElementos(int *v, int n){
	if(n==1){
		return v[0];
	}
	else{
		return v[n-1] + somarElementos(v,n-1);
	}
}


int palindroma(char *v, int n){
	if(n<=1){
		return 1;
	}
	else{
		if(v[0] != v[n-1]){
			return 0;
		}
		return palindroma(v+1, n-2);
	}
}

int contarCaractere(char *v, int n, char c){
	int cont=0;
	if(n<1){
		return 0;
	}
	else{
		if(v[0] == c){
			cont++;
		}
		return cont + contarCaractere(v+1,n-1,c);
	}
}

int somatorio(int n){
	if(n<=1){
		return 1;
	}
	else{
		return n+somatorio(n-1);
	}
}

/*int somaIgual(int v1*, int n1, int v2*, int n2, int x){
		if(n1 == 1 && n2 == 1){
				if()
		}
}
*/

float mediaVetor(int *v, int n){
	if(n==1){
		return v[0];
	}
	else{
		return ((somarElementos(v, n))/n);
	}
}

int pertence(int *v, int n, int x){
	if(n==1){
		if(v[0] == x){
			return 1;
		}else{
			return 0;
		}
	}
	if(v[0] == x){
		return 1;
	}else{
		pertence(v+1, n-1, x);
	}
	
}

int somaDeX(int *v, int n, int x){
	if(n==1){
		return 0;
	}
	else{
		
	}
}