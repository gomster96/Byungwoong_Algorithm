#include<bits/stdc++.h>

using namespace std;

int N;
int a[301];
/// 캐시문제로 한참 해맷음. 반드시 정리해두기
int cache[3][301];
int climStairs(int n, int c){
    if(n<=0) return 0;
    if(c>=3) return -987654321;
    int& ret = cache[c][n];
    if(ret != -1) return ret;
    ret = max(climStairs(n-1, c+1)+a[n], climStairs(n-2, 1)+a[n]);
    return ret;
    
}


int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    memset(a, -1, sizeof(a));
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> a[i];
    }
    
    cout << climStairs(N, 1) << endl;
    
    return 0;
}


