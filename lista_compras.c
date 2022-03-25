#include "lista_compras.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

ListaCompras* LC_Criar(char *itens)
{
    ListaCompras* nova = malloc(sizeof(ListaCompras));
    nova->itens = malloc(sizeof(char*) * MAX_ITENS);
    int n = 0;
    char *item = strtok(itens, " ");
    while (item != NULL){
        nova->itens[n] = malloc(sizeof(char) * (strlen(item)+1));
        strcpy(nova->itens[n], item);
        n++;
        item = strtok(NULL, " ");
    }
    nova->n = n;
    return nova;
}

static void merge(char** v, int p, int q, int r)
{
    char** e, **d;
    int i, j, k;
    int n1 = q-p+1;
    int n2 = r-q;
    char sentinela[] = "zzzzzz";
    e = malloc(sizeof(char*) * (n1+1));
    d = malloc(sizeof(char*) * (n2+1));
    for(i = 0; i < n1; i++)
        e[i] = v[p+i];
    for(j = 0; j < n2; j++)
        d[j] = v[q+1+j];
    e[n1] = sentinela;
    d[n2] = sentinela;
    i = 0;
    j = 0;
    for(k = p; k <= r; k++)
    {
        if(strcmp(e[i], d[j]) <= 0)
        {
            v[k] = e[i];
            i++;
        }
        else
        {
            v[k] = d[j];
            j++;
        }
    }
    free(e);
    free(d);
}

static void mergeSort(char** v, int e, int d)
{
    if (e < d)
    {
        int m = (e+d)/2;
        mergeSort(v, e, m);
        mergeSort(v, m+1, d);
        merge(v,e,m,d);
    }
}

void LC_Ordenar(ListaCompras* lc)
{
    mergeSort(lc->itens, 0, lc->n-1);
}

char* LC_SemRepeticoes(ListaCompras* lc)
{
    LC_Ordenar(lc);
    char* saida = malloc(sizeof(char) * BUF_LEN);
    saida[0] = '\0';
    strcat(saida, lc->itens[0]);
    strcat(saida, " ");
    char* ultimaSaida = lc->itens[0];
    for (int i = 0; i < lc->n; i++)
    {
        if (strcmp(ultimaSaida, lc->itens[i])!=0)
        {
            ultimaSaida = lc->itens[i];
            strcat(saida, ultimaSaida);
            strcat(saida, " ");
        }
    }
    return saida;
}

void LC_Imprimir(ListaCompras* lc)
{
    for (int i = 0; i < lc->n; i++)
    {
        printf("%s, ", lc->itens[i]);
    }
    printf("\n");
}

void LC_Destruir(ListaCompras* lc)
{
    for (int i = 0; i < lc->n; i++)
    {
        free(lc->itens[i]);
    }
    free(lc->itens);
    free(lc);
}