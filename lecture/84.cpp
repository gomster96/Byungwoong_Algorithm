#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define instructor

#ifdef mine
int n = 0;
vector<pair<int, int> > sche;
int ch[16];
int res = -2147000000;
void DFS(int L){
    if(L>=n){
        int sum = 0;        
        for(int i=0; i<n; i++){
            if(ch[i]==1){
                sum+=sche[i].second;
            }
        }
        printf("%d\n",sum);
        if(sum>res) res = sum;
    }
    else{
        if(sche[L].first+L > n || L+1 > n){
            DFS(n+1);
            return;
        }
        else{
            ch[L] = 1;
            printf("L: %d\n",L);
            DFS(sche[L].first + L);
            
            ch[L] = 0;
            
            DFS(L+1);
            
        }
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    
    scanf("%d",&n);
    int a, b;
    for(int i=1; i<=n; i++){
        scanf("%d %d",&a , &b);
        sche.push_back(make_pair(a,b));
    }
    DFS(0);
    printf("%d\n",res);
    return 0;
}

#endif

#ifdef instructor
int n, res = -2147000000;
vector<int> T,P;
void DFS(int L, int sum){
    if(L==n+1){
        if(sum>res) res = sum;
        else{
            if(L+T[L]<=n+1) DFS(L+T[L],sum+P[L]);
            DFS(L+1,sum);
        }
    }
}
int main(){
    freopen("input.txt","rt",stdin);
    int a,b;
    cin>>n;
    T.push_back(0);
    P.push_back(0);
    for(int i=0; i<n; i++){
        cin>>a>>b;
        T.push_back(a);
        P.push_back(b);
    }
    DFS(1,0);
    cout<<res;


    return 0;
}
#endif