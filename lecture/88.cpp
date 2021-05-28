#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define instructor

#ifdef mine

int map[8][8];
int ch[8][8];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0 , 1};
int flag = 0;
int mini = 2147000000;
void BFS(int r, int c, int sum){
    if(r == 7 && c == 7){
        
        if(sum < mini) mini = sum;
        flag = 1;
        return;
    }
    else{
        for(int i=0; i<4; i++){
            if(r+dy[i]>7 || c+dx[i] >7 || r+dy[i] < 1 || c+dx[i] <1 ){
                continue;
            }
            else if(ch[r+dy[i]][c+dx[i]]==0 && map[r+dy[i]][c+dx[i]] == 0){
                
                ch[r+dy[i]][c+dx[i]] = 1;
                printf("%d %d\n", r+dy[i], c+dx[i]);
                BFS(r+dy[i],c+dx[i], sum+1);
                ch[r+dy[i]][c+dx[i]] = 0;
            }
        }
    }

}

int main(){
    freopen("input.txt","rt",stdin);
    
    for(int i=1; i<=7; i++){
        for(int j=1; j<=7; j++){
            scanf("%d",&map[i][j]);
        }
    }
    ch[1][1] = 1;
    BFS(1,1, 0);
    if(flag == 0){
        printf("-1\n");
    }
    else{
        printf("%d\n",mini);
    }
    return 0;
}

#endif

#ifdef instructor

int n, map[10][10], dis[10][10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
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
    for(int i=1; i<=7; i++){
        for(int j=1; j<=7; j++){
            scanf("%d",&map[i][j]);
        }
    }
    Q.push(Loc(1,1));
    map[1][1] = 1;
    while(!Q.empty()){
        Loc tmp = Q.front();
        Q.pop();
        for(int i=0; i<4; i++){
            int xx = tmp.x+dx[i];
            int yy = tmp.y+dy[i];
            if(map[xx][yy] == 0 && xx>=1 && xx<=7 && yy>=1 && yy<=7){
                /// 7을 넘어서면 자동적으로 없어지기 때문에 결국 제일먼저 7,7에 도착한 값이 최소값으로 계속 있게 됨
                Q.push(Loc(xx,yy));
                map[xx][yy] = 1;
                dis[xx][yy] = dis[tmp.x][tmp.y] +1;
            }
        }
    }
    printf("%d",dis[7][7]);
    return 0;
}
#endif