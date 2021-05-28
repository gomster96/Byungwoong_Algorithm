#include<bits/stdc++.h>

using namespace std;

#define mine

int N;
int dp[11][1002];
const int MOD = 10007;
int incNum(int n, int c){
    if(c <= 0) return 0;
    if(c == 1) return dp[n][1];
    int& ret = dp[n][c];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=n; i<10; i++){
        ret = (ret+incNum(i, c-1))%MOD;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<10; i++) dp[i][1] = 10-i;

    cout << incNum(0, N) << endl;

    return 0;
}


