#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
using namespace std;

vector<pair<int, int>> grafo[100000];
vector<pair<int,int>> newGrafo[100000];
multiset<pair<int,int>> colaPrioridad;
int visitados[100000];
int conectado[100000];
int origenes[100000];
int pesosOrigenes[100000];
int numeroConexiones;

void Prim(int verticeInicial){
    colaPrioridad.insert(make_pair(0, verticeInicial));
    memset(visitados, false, sizeof(visitados));
    for (int i = 0; i < 100000; i++)
    {
        pesosOrigenes[i] = -1;
    }
    
    conectado[verticeInicial]=true;
    while (!colaPrioridad.empty())
    {
        //Paso 3: Sacar el nodo prioritario de la cola de prioridad
        pair<int, int> verticeActual = *colaPrioridad.begin();
        colaPrioridad.erase(colaPrioridad.begin());
        int vertice = verticeActual.second;//origen
        // printf("vertice actual: %d\n",vertice);
        if (!visitados[vertice])
        {
            visitados[vertice] = true;
            for (int i = 0; i < grafo[vertice].size(); i++)
            {
                //Paso 2: Agregar todos los vecinos del nodo a una cola
                // de prioridad
                int verticeVecino = grafo[vertice][i].second;
                int pesoVecino = grafo[vertice][i].first;
                if(!visitados[verticeVecino]){
                    // printf("[peso:%d, nodoVecino:%d] ",pesoVecino,verticeVecino);
                    if(origenes[verticeVecino]==0 || (pesoVecino<pesosOrigenes[verticeVecino]
                    && pesosOrigenes[verticeVecino]!=-1)){
                        origenes[verticeVecino]=vertice;
                        pesosOrigenes[verticeVecino]=pesoVecino;
                    }
                    colaPrioridad.insert(make_pair(pesoVecino, verticeVecino));
                }
            }
            if(!conectado[vertice]){
                conectado[vertice] = true;
                newGrafo[vertice].push_back(
                            make_pair(pesosOrigenes[vertice],origenes[vertice]));
                        newGrafo[origenes[vertice]].push_back(
                            make_pair(pesosOrigenes[vertice],vertice));
            }
            // printf("\n");
        }
        //Paso 4: Repetir el paso 2 y 3
    }
    
    
}

int main(){
    input;
    //pidiendo numero de aristas
    scanf("%d",&numeroConexiones);
    set <int> nodos;
    for (int i = 0; i < numeroConexiones; i++)
    {
        //creacion del grafo
        int vertice1,vertice2,peso;
        scanf("%d %d %d",&vertice1,&vertice2,&peso);
        if(!(nodos.find(vertice1)!=nodos.end())){
            nodos.insert(vertice1);
        }
        if(!(nodos.find(vertice2)!=nodos.end())){
            nodos.insert(vertice2);
        }
        grafo[vertice1].push_back(make_pair(peso,vertice2));
        grafo[vertice2].push_back(make_pair(peso,vertice1));
    }
    int inicio;
    //Paso 1: Seleccionar desde que nodo iniciar el Algoritmo Prim
    scanf("%d",&inicio);
    Prim(inicio);
    for (auto it = nodos.begin(); it != nodos.end(); ++it)
    {
        printf("nodo %d: -> ",*it);
        for (int i = 0; i < newGrafo[*it].size(); i++)
        {
            printf("[peso:%d, nodoVecino:%d] ",newGrafo[*it][i].first,newGrafo[*it][i].second);
        }
        printf("\n");
    }
    return 0;
}