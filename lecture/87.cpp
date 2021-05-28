#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define instructor

#ifdef mine
int map[21][21];
int ch[21][21];
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
// int dy[4] = {0, -1, 0, 1};
// int dx[4] = {-1, 0, 1, 0};
int n = 0;
void BFS(int r, int c){
    
    for(int i = 0; i<8; i++){
        if(ch[r+dy[i]][c+dx[i]] == 0 && map[r+dy[i]][c+dx[i]] == 1){
            ch[r+dy[i]][c+dx[i]] = 1;
            BFS(r+dy[i],c+dx[i]);
        }
    }
    
}


int main(){
    freopen("input.txt","rt",stdin);
    
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&map[i][j]);
        }
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(ch[i][j] == 0 && map[i][j] == 1){
                cnt++;
                BFS(i,j);
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}

#endif

#ifdef instructor

int n, map[30][30], cnt = 0;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

struct Loc{
    int x;
    int y;
    Loc(int a, int b){
        x = a;
        y = b;
    }
};
queue<Loc> Q;
int main(){
    freopen("input.txt","rt",stdin);
    int i, j;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(map[i][j] == 1){
                Q.push(Loc(i,j));
                map[i][j] = 0;
                while(!Q.empty()){
                    Loc tmp = Q.front();
                    Q.pop();
                    for(int k = 0; k<8; k++){
                        if(map[tmp.x + dx[i]][tmp.y + dy[i]] == 1){
                            Q.push(Loc(tmp.x+dx[i],tmp.y+dy[i]));
                            map[tmp.x + dx[i]][tmp.y+dy[i]] = 0;
                        }
                    }
                }
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
#endif