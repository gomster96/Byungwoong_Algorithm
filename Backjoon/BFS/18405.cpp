#include<bits/stdc++.h>

using namespace std;

int N, K, S;

int mp[202][202];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

struct virus{
    int r, c, k, val;
    virus(int aa, int bb, int cc, int dd){
        r = aa;
        c = bb;
        k = cc;
        val = dd;
    }
    bool operator<(const virus& v) const{
        return val < v.val;
    }
};

vector<virus> a;

int BFS(int r, int c){
    queue<virus> q;
    sort(a.begin(), a.end());
    for(int i=0; i<a.size(); i++){
        q.push(a[i]);
    }

    while(!q.empty()){
        virus ret = q.front();
        q.pop();
        if(ret.k == S) continue;
        for(int i=0; i<4; i++){
            int rr = ret.r + dy[i];
            int cc = ret.c + dx[i];
            if(rr < 1 || cc < 1 || rr > N || cc > N) continue;
            if(mp[rr][cc] == 0){
                mp[rr][cc] = ret.val;
                q.push(virus(rr,cc,ret.k+1,ret.val));
            }
        }
    }

    return mp[r][c];
}


int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    cin >> N >> K;
    memset(mp, -1, sizeof(mp));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> mp[i][j]; 
            if(mp[i][j] != 0) a.push_back(virus(i, j, 0, mp[i][j]));
        }
    }
    int R, C;
    cin >> S >> R >> C;
    cout << BFS(R,C) << endl;

    return 0;
}


