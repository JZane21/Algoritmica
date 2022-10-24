#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define infinito 1000000
using namespace std;
int longValue[infinito];
int valores[infinito];

int LIS(int n){
    int biggestSequence=0;

    for (size_t k = 0; k < n; k++)
    {
        longValue[k]=1;
        for (size_t i = 0; i < k; i++)
        {
            if(valores[i]<valores[k]){
                longValue[k]=max(longValue[k],longValue[i]+1);
                if(biggestSequence<longValue[k]){
                    biggestSequence=longValue[k];
                }
            }
        }
    }

    return biggestSequence;
}

int main(){

    input;
    int n;
    scanf("%d",&n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d",&valores[i]);
    }
    printf("%d\n",LIS(n));

    return 0;
}