#include<bits/stdc++.h>

using namespace std;

int N;
int a[1001];
int dp[1001];

int maxIncSeq(int n){
    int&ret = dp[n];
    if(ret != -1) return ret;
    
    for(int i=n+1; i<=N; i++){
        if(a[i]>a[n]){
            
            ret = max(ret, maxIncSeq(i) + a[i]) ;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=N; i++){
        cin >> a[i];
    }
    cout << maxIncSeq(0) + 1 << endl;
    return 0;
}


