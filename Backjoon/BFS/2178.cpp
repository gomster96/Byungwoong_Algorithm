#include<bits/stdc++.h>

using namespace std;

int N, M;

int a[102][102];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int main(){
    ios_base::sync_with_stdio(false);
    freopen("../input.txt","rt",stdin);
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> a[i][j];
        }
    }
    queue<pair<int, int> > q;
    q.push(make_pair(1,1));
    a[1][1] = 0;
    return 0;
}


