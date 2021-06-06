#include<bits/stdc++.h>

using namespace std;

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
    // ios_base::sync_with_stdio(false);
    freopen("../input.txt","rt",stdin);

    vector<Edge> Ed;
    int i, n, m, a, b, c, j, s,e;
    scanf("%d %d",&n, &m);
    for(i=1; i<=m; i++){
        scanf("%d %d %d",&a,&b,&c);
        Ed.push_back(Edge(a,b,c));
    }
    for(i=1; i<=n; i++){
        dist[i] = 2147000000;
    }
    scanf("%d %d",&s, &e);
    dist[s] = 0;
    /// n-1번 도는 것
    for(i=1; i<n; i++){
        // i = 1 이면 간선이 하나일때
        // i ==2 이면 간선이 2개일때 들을 찾는 것
        for(j=0; j<Ed.size(); j++){
            int u = Ed[j].s;
            int v = Ed[j].e;
            int w = Ed[j].val;
            if(dist[u] != 2147000000 && dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
            }
        }
    }

    // 간선이 n개임을 찾는것 --> 음의 사이클을 찾는 것
    for(j=0; j<Ed.size(); j++){
            int u = Ed[j].s;
            int v = Ed[j].e;
            int w = Ed[j].val;
            if(dist[u] != 2147000000 && dist[u]+w < dist[v]){
                printf("-1\n");
                exit(0);
            }
    }

    return 0;
}


