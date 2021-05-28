#include<bits/stdc++.h>
using namespace std;

#define mine

#ifdef mine

int n;

double dist[11][11];

double shortestPath(vector<int> & path, vector<bool> & visited, double currentLength){
    // 기저사례: 모든 도시를 다 방문했을 때는 시작 도시로 돌아가고 종료한다.
    if(path.size() == n) return currentLength + dist[path[0]][path.back()]; ///마지막으로 안이어진 출발점과 도착점을 이은 것

    double ret = 2147000000;
    /// 방문할 도시를 전부 시도해보기
    for(int next = 0; next < n; next++){
        if(visited[next]) continue;
        int here = path.back();
        path.push_back(next);
        visited[next] = true;
        double cand = shortestPath(path, visited, currentLength + dist[here][next]);
        ret = min(ret, cand);
        visited[next] = false;
        path.pop_back();
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);

    return 0;
}

#endif
#ifdef instructor
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);

    return 0;
}
#endif