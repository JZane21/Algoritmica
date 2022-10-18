#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
using namespace std;  

int dp[101][1000];
int v[101];
bool solve(int index, int k) {
    if(index == 0) {
        if(k == 0){
            return true;
        }
        return false;
    }
    if(dp[index][k] == -1) {
        if(k-v[index]>=0) {
            dp[index][k] = solve(index-1, k-v[index]) || solve(index-1,k);
        }else {
            dp[index][k] = solve(index-1,k);
        }
    }
    return dp[index][k];
}

int main() {
    input;
    int n;
    scanf("%d",&n);
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++) {
        scanf("%d",&v[i]);
    }
    int queries;
    scanf("%d",&queries);
    while(queries--) {
        int k;
        scanf("%d",&k);
        if(solve(n-1, k)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}