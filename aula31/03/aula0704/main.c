#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "ordenacao.h"
#include "utils.h"


bool twosum_bruteforce(int*v, int n, int x){
    int i,j;
    for(i=0; i < n-1; i++){
        for (j = 0; j < n-1; j++){
            if((v[i] + v[j]) == x){
                printf("%d + %d = %d\n", v[i], v[j], x);
                return true;
            }
        }
    }
        return false;
}

int main(int argc, char** argv){
    //int v[]= {2, -1, 5, 8, 7, 4};
    //int n = 12;
    int n = atoi(argv[1]);
    int *v = random_vector(n, n, 999);
    quicksort(v, n);
    twosum_bruteforce(v, n, 80);

    return EXIT_SUCCESS;
}
