#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define instructor

#ifdef mine
int map[8][8], cnt = 0;
int ch[8][8];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
void DFS(int vRow, int vCol){
    
    if(vRow == 7 && vCol == 7){
        cnt++;
        return;
    }
    else{
        for(int i=0; i<4; i++){
            
            if(vRow + dy[i] < 8 && vRow + dy[i] >0 && vCol + dx[i] < 8 && vCol + dx[i] > 0){
                if(map[vRow+dy[i]][vCol+dx[i]] == 0 && ch[vRow+dy[i]][vCol+dx[i]] == 0){
                    ch[vRow+dy[i]][vCol+dx[i]] = 1;
                    DFS(vRow+dy[i], vCol+dx[i]);
                    ch[vRow+dy[i]][vCol+dx[i]] = 0;
                }
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
    DFS(1,1);
    printf("%d\n",cnt);
    return 0;
}

#endif

#ifdef instructor

int map[10][10], ch[10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt = 0;

void DFS(int x, int y){
    int i, xx, yy;
    if(x == 7 && y == 7){
        cnt++;
    }
    else{
        for(i=0; i<4; i++){
            xx = x+dx[i];
            yy = y+dy[i];
            if(xx<1 || xx>7 || yy<1 || yy>7) continue;
            if(map[xx][yy] == 0 && ch[xx][yy] == 0){
                ch[xx][yy] = 1;
                DFS(xx, yy);
                ch[xx][yy] = 0;
            }
        }
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    int i, j;
    for(i=1; i<=7; i++){
        for(j=1; j<=7; j++){
            scanf("%d",&map[i][j]);
        }
    }
    ch[1][1] = 1;
    DFS(1,1);
    printf("%d\n",cnt);
    return 0;
}
#endif