#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> a[100001];
int ans[100001];

void DFS(int v){

    for(int i=0; i<a[v].size(); i++){
        if(ans[a[v][i]] == 0){
            ans[a[v][i]] = v;
            DFS(a[v][i]);
        }
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    cin >> N;
    int ta, tb;
    for(int i=1; i<=N; i++){
        cin >> ta >> tb;
        a[ta].push_back(tb);
        a[tb].push_back(ta);
    }
    ans[1] = 1;
    DFS(1);
    //// endl을 써서 틀렸는데 '\n'을 써서 맞았다... 매우 중요함!
    for(int i=2; i<=N; i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}


