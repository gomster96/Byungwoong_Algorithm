#include<bits/stdc++.h>

using namespace std;

#define mine


int main(){
    ios_base::sync_with_stdio(false);
    freopen("../input.txt","rt",stdin);
    
    int T, N, M, i, j, k;
    long long dp[31][31];
    memset(dp, 0, sizeof(dp));

    // 1개 뽑을때 i개 있을때 경우의 수들
    for(i=1; i<31; i++) dp[1][i] = i;

    for(i=2; i<31; i++){
        for(j=i; j<31; j++){
            for(k = j-1; k>=i-1; k--) dp[i][j] += dp[i-1][k];
        }
    }
    

    return 0;
}


