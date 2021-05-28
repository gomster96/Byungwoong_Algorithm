#include<bits/stdc++.h>
#include<queue>
using namespace std;

int N, M, V;
int a[1002][1002] = {0, };
bool ch[1002] = {false, };

void DFS(int v){
    
    for(int i=1; i<=N; i++){
        if(ch[i] == false && a[v][i] == 1){
            ch[i] = true;
            cout<<i<<" ";
            DFS(i);
        }
    }
    return;
}

void BFS(int v){
    queue<int> q;
    q.push(v);

    while(!q.empty()){
        //// 왜 이부분을 없애야 런타임에러가 발생하지 않는것일 까??? 
        //// empty일때의 조건을 주지 않았기 떄문에 q에 있지않은 값에 접근하게된것...! 잘못!
        while((ch[q.front()] != false) && !q.empty()) q.pop();
        if(q.empty()) break;
        int ft = q.front();
        ch[ft] = true;
        cout<<ft<<" ";
        q.pop();
        for(int i=1; i<=N; i++){
            if(ch[i]==false && a[ft][i] == 1){
                // ch[i] = true;
                q.push(i);
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    cin >> N >> M >> V;
    int ta, tb;
    for(int i=1; i<=M; i++){
        cin >> ta >> tb;
        a[ta][tb] = 1;
        a[tb][ta] = 1;
    }
    cout<<V<<" ";
    ch[V] = true;
    DFS(V);
    cout<<endl;
    memset(ch, false, sizeof(ch));

    BFS(V);
    cout<<endl;
    return 0;
}


