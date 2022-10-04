#include<bits/stdc++.h>
#define MAX_N 10000000
#define input freopen("in.txt","r",stdin)
using namespace std;
int N=0, arreglo[MAX_N];
queue<int> swapAnswer;
map<int,int> swapMap;
struct node{
    int min;
    int max;
}segmentTree[MAX_N*2];

map<int,int> posiciones;

int lugar=0;

void init(int inicio, int final, int nodoActual) {

    if( inicio == final ) {
        segmentTree[nodoActual].min = arreglo[inicio];
        segmentTree[nodoActual].max = arreglo[inicio];
        posiciones[arreglo[inicio]] = nodoActual;
        swapMap[arreglo[inicio]] = lugar;
        lugar++;
    } else {
        int mid = (inicio + final) / 2; 
        int nodoIzquierdo = 2 * nodoActual + 1; 
        int nodoDerecho   = 2 * nodoActual + 2;
        // Ir por lado izquierdo
        init(inicio, mid, nodoIzquierdo );
        // Ir por lado derecho 
        init(mid+1, final, nodoDerecho);

        
        segmentTree[nodoActual].min = 
            min(segmentTree[nodoIzquierdo].min,  segmentTree[nodoDerecho].min);
        
        segmentTree[nodoActual].max = 
            max(segmentTree[nodoIzquierdo].max,  segmentTree[nodoDerecho].max);
    }


    
}

void update(int inicio, int final, int nodoActual, int posicion, int valor ) {
    if(posicion < inicio || posicion > final ) {
        return ;
    }
    if( inicio == final ) {
        segmentTree[nodoActual].max = valor;
        segmentTree[nodoActual].min = valor;
    } else { 

        int mid = (inicio + final ) / 2; 
        int nodoIzquierdo = 2 * nodoActual + 1; 
        int nodoDerecho   = 2 * nodoActual + 2;
        // Actualizar por lado izquierdo
        update(inicio, mid, nodoIzquierdo, posicion, valor );
        // Actualizar por lado derecho 
        update(mid+1, final, nodoDerecho, posicion, valor );
        segmentTree[nodoActual].max = 
            max(segmentTree[nodoIzquierdo].max,  segmentTree[nodoDerecho].max);
        if(segmentTree[nodoIzquierdo].min>0 && segmentTree[nodoDerecho].min>0){
            segmentTree[nodoActual].min = 
            min(segmentTree[nodoIzquierdo].min, segmentTree[nodoDerecho].min);
            return;
        }else if(segmentTree[nodoIzquierdo].min<0 && segmentTree[nodoDerecho].min>0){
            segmentTree[nodoActual].min = segmentTree[nodoDerecho].min;
            return;
        }else if(segmentTree[nodoDerecho].min<0 && segmentTree[nodoIzquierdo].min>0){
            segmentTree[nodoActual].min = segmentTree[nodoIzquierdo].min;
            return;
        }else{
            segmentTree[nodoActual].min = -1;
            return;
        }

    }
}





void TurboSort(){
    int sizeArr=0;
    int sizeArr2=0;
    int sizeExtra=0;
    bool primeraVez=false;

    map<int,pair<int,int>> restas;
    set<int> Ssort;

    while (sizeExtra<N && N!=1)
    {   
        int smallest = segmentTree[0].min;
        int biggest = segmentTree[0].max;

        int swapSmallest = swapMap.at(smallest);
        int swapBiggest = (N-1)-swapMap.at(biggest);

        int swapf1=0;
        int swapf2=0;

        if (sizeExtra+1==N)
        {
            break;
        }
        
        //OPCION 1:

        // if(primeraVez){
        //     for(int i:Ssort){
        //         if(smallest>i){
        //             swapf1--;
        //         }
        //     }
        //     Ssort.insert(smallest);
        //     for(int i:Ssort){
        //         if(biggest<i){
        //             swapf2--;
        //         }
        //     }
        //     if(swapSmallest>swapMap.at(biggest)){
        //         swapBiggest--;
        //     }
        //     Ssort.insert(biggest);
        //     swapf1+=swapSmallest;
        //     swapf2+=swapBiggest;
        // }else{
        //     Ssort.insert(smallest);
        //     Ssort.insert(biggest);

        //     if(swapSmallest>swapMap.at(biggest)){
        //         swapBiggest--;
        //     }
        //     swapf1 = swapSmallest;
        //     swapf2 = swapBiggest;

        //     primeraVez=true;
        // }
        

        //OPCION 2:

        if(primeraVez){
            //Min
            for (int i = swapSmallest-1; i >=0 ; i--)
            {
                if(Ssort.find(i)!=Ssort.end()){
                    if(restas[i].first!=0){ 
                        swapSmallest-=restas[i].first;
                        restas[swapSmallest].first = restas.at(i).first-1;
                        restas[swapSmallest].second = restas.at(i).second;
                        break;
                    }
                }
                if(i==0){
                    restas[swapSmallest].first = -1;
                    restas[swapSmallest].second = (-1)*(Ssort.size()+1);
                }
            }
            for (int i : Ssort)
            {
                if(swapSmallest>i){
                    restas[i].second -= 1;
                }else if(swapSmallest<i){
                    restas[i].first -=1 ;
                }
            }
            
            Ssort.insert(swapSmallest);

            //Max
            for (int i = swapMap.at(biggest)+1; i < N; i++)
            {
                if(Ssort.find(i)!=Ssort.end()){
                    if(restas[i].second!=0){
                        swapBiggest -= restas[i].second;
                        restas[swapMap.at(biggest)].second = restas[i].second-1;
                        restas[swapMap.at(biggest)].first = restas[i].first;
                        break;
                    }
                }
                if(i+1==N){
                    restas[swapMap.at(biggest)].second = -1;
                    restas[swapMap.at(biggest)].first = (-1)*(Ssort.size()+1);
                }
            }
            for (int i : Ssort)
            {
                if(swapMap.at(biggest)>i){
                    restas[i].second -= 1;
                }else if(swapMap.at(biggest)<i){
                    restas[i].first -= 1;
                }
            }
            
            
            Ssort.insert(swapMap.at(biggest));
            
        }else{
            if(swapSmallest>swapMap.at(biggest)){
                restas[swapMap.at(smallest)].first = -2;
                restas[swapMap.at(biggest)].first = -1;

                restas[swapMap.at(biggest)].second = -1;
                restas[swapMap.at(smallest)].second = -2;
                              
            }else{
                restas[swapMap.at(smallest)].first = -1;
                restas[swapMap.at(biggest)].first = -2;

                restas[swapMap.at(biggest)].second = -2;
                restas[swapMap.at(smallest)].second = -1;
            }
            primeraVez=true;
        }


        printf("%d\n", swapf1);
        sizeExtra++;
        if(sizeExtra<N){
            printf("%d\n", swapf2);
            sizeExtra++;
        }

        update(0,N-1,0,swapSmallest,-1);
        update(0,N-1,0,swapMap.at(biggest),-1);
        sizeArr++;
    }
    if(N%2==1){
        printf("%d\n",0);
    }

}

void TurboSort2(){
    int sizeArr=0;
    int sizeArr2=0;
    int sizeExtra=0;
    bool primeraVez=false;

    map<int,pair<int,int>> restas;
    set<int> Ssort;
    int maxMin[N];
    int swapsElements[N];
    while(sizeExtra<N){
        int smallest = segmentTree[0].min;
        int biggest = segmentTree[0].max;
        
        int swapSmallest = swapMap.at(smallest);
        int swapBiggest = swapMap.at(biggest);

        maxMin[sizeExtra] = smallest;
        swapsElements[sizeExtra] = swapSmallest;
        if(sizeExtra+1<N){
            maxMin[sizeExtra+1] = biggest;
            swapsElements[sizeExtra+1] = swapBiggest;
        }

        update(0,N-1,0,swapMap.at(smallest),-1);
        update(0,N-1,0,swapMap.at(biggest),-1);
        sizeExtra+=2;
    }
    for (size_t i = 0; i < N; i++)
    {
        
    }
    
    
}



int main(){
    input;

    cin>>N;
    for (size_t i = 0; i < N; i++)
    {
        int element;
        scanf("%d", &element);
        arreglo[i] = element;
    }

    init(0,N-1, 0);

    TurboSort2();
    

    return 0;
}