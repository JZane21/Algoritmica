#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define Maximo 100000
using namespace std;

int parent[Maximo];
int cont[Maximo];
int rango[Maximo];

int n;
void init() {
    for(int i=0;  i<= n; i++) {
        parent[i] = i;
        rango[i] = 0;
        cont[i] = 1;
    }
    
}

int find(int x) {
    return x==parent[x] ? x :
        parent[x] = find(parent[x]);
}

void unionRango(int x,int y) { 
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
        cont[yRaiz] += cont[xRaiz];
    } else {
        parent[xRaiz] = yRaiz;
        cont[xRaiz] += cont[yRaiz];
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

int main() {
    input;
    scanf("%d",n);
    init();
    int nrounionRangoes; 
    scanf("%d",nrounionRangoes);
    while(nrounionRangoes--) {
        int x,y;
        cin>>x>>y; 
        scanf("%d",x);
        scanf("%d",y);
        unionRango(x,y);
    }
    for(int i=0;i<=n;i++){
        printf("[%d] ",i);
    }
    printf("\n");
    for(int i=0;i<=n;i++){
        printf("[%d] ",parent[i]);
    }
    printf("\n");
    for(int i=0;i<=n;i++){ 
        printf("[%d] ",rango[i]);
    }
    printf("\n");
    int sol = -1;
    for(int i=0;i<=n;i++){
        if(i == parent[i]) {
            sol = max(sol,cont[i]);
        }
    }
    printf("%d\n",sol);

    return 0;
}