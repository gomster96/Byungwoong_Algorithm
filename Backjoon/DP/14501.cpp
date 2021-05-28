#include<bits/stdc++.h>

using namespace std;

#define mine

int N;
vector<pair<int, int> > a;
int res = -2147000000;

void DFS(int T, int P){
    if(T>=N){
        if(P>res) res = P;
    }
    else{

        if(T+a[T+1].first <= N){
                DFS(T+a[T+1].first, P+a[T+1].second);
        }
        DFS(T+1, P);

        // for(int i=T+1; i<=N; i++){
            // if(T+a[i-1].first <= N){
            //     cout<< T << " " << i << " " << P << endl;
            //     DFS(T+a[i-1].first, P+a[i-1].second);
            //     DFS(T+1, P);
            // }
        //     else{
        //         DFS(N, P);
        //     }  
        // }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    cin >> N;
    int t1,t2;
    a.push_back(make_pair(-1,-1));
    for(int i=0; i<N; i++){
        cin >> t1 >> t2;
        a.push_back(make_pair(t1,t2));
    }
    DFS( 0, 0);
    cout << res << endl;
    return 0;
}


