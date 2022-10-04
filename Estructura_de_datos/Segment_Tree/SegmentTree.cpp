#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define MAX_N 1000000

using namespace std;

int N, arreglo[MAX_N];

struct node{
    int min, max;
}segmentTree[MAX_N*2];

void init(int inicio, int final, int nodoActual) { 
    if( inicio == final ) {
        segmentTree[nodoActual].max = arreglo[inicio];
        segmentTree[nodoActual].min = arreglo[inicio];
    } else {
        int mid = (inicio + final) / 2; 
        int nodoIzquierdo = 2 * nodoActual + 1; 
        int nodoDerecho   = 2 * nodoActual + 2;
        init(inicio, mid, nodoIzquierdo );
        // Ir por lado derecho 
        init(mid+1, final, nodoDerecho);

        segmentTree[nodoActual].max = 
            max(segmentTree[nodoIzquierdo].max,  segmentTree[nodoDerecho].max);
        segmentTree[nodoActual].min = 
            min(segmentTree[nodoIzquierdo].min, segmentTree[nodoDerecho].min);
    } 
}

node query(int inicio, int final, int nodoActual, int izquierda, int derecha ) {
    if(inicio >= izquierda && final <= derecha ) {
        return segmentTree[nodoActual];
    }
    
    int mid = (inicio + final ) / 2; 
    int nodoIzquierdo = 2 * nodoActual + 1; 
    int nodoDerecho   = 2 * nodoActual + 2;

    if(derecha <= mid ) {
        return query(inicio, mid, nodoIzquierdo, izquierda, derecha); 
    } else if(izquierda > mid) {
        return query(mid+1, final, nodoDerecho, izquierda, derecha);
    } else {
        node maxIzquierdo = query(inicio, mid, nodoIzquierdo,izquierda,derecha);
        node maxDerecho   = query(mid+1, final, nodoDerecho,izquierda,derecha);

        node result ; 
        result.max = max(maxIzquierdo.max, maxDerecho.max);
        result.min = min(maxIzquierdo.min, maxDerecho.min);
        return result;
    }      
}

void update(int inicio, int final, int nodoActual, int posicion, int valor ) {
    if(posicion < inicio || posicion > final )
        return ;
    if( inicio == final ){
        segmentTree[nodoActual].max = valor;
        segmentTree[nodoActual].min = valor;
    }else{ 
        int mid = (inicio + final ) / 2; 
        int nodoIzquierdo = 2 * nodoActual + 1; 
        int nodoDerecho   = 2 * nodoActual + 2;
        update(inicio, mid, nodoIzquierdo, posicion, valor);
        update(mid+1, final, nodoDerecho, posicion, valor);

        segmentTree[nodoActual].max = 
            max(segmentTree[nodoIzquierdo].max,  segmentTree[nodoDerecho].max); // -inf
        segmentTree[nodoActual].min = 
            min(segmentTree[nodoIzquierdo].min, segmentTree[nodoDerecho].min);  // inf
    }
}

int main(){
    input;
    scanf("%d",N);
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d",arreglo[i]);
    }

    init(0,N-1,0);
    update(0,N-1,0,0,-1);

    for (size_t i = 0; i < N*2-1; i++)
    {
        printf("[%d], ",segmentTree[i]);
    }
    printf("[%d]\n",segmentTree[N-1]);

    return 0;
}
