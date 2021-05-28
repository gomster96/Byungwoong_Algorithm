#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define instructor

#ifdef mine
int a[11] = {0,};
int n = 0;

void D(int s){
    if(s>=n) {
        for(int i=0; i<n; i++){
            if(a[i]==0) continue;
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    else{
        D(s+1);
        // printf("a[s-1] %d\n",a[s-1]);
        a[s] = 0;
        // printf("a[s-1] %d\n",a[s-1]);
        D(s+1);
        a[s] = s+1;
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        a[i] = i+1;
    }
    D(1);    
    return 0;
}

#endif

#ifdef instructor
int n, ch[11];

void DFS(int L){
    int i;
    if(L==n+1){
        for(i=1; i<=n; i++){
            if(ch[i]==1) printf("%d ",i);
        }
        puts("");
    }
    else{
        ch[L] = 1;
        DFS(L+1);
        ch[L] = 0;
        DFS(L+1);
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    scanf("%d",&n);
    
    DFS(1);

    return 0;
}
#endif