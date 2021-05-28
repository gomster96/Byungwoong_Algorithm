#include<bits/stdc++.h>

using namespace std;

int N, K;
int dp[1001][1001];
const int MOD = 10007;
int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        dp[i][1] = i;
        dp[i][i] = 1;
        dp[i][0] = 1;
    }

    for(int i = 2; i<=N; i++){
        for(int j= 2; j<=K; j++){
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%MOD;
        }
    }
    cout << dp[N][K] << endl;

    return 0;
}


