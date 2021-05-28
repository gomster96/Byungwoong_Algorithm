#include<bits/stdc++.h>

using namespace std;

#define mine

int a[3][100001];
int dp[3][100001];
int N;

int stiker(int n, int beforeCheck){
    if(n>N) return 0;
    int&ret = dp[beforeCheck][n];
    if(ret != -1) return ret;

    // beforeCheck = 1번항 또는 2번항이 체크되고 아무것도 안되어있으면 0
    
    for(int i=1; i<=2; i++){
        if(i != beforeCheck){
            ret = max(ret, stiker(n+1, i)+a[i][n]);
        }
    }
    ret = max(ret, stiker(n+1, 0));
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        memset(a, -1, sizeof(a));
        memset(dp, -1, sizeof(dp));
        for(int j=1; j<=2; j++){
            for(int i=1; i<=N; i++){            
                cin >> a[j][i];
            }
        }
        cout<<stiker(1, 0)<<endl;

    }

    return 0;
}


