#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define instructor

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    int n = 0;
    int r = 0 ;
    scanf("%d %d",&n, &r);
    
    int res = 1;
    vector<int> a;
    while(r != 0){
        a.push_back(n);
        a.push_back(r);
        n--;
        r--;
    }

    for(int i=0; i<a.size(); i++){
        if(i%2 == 0){
            res = res*a[i];
        }
    }
    for(int i=0; i<a.size(); i++){
        if(i%2 != 0){
            res = res/a[i];
        }
    }
    printf("%d\n",res);
    return 0;
}

#endif

#ifdef instructor

int dy[21][21];

int DFS(int n, int r){
    if(dy[n][r] > 0) {
        return dy[n][r];
    }
    if(n==r || r==0) return 1;
    else return dy[n][r] = DFS(n-1, r-1) + DFS(n-1, r);
}

int main(){
    freopen("input.txt","rt",stdin);

    int n, r;
    scanf("%d %d", &n, &r);
    printf("%d\n",DFS(n,r));

    return 0;
}
#endif