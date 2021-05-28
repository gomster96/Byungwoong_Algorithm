#include<bits/stdc++.h>

using namespace std;

#define mine

int N;
int cache[501][501];
int a[501][501];

/////////// 중요...! 
/////////// 이문제에서 범위는 0~9999이다 즉 0도가능하다
/////////// 항상 실수하는것...! ret에다가 &붙여주는거 잊지말자>.!!
int tri(int r, int c){
    if(r==N) return a[r][c];
    int& ret = cache[r][c];
    if(ret != -1) return ret;
    ret = max(tri(r+1,c)+a[r][c], tri(r+1, c+1)+a[r][c]);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);

    memset(cache, -1, sizeof(cache));
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            cin >> a[i][j];
        }
    }
    cout << tri(1, 1) << endl;
    
    return 0;
}


