#include<bits/stdc++.h>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    freopen("../input.txt","rt",stdin);
    
    int i, j, n, k;
    int dp[10001] = {0,};

    cin >> n >> k;

    int coins[n];

    for(i=0; i<n; i++) scanf("%d",&coins[i]);
    dp[0] = 1;

    for(i=0; i<n; i++){
        for(j=coins[i]; j<=k; j++){
            if(j-coins[i] >= 0){
                dp[j] += dp[j - coins[i]];
            }
        }
    }

    return 0;
}





// #include<bits/stdc++.h>

// using namespace std;

// int N, K;
// int dp[10001];
// int a[101];
// int coin(int k){
//     if(k == 0) return 1;
//     else if(k<0) return 0;
//     int& ret = dp[k];
//     if(ret != -1) return ret;
//     ret = 0;
//     for(int i=1; i<=N; i++){
//         if(k - a[i] >= 0){
//             ret = ret + coin(k-a[i]);
//         }
//     }
//     return ret;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     freopen("../input.txt","rt",stdin);
//     cin >> N >> K;
//     memset(dp, -1, sizeof(dp));
//     dp[0] = 0;
//     for(int i=1; i<=N; i++){
//         cin >> a[i];
//     }

//     cout<<coin(K) << endl;
//     for(int i=1; i<=K; i++){
//         cout <<i<<" : "<<dp[i]<<endl;
//     }

//     return 0;
// }

// // 1먼저 처리하고 시작
// // 2먼저 처리하고시작
// // 5먼저 처리하고시작

