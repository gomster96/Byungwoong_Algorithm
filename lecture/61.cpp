#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define instructor

#ifdef mine
int n=0, m=0;
int a[11] = {0,};
int ch[11] = {0,};

void DFS(int L, int* count){
    if(L > n) {
        int sum = 0;
        for(int i=1; i<=n; i++){
            if(ch[i]==1){
                sum+=a[i];
            }
            else if(ch[i] == -1){
                sum-=a[i];   
            }
        }
        if(sum == m) (*count)++;

        return;
    }
    else{
        ch[L] = 1;
        DFS(L+1, count);
        ch[L] = 0;
        DFS(L+1, count);
        ch[L] = -1;
        DFS(L+1, count);
    }
    
}

int main(){
    freopen("input.txt","rt",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    int* count;
    DFS(1, count);
    printf("%d\n",*count);
    return 0;
}

#endif

#ifdef instructor

int a[11], n, m, cnt = 0, path[11];

void DFS(int L, int val){
    if(L==n+1){
        if(val==m){
            cnt++;
            for(int i=1; i<=n; i++){
                printf("%d ",path[i]);
            }
            puts("");
        } 
        
    }
    else{
        path[L] = a[L];
        DFS(L+1, val+a[L]);
        path[L] = 0;
        DFS(L+1, val);
        path[L] = -a[L];
        DFS(L+1, val-a[L]);
        ///이런식으로 더하기 한 과정까지 출력할 수 있음
    }
}

int main(){
    freopen("input.txt","rt",stdin);

    int i;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    DFS(1,0);
    printf("%d\n",cnt);
    return 0;
}
#endif