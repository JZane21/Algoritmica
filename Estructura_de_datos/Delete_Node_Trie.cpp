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

bool sinHijos(nodito* nodoActual){
    for (size_t i = 0; i < 27; i++)
    {
        if(nodoActual->herencia[i]){
            return false;
        }
    }
    return true;
}

nodito* eliminarPalabra(nodito* nodoActual,string palabra, int size=0){
    if(buscarPalabra(palabra)){
        int n = palabra.length();
        if(size==n){
            if(nodoActual->finalPalabra){
                nodoActual->finalPalabra = false;
            }
            if(sinHijos(nodoActual)){
                nodoActual = NULL;
            }
            return nodoActual;
        }

        int letra = palabra[size] - 'a';
        nodoActual->herencia[letra] =  eliminarPalabra(nodoActual->herencia[letra],palabra,size+1);
        
        if(sinHijos(nodoActual) && (!nodoActual->finalPalabra)){
            nodoActual = NULL;
        }

        return nodoActual;


        // for (size_t i = 0; i < n; i++)
        // {
        //     int letra = palabra[i] - 'a';
        //     cout<<i+1<<endl;
        //     if(nodoActual->finalPalabra && nodoActual->herencia[letra]!=NULL
        //     && ((i+1) == n)){
        //         nodoActual->finalPalabra = false;
        //         entrePalabras = true;
        //     }else if(nodoActual->finalPalabra && nodoActual->herencia[letra]!=NULL){
        //         contador++;
        //     }
        // }
        // if(!entrePalabras){
        //     nodito *nodoActual = trie;
        //     for (size_t i = 0; i < n; i++)
        //     {
        //         int letra = palabra[i] - 'a';
        //         if(nodoActual->finalPalabra){
        //             contador--;
        //         }
        //         if(contador<=0){

        //             nodoActual->herencia[letra]=NULL;
        //             i=n;
        //         }
        //     }
        // }
    }else{
        return NULL;
    }
}

int main(){

    /*
    INPUT:
    4
    hola
    hooola
    hoola
    hi
    hoola

    OUTPUT:
    0
    1
    1
    */

    iniciarTrie();
    int n;
    cin>>n;
    string word;
    while(n--){
        word.clear();
        cin>>word;
        insertarPalabra(word);
    }
    word.clear();
    cin>>word;
    eliminarPalabra(trie,word);
    cout<<buscarPalabra(word)<<endl;
    word="hola";
    cout<<buscarPalabra(word)<<endl;
    word="hooola";
    cout<<buscarPalabra(word)<<endl;
    return 0;
}