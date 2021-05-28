#include<bits/stdc++.h>

using namespace std;

#define mine

int N;
long long dp[101];
long long waveSeq(int n){
    if(n <= 0) return 0;
    long long& ret = dp[n];
    if(ret != -1) return ret;

    return ret = waveSeq(n-5) + waveSeq(n-1);

}
int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    cin >> N;
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        cout << waveSeq(tmp) << endl;
    }

    return 0;
}


