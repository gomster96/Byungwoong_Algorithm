#include<bits/stdc++.h>

using namespace std;

int N;
int dy[] = {-2, -2, 0, 0, 2, 2};
int dx[] = {-1, 1, -2, 2, -1, 1};
bool ch[201][201];

struct deathKnight{
    int r, c, val;
    deathKnight(int aa, int bb, int cc){
        r = aa;
        c = bb;
        val = cc;
    }
};

int BFS(int r, int c, int rF, int cF){
    ch[r][c] = true;
    queue<deathKnight > q;
    q.push(deathKnight(r,c,0));
    while(!q.empty()){
        deathKnight ret = q.front();
        q.pop();

        if(ret.r == rF && ret.c == cF) return ret.val;

        for(int i=0; i<6; i++){
            int rr = ret.r+dy[i];
            int cc = ret.c+dx[i];
            if(rr < 0 || cc <0 || rr>=N || cc >=N) continue;

            if(!ch[rr][cc]){
                ch[rr][cc] = true;
                q.push(deathKnight(rr,cc,ret.val+1));
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    cin >> N;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout<<BFS(a,b,c,d)<<endl;
    return 0;
}


