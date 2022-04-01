int max(int *v, int ini, int fim){
    int m = ini;
    for (int j = ini+1; j<=fim; j++){
        if (v[j] > v[m]){
            m = j;
        }
    }
    return m;
}
void troca(int *v, int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}
void SelectionSort(int *v, int n){
    int i,m;
    for(i = n-1; i > 0;i--){
        m=max(v,0,i);
        troca(v,i,m);
    }
}

void insertion(int* v, int k){
    int x = v[k];
    int i = k-1;
    while(i >= 0 && x < v[i] ){
        v[i+1] = v[i];
        i--;
    }
    v[i+1] = x;
}

void InsertionSort(int *v, int n){
    int j;
    for (j=1;j<n;j++){
        insertion(v,j);
    }
}

void trocar(int*v, int i, int j){
    int x = v[i];
    v[i] = v[j];
    v[j] = x; 
}
int partition (int*v, int p, int r){
    int x;
    int i, j;
    x=v[r];
    i = p-1;
    for (j=p;j<r;j++){
        if(v[j] <= x){
            i++;
            trocar(v,i,j);
        }
    }
    trocar(v,i+1,r);
    return i+1;
}

void QuickSort(int *v, int e, int d){
    if (e<d){
        int q = partition(v,e,d);
        QuickSort(v,e,q-1);
        QuickSort(v,q+1,d);
    }
}

int esq(int i){
    return (2*i)+1;
}
int dir(int i){
    return esq(i)+1;
}
void max_heapify(int *v, int i, int th){
    int e, d;
    int maior = i;
    e = esq(i);
    d = dir(i);
    if ((e<th)&&(v[e]>v[i])){
        maior = e;
    }
    if (d<th && v[d] > v[maior]){
        maior = d;
    }
    if (maior != i){
        trocar(v, i, maior);
        max_heapify(v, maior,th);
    }
}

void BuildMaxHeap(int *v, int n){
    int i;
    for (i=n/2; i>=0; i--){
        max_heapify(v,i,n);
    }
}

void HeapSort(int *v, int n){
    int i;
    BuildMaxHeap(v,n);
    for (i = n; i > 0; i--){
        trocar(v,0,i);
        max_heapify(v,0,i);
    }
}
