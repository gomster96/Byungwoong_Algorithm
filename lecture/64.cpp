#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define instructor

#ifdef mine
int map[21][21];
int ch[21];
int n = 0, m = 0, cnt = 0;

void DFS(int from){
    
    if(from == n){
        cnt++;
        return;
    }
    for(int i=2; i<=n; i++){
        if(map[from][i] == 1 && ch[i]!= 1){
            ch[i] = 1;
            // printf("%d ",i);
            DFS(i);
            
            ch[i] = 0;
        }
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    
    scanf("%d %d",&n, &m);
    int a, b;
    for(int i=1; i<=m; i++){
        scanf("%d %d",&a,&b);
        map[a][b] = 1;
    }
    ch[1] = 1;
    DFS(1);
    printf("%d\n",cnt);
    return 0;
}

#endif

#ifdef instructor

int map[30][30];
int ch[30], cnt = 0;
int n, m;
void DFS(int v){
    int i;
    if(v == n){
        cnt++;
    }
    else{
        for(i=1; i<=n; i++){
            if(map[v][i]==1 && ch[i]==0){
                ch[i] = 1;
                DFS(i);
                ch[i] = 0;
            }
        }
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    int  i, a, b;
    scanf("%d %d",&n, &m);
    for(i=1; i<=m; i++){
        scanf("%d %d",&a,&b);
        map[a][b] = 1;
    }
    ch[1] = 1;
    DFS(1);
    printf("%d\n",cnt);
    return 0;
}
#endif