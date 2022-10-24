#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define infinito 1000000
using namespace std;

void Rod_Cutting(int p[],int n){
    int r[n+1],s[n+1];
    for (size_t i = 0; i <= n; i++)
    {
        r[i] = s[i] = i;
    }
    r[0]=0;
    for (size_t j = 1; j <= n; j++)
    {
        int q = -infinito;
        for (size_t i = 1; i <= j; i++)
        {
            if(q < p[i]+r[j-i]){
                q = p[i]+r[j-i];
                s[j]=i;
            }
        }
        r[j]=q;
    }
    for (size_t i = 0; i <= n; i++)
    {
        printf("%d ",r[i]);
    }
    printf("\n");
}

int main(){

    input;
    int n;
    scanf("%d",&n);
    int p[n+1];
    p[0]=0;
    for (size_t i = 1; i <= n; i++)
    {
        scanf("%d",&p[i]);
    }
    Rod_Cutting(p,n);

    return 0;
}