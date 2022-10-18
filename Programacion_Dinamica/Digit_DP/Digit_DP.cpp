#include <bits/stdc++.h>
using namespace std;

string numero = "9107";
int dp[20][2][20][200];

int solve_dp(int pos, int mayor,int pares, int suma) {
    if(pos > numero.size()) {
        return 0;
    }
    if(pos == numero.size()) {
        if(pares >= 2) { 
            return 1;
        }
        else {
            return 0;
        }
    }
    if(dp[pos][mayor][pares][suma] == -1) { 
        int tope = 9;
        if(mayor == true) {
            tope = numero[pos]-'0';
        }
        dp[pos][mayor][pares][suma] = 0;
        for(int digito = 0; digito <= tope; digito++) {
            if(digito == tope ) {
                int total= suma +digito;
                int esPar = (total > 0) && (digito%2 == 1);
                dp[pos][mayor][pares][suma] += solve_dp(
                    pos+1, true, pares + esPar, total );
            }
            else {
                int total = suma + digito;
                int esPar = (total > 0) && (digito%2 == 1);
                dp[pos][mayor][pares][suma] += solve_dp(
                    pos+1, false, pares + esPar, total);
            }
        }
    }
    return dp[pos][mayor][pares][suma];
}



int main(){
    int  a = 20;
    int b = 30;
    
    numero = to_string(a-1);
    memset(dp, -1, sizeof(dp));
    int pares_hasta_a = solve_dp(1, true, 2,3);

    memset(dp, -1, sizeof(dp));
    numero = to_string(b);
    int pares_hasta_b = solve_dp(1, true, 2, 3);
    printf("%d\n",(pares_hasta_b-pares_hasta_a));
    return 0;
}