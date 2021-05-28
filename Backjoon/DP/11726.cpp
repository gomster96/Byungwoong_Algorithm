#include<bits/stdc++.h>
using namespace std;

#define mine

int N;
int cache[1001];
const int MOD = 10007;
int tiling(int n){
    int& ret = cache[n];
    if(ret != -1) return ret;

    return ret = (tiling(n-1) + tiling(n-2))%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    memset(cache, -1, sizeof(cache));
    cache[1] = 1;
    cache[2] = 2;
    cin >> N;
    cout << tiling(N) << endl;
    
    return 0;
}


