#include<bits/stdc++.h>

using namespace std;

int A, B;
int res = 2147000000;
void DFS(int L,long long num){
    if(num == B){
        if(L < res) res = L;
        return;
    }
    else if(num > B) return;
    
    DFS(L+1, num*2);
    DFS(L+1, num*10+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    cin >> A >> B;
    DFS(1, A);
    if(res == 2147000000) cout << -1 << endl;
    else cout << res <<endl;
    return 0;
}


