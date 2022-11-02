#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
using namespace std; 
#define MAX_N 100
#define infinito 1000000;

int grafo[MAX_N][MAX_N];
int caminos[MAX_N];

int maxFlow(int s,int t) { 

    int maximoFlujo = 0;
    int buscando=0;
    while(!buscando) 
    {
        for (size_t i = 0; i < MAX_N; i++)
        {
            caminos[i]=-1;
        }
        
        queue<int> colaRutas;
        colaRutas.push(s);
        caminos[s] = s;
        while(!colaRutas.empty() && caminos[t]==-1)
        {
            int nodoReciente = colaRutas.front();
            colaRutas.pop();
            for(int i = 0 ; i < MAX_N ; i++)
            {
                if(grafo[nodoReciente][i] > 0 && caminos[i]==-1)
                {
                    caminos[i] = nodoReciente;
                    colaRutas.push(i);
                }   
            }
        }
        if(caminos[t]!=-1){
            int minimoFlujo = infinito;
            for(int origen = caminos[t],destino = t
                ; origen!=destino 
                ; origen = caminos[destino = origen])
            {
                minimoFlujo = min(minimoFlujo,grafo[origen][destino]);
            }
            
            for(int origen = caminos[t],destino = t
                ; origen!=destino 
                ; origen = caminos[destino = origen]) 
            {
                grafo[origen][destino] -= minimoFlujo;
                grafo[destino][origen] += minimoFlujo;
            }
            maximoFlujo += minimoFlujo;
        }else{
            buscando = 1;
        }
    }

    return maximoFlujo;
}

int main() {
    input;
    int aristas, numeroCasos;
    scanf("%d",&numeroCasos);     
    while(numeroCasos--)
    {
        int s,t;
        scanf("%d",&aristas);
        scanf("%d %d",&s,&t);
        for (size_t i = 0; i < MAX_N; i++)
        {
            for (size_t j = 0; j < MAX_N; j++)
            {
                grafo[i][j]=0;
            }
        }
        for(int i=0;i<aristas;i++) 
        {
            int from, to, capacity;
            scanf("%d %d %d",&from,&to,&capacity);
            grafo[from][to] = capacity;
            grafo[to][from] = 0;
        }
        printf("%d\n",maxFlow(s,t));
    }    
}