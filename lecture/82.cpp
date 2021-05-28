#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;

#define mine

#ifdef mine

int n, r;
int a[21];
int ch[21];
int cnt = 0;
int res[21];
queue<int> q;
void DFS(int L){
    if(L>r){
        for(int i=1; i<=n; i++){
            if(res[i] != 0) printf("%d ",res[i]);
        }
        puts("");
        cnt++;
    }
    else{
        for(int i=1; i<=n; i++){
            if(ch[i]==0){
                ch[i] = 1;
                res[L] = a[i];
                DFS(L+1);
                ch[i] = 0;
                res[L] = 0;
            }
        }
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    
    scanf("%d %d",&n, &r);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);        
    }
    
    DFS(1);
    printf("%d\n",cnt);
    return 0;
}

#endif

#ifdef instructor
int n, r, cnt = 0;
int a[20], res[20], ch[20];
void DFS(int L){
    if(L==r){
        for(int j=0; j<L; j++){
            printf("%d ",res[j]);
        }
        cnt++;
        puts("");
    }
    else{
        for(int i=1; i<=n; i++){
            if(ch[i] == 0){
                res[L] = a[i];
                ch[i] = 1;
                DFS(L+1);
                ch[i] = 0;
            }
        }
    }
}

int main(){
    freopen("input.txt","rt",stdin);

    scanf("%d %d",&n, &r);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    DFS(0);
    printf("%d\n",cnt);

    return 0;
}
#endif