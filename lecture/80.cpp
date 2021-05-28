#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define instructor

#ifdef mine

struct Edge{
    int vex;
    int dis;
    Edge(int a, int b){
        vex = a;
        dis = b;
    }
    bool operator<(const Edge &b) const {
        return dis > b.dis;
    }
};

int main(){
    freopen("input.txt","rt",stdin);

    priority_queue<Edge> pQ;
    vector<pair<int, int> > graph[30];
    int i, n, m, a, b, c;
    cin>>n>>m;
    vector<int> dist(n+1, 2147000000);
    //// 2147000000 으로 초기화 하는 것
    for(i=1; i<=m; i++){
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
    }
    pQ.push(Edge(1,0));
    dist[1] = 0;
    while(!pQ.empty()){
        int now = pQ.top().vex;
        int cost = pQ.top().dis;
        pQ.pop();
        if(cost>dist[now]) continue;
        for(i=0; i<graph[now].size(); i++){
            int next = graph[now][i].first;
            int nextDis = cost + graph[now][i].second;
            if(dist[next] > nextDis){
                dist[next] = nextDis;
                pQ.push(Edge(next, nextDis));
            }
        }
    }

    for(i=2; i<=n; i++){
        if(dist[i] != 2147000000) cout<<i<<" : "<<dist[i]<<endl;
        else cout<<i<<" : impossible"<<endl;
    }

    return 0;
}

#endif



#ifdef instructor

struct Edge{
    int vex;
    int dis;
    Edge(int a, int b){
        vex = a;
        dis = b;
    }
    bool operator<(const Edge &b) const {
        return dis > b.dis;
    }
};

int main(){
    freopen("input.txt","rt",stdin);
    priority_queue<Edge> pQ;
    vector<pair<int, int> > graph[30];
    int i, n, m, a, b, c;
    cin>>n>>m;
    vector<int> dist(n+1, 2147000000);
    for(i=1; i<=m; i++){
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
    }
    pQ.push(Edge(1,0));
    dist[1] = 0;
    while(!pQ.empty()){
        int now = pQ.top().vex;
        int cost = pQ.top().dis;
        pQ.pop();
        if(cost>dist[now]) continue;
        for(i=0; i<graph[now].size(); i++){
            int next = graph[now][i].first;
            int nextDis = cost + graph[now][i].second;
            if(dist[next] > nextDis){
                dist[next] = nextDis;
                pQ.push(Edge(next, nextDis));
            }
        }
    }
    return 0;
}
#endif