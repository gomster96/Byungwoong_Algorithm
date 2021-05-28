#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

#define instructor

#ifdef mine
vector<pair<int, int> > map[21];
int ch[21];
int res = 2147000000;
int n = 0, m = 0;

void DFS(int v, int sum){
    if(v == 5){
        if(res > sum){
            res = sum;
        }
    }
    else{
        for(int i=0; i<map[v].size(); i++){
            if(ch[map[v][i].first] == 0){
                ch[map[v][i].first] = 1;
                sum += map[v][i].second;
                DFS(map[v][i].first, sum);
                ch[map[v][i].first] = 0;
                sum -= map[v][i].second;
            }
        }
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    
    scanf("%d %d",&n, &m);
    int a, b, c;
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        map[a].push_back(make_pair(b, c));
    }
    ch[1] = 1;
    DFS(1, 0);
    printf("%d\n",res);
    return 0;
}

#endif

#ifdef instructor

int map[30][30], ch[30], n, cost=2147000000;

void DFS(int v, int sum){
    if(v==n){
        if(sum < cost) cost = sum;
    }
    else{
        for(int i=1; i<=n; i++){
            if(map[v][i] > 0 && ch[i]==0){
                ch[i] = 1;
                DFS(i, sum+map[v][i]);
                /// 이렇게 더해줘서 보내버리는게 더 뭔가 recursion같음 집중하기
                ch[i] = 0;
            }
        }
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    int m, i, a, b, c;
    scanf("%d %d",&n, &m);
    for(i=1; i<=m; i++){
        scanf("%d %d %d",&a, &b, &c);
        map[a][b] = c;
    }
    ch[1] = 1;
    DFS(1,0);
    return 0;
}
#endif

