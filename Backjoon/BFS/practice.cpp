#include<bits/stdc++.h>

using namespace std;
#define belmanford
#ifdef dikstra

struct Edge{
    int vex;
    int dis;
    Edge(int a, int b){
        vex = a;
        dis = b;
    }
    // 오름차순으로 만드는 방법
    bool operator<(const Edge &b) const{
        return dis > b.dis;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    freopen("../input.txt","rt",stdin);
    
    int i, n, m, a, b, c;
    priority_queue<Edge> Q;
    vector<pair<int, int> > graph[30];
    cin >> n >> m;
    vector<int> dist(n+1, 2147000000);

    for(i=1; i<=m; i++){
        cin >> a >> b >>c;
        graph[a].push_back(make_pair(b,c));
    }

    Q.push(Edge(1,0));
    dist[1] = 0;
    while(!Q.empty()){
        int now = Q.top().vex;
        int cost = Q.top().dis;
        Q.pop();
        if(cost > dist[now]) continue;
        for(i=0; i<graph[now].size(); i++){
            int next = graph[now][i].first;
            int nextDis = cost + graph[now][i].second;
            if(dist[next] > nextDis){
                dist[next] = nextDis;
                Q.push(Edge(next, nextDis));
            }
        }
    }

    return 0;
}

#endif

#ifdef belmanford

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
    freopen("../input.txt","rt", stdin);
    vector<Edge> Ed;
    int i, n, m, a, b, c, j, s, e;
    scanf("%d %d",&n, &m);
    for(i=1; i<=m; i++){
        scanf("%d %d %d",&a, &b, &c);
        Ed.push_back(Edge(a,b,c));
    }
    scanf("%d %d",&s, &e);
    dist[s] = 0;
    for(i=1; i<n; i++){
        for(j=0; j<Ed.size(); j++){
            int u = Ed[j].s;
            int v = Ed[j].e;
            int w = Ed[j].val;
            if(dist[u] != 2147000000 && dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
            }
        }
    }
}

#endif
 