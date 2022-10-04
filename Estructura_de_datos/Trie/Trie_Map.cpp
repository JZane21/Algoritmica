#include<bits/stdc++.h>
using namespace std;

struct nodito{
    char letraActual;
    bool finalPalabra=false;
    map<int,nodito*> herencia;
    int nivel=0;
}*trie;

void iniciarTrie(){
    trie = new nodito();
}

void insertarPalabra(string palabra){
    nodito *nodoActual = trie;
    int n = palabra.length();
    int incrementoNivel;
    for (size_t i = 0; i < palabra.length(); i++)
    {
        int letra = palabra[i] - 'a';
        if(nodoActual->herencia.find(letra)==nodoActual->herencia.end()){
            nodoActual->herencia[letra] = new nodito();

        }else{
            incrementoNivel++;
            nodoActual->herencia[letra]->nivel = incrementoNivel;
        }
        nodoActual = nodoActual->herencia[letra];
        nodoActual->letraActual = palabra[i];
    }
    nodoActual->finalPalabra = true;
}

bool buscarPalabra(string palabra){
    nodito *nodoActual = trie;
    int n = palabra.length();
    for (size_t i = 0; i < palabra.length(); i++)
    {
        int letra = palabra[i] - 'a';
        if(nodoActual->herencia[letra]!=NULL){
            nodoActual = nodoActual->herencia[letra];
            nodoActual->letraActual = palabra[i];
        }else{
            return false;
        }
    }
    return nodoActual->finalPalabra;
}

int main(){
    iniciarTrie();
    int nInsertar;
    cin>>nInsertar;
    string word;
    while(nInsertar--){
        word.clear();
        cin>>word;
        insertarPalabra(word);
    }
    word.clear();
    cin>>word;
    cout<<buscarPalabra(word)<<endl;
    return 0;
}