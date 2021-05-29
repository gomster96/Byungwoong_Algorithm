#include<bits/stdc++.h>

using namespace std;

int N, M;
int a[1002][1002];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
struct Tomato{
    int r, c, val;
    // 습관대로 a, b, c 써서 틀려버림 변수이름 집중하기
    // Tomato(int a, int b, int c){
    Tomato(int z, int x, int v){
        r = z;
        c = x;
        val = v;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    memset(a, -1, sizeof(a));
    cin >> M >> N;

    queue<Tomato> tom;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> a[i][j]; 
            if(a[i][j] == 1){
                tom.push(Tomato(i, j, 1));    
            }
        }
    }
    
    
    
    while(!tom.empty()){
        Tomato k = tom.front();
        tom.pop();
        for(int i=0; i<4; i++){
            int rr = k.r + dy[i];
            int cc = k.c + dx[i];
            if(a[rr][cc] == 0){
                
                a[rr][cc] = k.val+1;
                // cout<<rr<<" "<<cc<<" "<<a[rr][cc]<<endl;
                tom.push(Tomato(rr,cc,k.val+1));
            }
        }
    }
    int res = -1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(a[i][j] > res) res = a[i][j];
            if(a[i][j] == 0){
                res = 0;
                break;
            }
        }
        if(res == 0) break;
    }
    cout<< res-1<<endl;
    return 0;
}


