#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<int> a[101];
int ch[101];
int main(){
    ios_base::sync_with_stdio(false);
    freopen("../input.txt","rt",stdin);
    
    cin >> N >> M;
    int ta, tb;
    for(int i=1; i<=M; i++){
        cin >> ta >> tb;
        a[ta].push_back(tb);
        a[tb].push_back(ta);
    }
    queue<int> q;
    for(int i=1; i<=N; i++){
        
        q.push(i);
        
        while(!q.empty()){
            
            int k = q.front();
            q.pop();
            if(ch[k] != 0){
                continue;
            }
            else{
                for(int j=0; j<a[j].size(); j++){
                    if(ch[k] == 0){

                    }
                }
            }
            
        }
        
    }

    return 0;
}


