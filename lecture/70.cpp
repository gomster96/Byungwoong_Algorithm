#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define instructor

#ifdef mine

vector<int> map[30];

int main(){
    freopen("input.txt","rt",stdin);
    int n=0, m=0;
    int a, b;
    scanf("%d %d",&n, &m);
    for(int i=1; i<=m; i++){
        scanf("%d %d",&a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }
    int front = -1, back = -1;
    return 0;
}

#endif

#ifdef instructor
#include<queue>

int ch[30], dis[30];

int main(){
    freopen("input.txt","rt",stdin);
    int n, m, a, b, x;
    vector<int> map[30];
    queue<int> Q;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++){
        scanf("%d %d", &a, &b);
        map[a].push_back(b);    
    }
    Q.push(1);
    ch[1] = 1;
    while(!Q.empty()){
        x = Q.front();
        Q.pop();
        for(int i=0; i<map[x].size(); i++){
            if(ch[map[x][i]]==0){
                ch[map[x][i]] = 1;
                Q.push(map[x][i]);
                dis[map[x][i]] = dis[x]+1;
            }
        }
    }
    for(int i=2; i<=n; i++){
        printf("%d : %d\n",i, dis[i]);
    }

    return 0;
}
#endif