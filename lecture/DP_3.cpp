#include<bits/stdc++.h>
using namespace std;

#define instructor

#ifdef mine
int a[10001];
int DFS(int n){
    if(n==1 || n==2) return n;
    else return a[n] = DFS(n-1) + DFS(n-2);
}
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);

    int n = 0;
    cin >> n;
    
    cout<<DFS(n)<<"\n";

    return 0;
}

#endif
#ifdef instructor
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    int n =0;
    int dy[100001];
    cin >> n;
    dy[1] = 1;
    dy[2] = 2;
    for(int i=3; i<=n ; i++){
        dy[i] = dy[i-1]+dy[i-2];
    }
    
    cout<<dy[n] << "\n";

    return 0;
}
#endif