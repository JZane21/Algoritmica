#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define infinito 1000000
using namespace std;
int matrix[1000][1000];

void floy_Marshall(int n){
    int distancias[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            distancias[i][j] = infinito;
            if(i!=j){
                if(matrix[i][j]!=0){
                    distancias[i][j] = matrix[i][j];
                }
            }else{
                distancias[i][j] = 0; //dejando en 0 la diagonal
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(distancias[i][j]>distancias[i][k]+distancias[k][j]){
                    // este proceso se reemplaza la distancia mas
                    // grande con una nueva, pero esta es menor
                    // en comparacion a la otra
                    distancias[i][j] = distancias[i][k]+distancias[k][j];
                }
            }   
        }  
    }

    for (int i = 0; i < n; i++)
    {
        if(!i){
            printf("    %c",'X');
        }else{
            printf("    %d",i);
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if(!i){
            printf("%c : ",'X');
        }else{
            printf("%d : ",i);
        }
        for (int j = 0; j < n; j++)
        {
            if(distancias[i][j]>=infinito-100 || !i&&!j){
                printf("%c   ",'X');
            }else{
                printf("%d   ",distancias[i][j]);
            }
        }
        printf("\n");
    }
    

}

int main(){
    input;

    int vertices,aristas;
    scanf("%d %d",&vertices,&aristas);

    for (int i = 0; i < aristas; i++)
    {
        int vert1,vert2,peso;
        scanf("%d %d %d",&vert1,&vert2,&peso);
        matrix[vert1][vert2] = peso;
    }
    
    floy_Marshall(vertices+1);

    return 0;
}