#include<bits/stdc++.h>

using namespace std;

int dp[101];
int snake[101];
bool ch[101];
int N, M;
const int MAX = 2147000000;


int BFS(){
    queue<pair<int, int> > q;
    q.push(make_pair(1, 0));

    while(!q.empty()){
        int n = q.front().first;
        int L = q.front().second;
        q.pop();
        if(n == 100) return L;
        for(int i=1; i<=6; i++){
            int next = n+i;
            if(next>100) continue;
            if(snake[next] != -1){
                next = snake[next];
            }
            if(!ch[next]){
                ch[next] = true;
                q.push(make_pair(next,L+1));
            }
            
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    cin >> N >> M;
    int ta, tb;
    memset(dp, -1, sizeof(dp));
    memset(snake, -1, sizeof(snake));
    for(int i=1; i<=N+M; i++){
        cin >> ta >> tb;
        snake[ta] = tb;
    }

    // cout << DFS(0,1) << endl;
    cout << BFS() << endl;
    return 0;
}


