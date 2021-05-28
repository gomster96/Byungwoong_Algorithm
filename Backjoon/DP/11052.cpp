#include<bits/stdc++.h>

using namespace std;

#define mine

vector<int> p(1001);
int dp[1001];
int main(){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    // n개 만큼의 값을 입력받고 i-j까지의 수를 넘어갈 수 없으므로,
    // max를 i-j까지 한값 + p 를 사용하여 최댓값을 구해준다.
    // 이렇게 하면 결국 최종n에 최대값이 들어간다. -> 하나씩 다 탐색하기때문에
    // dp를 for문 안에서 하는거 잘해보자 ...

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], dp[i-j]+p[j]);
        }
    }
    cout << dp[n];
    return 0;
}