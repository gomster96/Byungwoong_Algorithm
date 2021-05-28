#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define instructor

#ifdef mine
int map[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0 ,1};
vector<pair<int,int> > st;

int n = 0, m = 0;

void BFS(int r, int c, int state){
    
    map[r][c] = state;
    for(int i=0; i<4; i++){
        if(r+dy[i] < 1 || c+dx[i] <1 || r+dy[i] > n || c+dx[i] > m) continue;
        if(map[r+dy[i]][c+dx[i]] > state+1 || map[r+dy[i]][c+dx[i]] == 0){
            BFS(r+dy[i],c+dx[i], state+1);
        }
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    
    scanf("%d %d",&m, &n);
    int a;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a);
            if(a==1){
                st.push_back(make_pair(i,j));
            }
        }
    }
    int maxi = -2147000000;
    if(st.size() == m*n) printf("0\n");
    else if(st.empty()) printf("-1\n");
    else{
        for(int i=0; i<st.size(); i++){
            BFS(st[i].first, st[i].second, 1);
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(map[i][j]>maxi) maxi = map[i][j];
            }
        }
        printf("%d\n",maxi-1);
    }
    
    return 0;
}

#endif

#ifdef instructor
int m, n, tom[1010][1010], res=-2147000000, dis[1010][1010];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
struct Loc{
    int x, y;
    Loc(int a, int b){
        x = a;
        y = b;
    }
};
queue<Loc> Q;
int main(){
    freopen("input.txt","rt",stdin);
    scanf("%d %d",&m, &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d",&tom[i][j]);
            if(tom[i][j] == 1){
                Q.push(Loc(i,j));
            }
        }
    }
    while(!Q.empty()){
        Loc tmp = Q.front();
        Q.pop();
        for(int i = 0; i<4; i++){
            int xx = tmp.x+dx[i];
            int yy = tmp.y+dy[i];
            if(tom[xx][yy] == 0){
                if(xx>=1 && xx<=n && yy>=1 && yy<=m){
                    Q.push(Loc(xx,yy));
                    tom[xx][yy] = 1;
                    dis[xx][yy] = dis[tmp.x][tmp.y] + 1;
                }
            }
        }
    }
    int f = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(tom[i][j] == 0) f= 0;
        }
    }
    if(f == 1){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(res<dis[i][j]) res = dis[i][j];
            }
        }
    }
    else printf("-1");
    return 0;
}
#endif