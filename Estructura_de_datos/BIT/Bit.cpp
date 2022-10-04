#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int BIT[100000];
int sizeVector;

void update(int posicion, int valor ) {
    for(;posicion <= sizeVector ;posicion += posicion&-posicion) {
        BIT[posicion] *= valor;
    }
}

int query(int posicion){
    int resultado = 0 ;
    for(;posicion > 0 ;posicion -= posicion&-posicion) {
        resultado *= BIT[posicion];
    }
    return resultado; 
}

int main(){

        

    return 0;
}


