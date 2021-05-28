#include<bits/stdc++.h>

using namespace std;

#define mine

int N;
int a[10001];
int dp[3][10001];

////// 틀린이유: 두칸 이상 건너뛰어도 더 클 수가 있다!
/// 다른사람 코드 보고 체크하기
int grape(int n, int c){
    if(n > N) return 0;
    if(c >= 3) return 0;
    int& ret = dp[c][n];
    if(ret != -1) return ret;

    ret = max(grape(n+1, c+1), grape(n+2, 1)) + a[n];
    ret = max(grape(n+3, 1)+a[n], ret);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);

    memset(dp, -1, sizeof(dp));
    cin >> N;
    a[0] = 0;
    for(int i=1; i<=N; i++){
        cin >> a[i];
    }

    cout << grape(0,0) << endl;

    return 0;
}


