#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define mine

#ifdef mine
int dist[101];
struct Edge{
    int s;
    int e;
    int val;
    Edge(int a, int b, int c){
        s = a;
        e = b;
        val = c;
    }
};
int main(){
    freopen("input.txt","rt",stdin);
    vector<Edge> Ed;
    int i, n, m, a, b, c, j ,s ,e;
    scanf("%d %d",&n, &m);
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &a, &b, &c);
        Ed.push_back(Edge(a,b,c));
    }
    for(i=1; i<=n; i++){
        dist[i] = 2147000000; /// 1차원 배열을 해도 됨
    }
    scanf("%d %d",&s, &e);
    dist[s] = 0;
    ///// 횟수에 대한건 그냥 여러번 처리하면 됌 
    for(i=1; i<n; i++){
        for(j=0; j<Ed.size(); j++){
            int u = Ed[j].s;
            int v = Ed[j].e;
            int w = Ed[j].val;
            if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
                dist[v] = dist[u]+w;
            }
        }
    }
    //// 음의 싸이클 체크하는 부분
    for(j=0; j<Ed.size(); j++){
            int u = Ed[j].s;
            int v = Ed[j].e;
            int w = Ed[j].val;
            if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
                dist[v] = dist[u]+w;
                printf("-1\n");
                exit(-1);
            }
        }
    printf("%d\n",dist[e]);
    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);

    return 0;
}
#endif