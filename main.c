#include <stdio.h>
#include <stdlib.h>
#include "lista_compras.h"

int main(int argc, char** argv){
    char listona[] = "pimenta ovo carne frango superbonder frango ovo pimenta farofa ovo pimenta frango carne whey creatina whey pre_treino creatina frango superbonder ketchup whey_de_morango whey_de_tapioca whey_de_chocolate";

    ListaCompras* lc = LC_Criar(listona);
    LC_Imprimir(lc);
    char *s = LC_SemRepeticoes(lc);
    printf("%s\n", s);
    LC_Destruir(lc);

    return EXIT_SUCCESS;
}
