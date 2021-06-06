#include<bits/stdc++.h>

using namespace std;

vector<int> v[300001];
int dist[300001] = {0,};
int n, m, k, x, z;

void bfs(int x){
    queue<int> q;
    q.push(x);

    while(!q.empty()){
        int nx = q.front();
        q.pop();

        for(int i=0; i<v[nx].size(); i++){
            int z = v[nx][i];
            if(dist[z] == 0 && z != x){
                dist[z] = dist[nx]+1;
                q.push(z);
            }
        }
    }
}
int main() {

	cin >> n >> m >> k >> x;

	int i1, i2;
	for (int i = 0; i < m; i++) {
		cin >> i1 >> i2;
		v[i1].push_back(i2);
	}

	bfs(x);

	vector<int> answer;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == k)
			answer.push_back(i);
	}
	if (answer.size() == 0)
		cout << -1 << endl;
	else {
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << endl;
		}
	}
}



// #include<bits/stdc++.h>

// using namespace std;

// int N, M, K, X;

// vector<int> graph[300001];
// int dist[300001];


// struct Edge{
//     int v, dis;
//     Edge(int a, int b){
//         v = a;
//         dis = b;
//     }
//     bool operator<(const Edge& E) const{
//         return dis < E.dis;
//     }
// };

// int main(){
//     ios_base::sync_with_stdio(false);
//     // freopen("../input.txt","rt",stdin);
    
//     cin >> N >> M >> K >> X;
//     int ta, tb;

    

//     for(int j=1; j<=M; j++){
//         cin >> ta >> tb;
//         graph[ta].push_back(tb);
//         graph[tb].push_back(ta);
//     }
    
//     memset(dist, -1, sizeof(dist));
//     dist[X] = 0;
//     priority_queue<Edge> q;
//     q.push(Edge(X, 0));
//     vector<int> ans;
//     while(!q.empty()){
//         int next = q.top().v;
//         int nextDis = q.top().dis;
//         if(dist[next] != -1) continue;
//         if(nextDis >= K) continue;
//         q.pop();
//         for(int i=0; i<graph[next].size(); i++){
            
//             if(dist[graph[next][i]] == -1 || dist[graph[next][i]] > nextDis+1  ){
//                 dist[graph[next][i]] = nextDis+1;
                
//                 if(dist[graph[next][i]] == K) ans.push_back(graph[next][i]);
//                 else q.push(Edge(graph[next][i],nextDis+1));
//             }
//         }
//     }
//     // if(ans.size() == 0){
//     //     cout<<-1<<"\n";
//     //     return 0;
//     // }

//     // sort(ans.begin(), ans.end());
    
//     // for(int i=0; i<ans.size(); i++){
//     //     cout<<ans[i]<<"\n";
//     // }
    
//     int cnt = 0;
//     for(int i=1; i<=N; i++){
//         if(dist[i] == K){
//             cnt++;
//             cout<<i<<"\n";
//         }
//     }
//     if(cnt == 0) cout<<-1<<"\n";
    
//     return 0;
// }


