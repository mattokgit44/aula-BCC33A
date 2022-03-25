#pragma once

typedef struct
{
    char** itens;
    int n;
} ListaCompras;

ListaCompras* LC_Criar(char *itens);
static void merge(char** v, int p, int q, int r);
static void mergeSort(char** v, int e, int d);
void LC_Ordenar(ListaCompras* lc);
char* LC_SemRepeticoes(ListaCompras* lc);
void LC_Imprimir(ListaCompras* lc);
void LC_Destruir(ListaCompras* lc);

#define MAX_ITENS 1000
#define MAX_TAM 21
#define BUF_LEN ((MAX_ITENS * MAX_TAM) + 1)