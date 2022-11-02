#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
using namespace std;
int n; 
int v[100010];
int numero;
queue <int> respuesta;
bool f(int k) {
    return v[k] >= numero ? true : false;
}


int binarySearch() {
    long  left = 0;
    long long  right = n*2-1;
    int mid = (left + right) /2; 
    while( left<right ) {
        if(f(mid)) {
            right = mid -1;
            respuesta.push(v[mid]);
        }
        else{
            left = mid+1;
        }
        mid = (left+right)/2;
    }
    return mid;
}

int main() {
    input;
    int t; 
    scanf("%d",&t);
    
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&v[i]);
        }
        scanf("%d",&numero);
        binarySearch();
        while (!respuesta.empty())
        {
            printf("%d ",respuesta.front());
            respuesta.pop();
        }
        printf("\n");
        memset(v,0,sizeof(v));
    }

    return 0;
}