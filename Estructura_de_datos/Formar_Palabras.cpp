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
        if(palabra[i]!=' '){
            int letra = palabra[i] - 'a';
            if(nodoActual->herencia[letra]==NULL){
                nodoActual->herencia[letra] = new nodito();
            }
            nodoActual = nodoActual->herencia[letra];
            nodoActual->letraActual = palabra[i];
        }
    }
    nodoActual->finalPalabra = true;
}

bool formarPalabra(string palabra){
    int n=palabra.length();
    bool vectorAux[n];
    for (size_t i = 0; i < n; i++)
    {
        vectorAux[i]=false;
    }
    for (size_t i = 0; i < n; i++)
    {
        nodito *nodoActual = trie;
        for (size_t j = i; j < n; j++)
        {
            if(palabra[j]==' '){
                continue;
            }
            int letra = palabra[j] - 'a';
            if(nodoActual->herencia[letra]!=NULL){
                nodoActual = nodoActual->herencia[letra];
                if(nodoActual->finalPalabra){
                    vectorAux[j] = true;
                }
            }else{
                j=n;
            }
        }
    }
    return vectorAux[n-1];
}

int main(){
    iniciarTrie();
    int nInsertar;
    cin>>nInsertar;
    string palabras[nInsertar];
    string word;
    int n=0;
    while(nInsertar--){
        word.clear();
        cin>>word;
        insertarPalabra(word);
        palabras[n] = word;
        n++;
    }
    word.clear();
    cin>>word;
    cout<<"\n"<<word<<": "<<formarPalabra(word)<<endl;
    
    
    return 0;
}