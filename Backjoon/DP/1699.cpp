#include<bits/stdc++.h>

using namespace std;

int N;
int dp[100001];

int main(){
    ios_base::sync_with_stdio(false);
    freopen("../input.txt","rt",stdin);
    
    cin >> N;
    dp[0] = 0;
    for(int i=1; i<=N; i++){
     
        dp[i] = i;
        for(int j=1; j*j <=i; j++){
            dp[i] = min(dp[i], dp[i - j*j]+1);
        }
    }
    cout << dp[N] << endl;
    return 0;
}


