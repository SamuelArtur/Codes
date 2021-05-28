#include <stdio.h>
#include <stdlib.h>
#include "Ordena.h"

void swap(int *v, int i, int j){
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

void bubbleSortCre(int *v, int n){
	int i, j;
	for(i = 0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(v[j] > v[j+1]){
				swap(v, j,j+1);
			}
		}
	}
}

void bubbleSortDe(int *v, int n){
	int i, j;
	for(i = 0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(v[j] < v[j+1]){
				swap(v, j,j+1);
			}
		}
	}
}

void bubbleSortReCre(int *v, int n){
	if(n==1){
		return;
	}
	for(int i=0;i<n-1;i++){
		if(v[i] > v[i+1]){
			swap(v, i,i+1);
		}
	}
	bubbleSortReCre(v, n-1);
}

void selectionSortCre(int *v, int n){
	int menor;
	for(int i=0;i<n-1;i++){
		menor = i;
		for(int j=i+1;j<n;j++){
			if(v[menor] > v[j]){
				menor = j;
			}
		}
		if(i!=menor){
			swap(v, i, menor);
		}
	}
}

void selectionSortDe(int *v, int n){
	int maior;
	for(int i=0;i<n-1;i++){
		maior = i;
		for(int j=i+1;j<n;j++){
			if(v[maior] < v[j]){
				maior = j;
			}
		}
		if(i!=maior){
			swap(v, i, maior);
		}
	}
}

int buscaBinaria (int *v, int n, int x) {
   int e, m, d;                            
   e = 0; d = n-1;                         
   while (e <= d) {                        
      m = (e + d)/2;                       
      if (v[m] == x){ 
      	return m;
      }             
      else if (v[m] < x){ 
      	e = m + 1;
      }             
      else{ 
      	d = m - 1;
      }                      
   }                                      
   return 0;                              
}

int buscaBinariaRec(int *v, int n, int x) {
   int e, m, d;                            
   e = 0; d = n-1;                                       
   m = (e+d)/2;
   if(v[m] == x){
   	return m;
   }
   else if(v[m] < x){
   		return buscaBinariaRec(&v[m+1], d, x);
   }
   else{
   		return buscaBinariaRec(&v[e], m-1, x);
   }
}    
 
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeDe(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortCre(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; 
        mergeSortCre(arr, l, m);
        mergeSortCre(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void mergeSortDe(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; 
        mergeSortDe(arr, l, m);
        mergeSortDe(arr, m+1, r);
        mergeDe(arr, l, m, r);
    }
}  

void criaHeap(int* v, int i, int f){
	int aux = v[i];
	int j = i*2+1;
	while(j<=f){
		if(j<f){
			if(v[j] < v[j+1]){
				j++;
			}
		}
		if(aux<v[j]){
			v[i] = v[j];
			i=j;
			j = 2*i+1;
		}
		else{
			j = f+1;
		}
	}
	v[i] = aux;
}

void criaHeapDe(int* v, int i, int f){
	int aux = v[i];
	int j = i*2+1;
	while(j<=f){
		if(j>f){
			if(v[j] > v[j+1]){
				j++;
			}
		}
		if(aux>v[j]){
			v[i] = v[j];
			i=j;
			j = 2*i+1;
		}
		else{
			j = f+1;
		}
	}
	v[i] = aux;
}

void heapSortCre(int* v, int n){
	int i, aux;
	for(i=(n-1)/2;i>=0;i--){
		criaHeap(v, i, n-1);
	}
	for(i=n-1;i>=1;i--){
		swap(v,0, i);
		criaHeap(v, 0, i-1);
	}
}

void heapSortDe(int* v, int n){
	int i, aux;
	for(i=(n-1)/2;i>=0;i--){
		criaHeapDe(v, i, n-1);
	}
	for(i=n-1;i>=1;i--){
		swap(v,0, i);
		criaHeapDe(v, 0, i-1);
	}
}

void quickSort(int *v, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = v[(left + right) / 2];
     
    while(i <= j) {
        while(v[i] < x && i < right) {
            i++;
        }
        while(v[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = v[i];
            v[i] = v[j];
            v[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quickSort(v, left, j);
    }
    if(i < right) {
        quickSort(v, i, right);
    }
}