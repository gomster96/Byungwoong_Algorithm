#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define mine

#ifdef mine

struct Edge{
    int v1, v2, val;
    Edge(int a, int b, int c){
        v1 = a;
        v2 = b;
        val = c;
    }
    bool operator< (const Edge& v) const{
        return val<v.val;
    }
};
int unf[26];
int Find(int a){
    if(unf[a] == a) return a;
    else return unf[a] = Find(unf[a]);
}

void Union(int a, int b){
    a= Find(a);
    b = Find(b);
    if(a != b){
        unf[a] = b;
    }
}
int main(){
    freopen("input.txt","rt",stdin);
    int v = 0, e = 0 , c = 0;
    int n = 0, m = 0;
    scanf("%d %d",&n, &m);
    vector<Edge> a;
    int res = 0;
    
    for(int i=1; i<=n; i++){
        unf[i]= i;
    }
    for(int i=1; i<=m; i++){
        scanf("%d %d %d",&v, &e, &c);
        a.push_back(Edge(v,e,c));
    }
    sort(a.begin(), a.end());
    for(int i=0; i<m; i++){
        
        if(Find(a[i].v1)!=Find(a[i].v2)){
            printf("%d %d %d\n",a[i].v1,a[i].v2,a[i].val);
            res+=a[i].val;
            Union(a[i].v1, a[i].v2);
        }
        
    }
    printf("%d\n",res);
    return 0;
}

#endif

#ifdef instructor

int unf[10001];

struct Edge{
    int v1;
    int v2;
    int val;
    Edge(int a, int b, int c){
        v1 = a;
        v2 = b;
        val = c;
    }
    bool operator<(const Edge &b ) const {
        return val<b.val;
    }
};

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
    vector<Edge> Ed;
    int i, n, m, a, b, c, cnt = 0, res = 0;
    scanf("%d %d",&n, &m);
    for(i=1; i<=n; i++){
        unf[i] = i;
    }
    for(i=1; i<=m; i++){
        scanf("%d %d %d",&a, &b, &c);
        Ed.push_back(Edge(a,b,c));
    }
    sort(Ed.begin(), Ed.end());
    for(i=0; i<m; i++){
        int fa = Find(Ed[i].v1);
        int fb = Find(Ed[i].v2);
        if(fa != fb){
            res+=Ed[i].val;
            Union(Ed[i].v1, Ed[i].v2);
        }
    }
    printf("%d\n",res);
    return 0;
}
#endif