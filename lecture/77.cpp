#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define instructor

#ifdef mine

int unf[1001];

int Find(int v){
    if(v==unf[v]) return v;
    else return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a!=b) unf[a] = b;
}

int main(){
    freopen("input.txt","rt",stdin);
    int n = 0, m = 0, a,b;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        unf[i] = i;
    }
    for(int i=1; i<=m; i++){
        cin>>a>>b;
        Union(a,b); /// 트리구조를 만드는것

    }
    cin>>a>>b;
    a=Find(a);
    b=Find(b);
    if(a==b) cout<<"YES";
    else cout<<"No";
    return 0;
}

#endif

#ifdef instructor

int unf[1001];

int Find(int v){
    if(v == unf[v]) return v;
    else return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
    if(Find(a)!= Find(b)){
        unf[a] = b;
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    int n = 0, m = 0;
    scanf("%d %d",&n, &m);
    for(int i=1; i<=n; i++){
        unf[i] = i;
    }

    int a, b;
    for(int i=1;i<=m; i++){
        scanf("%d %d",&a, &b);
        Union(a,b);
        
    }
    for(int i=1; i<=n; i++){
        printf("%d\n",unf[i]);
    }
    scanf("%d %d",&a, &b);
    // printf("%d %d\n",Find(a),Find(b));
    if(Find(a)==Find(b)) printf("yes\n");
    else printf("no\n");

    return 0;
}
#endif