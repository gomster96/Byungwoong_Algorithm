#include<bits/stdc++.h>

using namespace std;


int N, M;
int a[1001][1001];
bool ch[1001] = {false,};
int cnt = 0;

void DFS(int v){

    for(int i=1; i<=N; i++){
        if(!ch[i] && a[v][i] == 1){
            ch[i] = true;
            DFS(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    cin >> N >> M;
    int ta, tb;
    for(int i=1; i<=M; i++){
        cin >> ta >> tb;
        a[ta][tb] = 1;
        a[tb][ta] = 1;
    }

    for(int i=1; i<=N; i++){
        if( !ch[i] ){
            ch[i] = true;
            DFS(i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}


