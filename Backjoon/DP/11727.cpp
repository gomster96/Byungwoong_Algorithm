#include<bits/stdc++.h>

using namespace std;

#define mine

int N;
int dp[1001];
const int MOD = 10007;
int tiling(int n){
    if(n == 1) return 1;
    if(n == 2) return 3;
    int& ret = dp[n];
    if(ret != -1) return ret;
    return ret = (tiling(n-1) + 2*tiling(n-2))%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    memset(dp, -1, sizeof(dp));

    cin >> N;
    cout <<tiling(N)<<endl;

    return 0;
}


