#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define limiteN 100000

using namespace std; 

int padres[limiteN];
int rango[limiteN];

int n, m;

void init() {
    for(int i=0;  i<= limiteN; i++) {
        padres[i] = i;
        rango[i] = 0;
    }
}

int find(int x) {
    if(x == padres[x]) {
        return x;
    }
    else {
        padres[x] = find(padres[x]);
        return padres[x];
    }
}

bool mismoComponente(int nodoA,int nodoB) {
    return find(nodoA) == find(nodoB);
}

void unionRango(int x,int y) {
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        padres[yRaiz] = xRaiz;
    } else {
        padres[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

struct Arista{ 
    int origen;
    int destino; 
    double peso; 
    Arista(){

    }
    bool operator<(const Arista &a) const {
        if(peso == a.peso) {
            return origen < a.origen;
        } else {
            return peso < a.peso;
        }
    }
}aristas[limiteN]; 

Arista MST[limiteN];

int numAristasArbol;
double kruskal(int nroNodos, int nroAristas) {
    
    int origen, destino;
    double peso;

    double total = 0;

    numAristasArbol = 0;

    init();

    sort(aristas,aristas + nroAristas);

    for (int i = 0; i < nroAristas; i++)
    {
        origen = aristas[i].origen;
        destino = aristas[i].destino;
        peso = aristas[i].peso;

        if(!mismoComponente(origen,destino)) { 
            total += peso; 
            unionRango(origen,destino);
            MST[numAristasArbol] = aristas[i];
            numAristasArbol++;
            
        }
    }
    return total;
}

int main(){
    input;
    int casos;
    scanf("%d",&casos);
    while(casos--) {
        scanf("%d %d",&n,&m);
        if(n==-1 || m==-1){
            return 0;
        }
        for(int i=0; i<m; i++) {
            scanf("%d %d %lf",&aristas[i].origen,&aristas[i].destino,&aristas[i].peso);
        }
        printf("%.2lf\n",kruskal(n,m));
        for(int i = 0 ;i <numAristasArbol;i++) {
            printf("Origen: %d | Destino: %d | Peso: %lf\n"
            ,MST[i].origen,MST[i].destino,MST[i].peso);
        }
    }

    return 0;
}