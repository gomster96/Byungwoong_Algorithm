#include<bits/stdc++.h>
using namespace std;

#define mine
int n, t;
int cnt;
void DFS(int k){
    if(k >= n){
        if(k == n) cnt++;
        return;
    }
    for(int i=1; i<=3; i++){
        DFS(k+i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    

    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        DFS(0);
        cout << cnt << endl;
        cnt = 0;
    }

    
    
    return 0;
}


