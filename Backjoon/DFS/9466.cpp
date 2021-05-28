#include<bits/stdc++.h>

using namespace std;

int T, N;
bool dp[100001];
int a[100001];

bool DFS(int start, int n){
    if(a[start] <= 0 || a[n]<=0) return false;
    if(dp[start] || dp[n]) return false;
    
    
    if(start == a[n]){
        
        dp[n] = true;
        return true;
    }
    if(n == a[n]) return false;
    
    dp[n] = DFS(start, a[n]);
    if(dp[n]) return true;
    
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("../input.txt","rt",stdin);
    cin >> T;

    for(int k=0; k<T; k++){
        cin >> N;
        memset(dp, false, sizeof(dp));
        memset(a, -1, sizeof(a));

        for(int i=1; i<=N; i++){
            cin >> a[i];
        }
        for(int i=1; i<=N; i++){
            DFS(i , i);
        }
        int cnt = 0;
        for(int i=1; i<=N; i++){
            if(dp[i] == false){
                cnt++;
            }    
        }
        cout << cnt << endl;
    }

    

    return 0;
}


