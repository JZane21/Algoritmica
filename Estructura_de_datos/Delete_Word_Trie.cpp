#include<bits/stdc++.h>
using namespace std;

struct nodito{
    char letraActual;
    bool finalPalabra;
    struct nodito *herencia[27];
    nodito(){
        finalPalabra = false;
    }
}*trie;

void iniciarTrie(){
    trie = new nodito();
}

void insertarPalabra(string palabra){
    nodito *nodoActual = trie;
    int n = palabra.length();
    for (size_t i = 0; i < palabra.length(); i++)
    {
        int letra = palabra[i] - 'a';
        if(nodoActual->herencia[letra]==NULL){
            nodoActual->herencia[letra] = new nodito();
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

int wordD;
bool stop;
void eliminarPalabra(nodito* nodoActual,string palabra){
    if(buscarPalabra(palabra)){
        if(wordD != palabra.length()){
            int letra = palabra[wordD] - 'a';
            wordD++;
            eliminarPalabra(nodoActual->herencia[letra],palabra);
        }else{
            nodoActual->finalPalabra=false;
        }
        if(!stop){
            if(nodoActual->herencia!=NULL){
                stop=true;
            }else{
                nodoActual = NULL;
            }
        } 
    }else{
        cout<<"NO existe la palabra"<<endl;
    }
}

int main(){
    iniciarTrie();
    int nBorrar, nInsertar;
    cin>>nInsertar>>nBorrar;
    string palabras[nInsertar];
    string word;
    int i=0;
    while(nInsertar--){
        word.clear();
        cin>>word;
        insertarPalabra(word);
        palabras[i] = word;
        i++;
    }
    while(nBorrar--){
        word.clear();
        cin>>word;
        eliminarPalabra(trie,word);
    }
    cout<<"Palabras del Trie"<<endl;
    for(int j=0;j<i;j++){
        cout<<palabras[j]<<": "<<buscarPalabra(palabras[j])<<endl;
    }
    return 0;
}