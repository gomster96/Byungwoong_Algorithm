#include<bits/stdc++.h>
using namespace std;

#define mine

#ifdef mine


int dy[101];
int DFS(int n){
    if(dy[n] > 0) return dy[n];
    if(n==1 || n==2){
        return n;
    }
    else return dy[n] = DFS(n-1)+DFS(n-2);
}
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);

    int n;
    cin>>n;
    cout<<DFS(n);

    return 0;
}

#endif
#ifdef instructor
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);

    return 0;
}
#endif