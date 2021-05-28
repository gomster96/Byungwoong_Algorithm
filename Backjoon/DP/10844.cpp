#include<bits/stdc++.h>

using namespace std;

#define mine

const int MOD = 1000000000;
int N;
int dp[11][101];

int stairNum(){
    for(int i=1; i<=9; i++){
        dp[i][1] = 1;
    }
    
    for(int i=2; i<=N; i++){
        
        dp[10][i] = 0 ;

        for(int j=0; j<=9; j++){
            if(j == 0) dp[j][i] =  dp[j+1][i-1];
            else dp[j][i] = (dp[j-1][i-1] + dp[j+1][i-1])%MOD;
        }
    }
    
    int ret = 0;
    for(int i=0; i<=9; i++){
        ret = (ret +dp[i][N]) %MOD;
    
    }
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    cin >> N;
    int res = 0;
    
    memset(dp, 0, sizeof(dp));
    

    cout<<stairNum()<<endl;

    return 0;
}


