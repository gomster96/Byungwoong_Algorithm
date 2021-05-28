#include<bits/stdc++.h>
using namespace std;

#define mine

int n;
vector<int> a;
int res = -2147000000;
int cache[3][10001];
void DFS(int L, int sum, int check){
    if(L >= n){
        // cout << sum << endl;
        if(sum > res) res = sum; 
        return ;
    }

    if(sum < cache[check][L]) return;
    cache[check][L] = sum;
    if(check < 2){      
        DFS(L+1, sum+a[L], check+1);
    }
    DFS(L+1, sum, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    

    memset(cache, -1, sizeof(cache));
    cin >> n;
    int tmp;
    for(int i=1; i<=n; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    DFS(0,0, 0);
    cout << res << endl;
    
    
    return 0;
}


