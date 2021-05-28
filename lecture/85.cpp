#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define instructor

#ifdef mine
int a[11];
int op[5];
int n = 0;
int res_max = -2147000000;
int res_min = 2147000000;
void DFS(int L, int sum){
    if(L == n){
        
        if(sum > res_max) res_max = sum;
        if(sum < res_min) res_min = sum;
        return ;
    }
    else{
        for(int i=1; i<=n; i++){
            if(op[i] > 0){
                op[i]--;
                if(i==1){
                    DFS(L+1, sum+a[L+1]);
                }
                else if(i==2){
                    DFS(L+1, sum-a[L+1]);
                }
                else if(i==3){
                    DFS(L+1, sum*a[L+1]);
                }
                else{
                    DFS(L+1, sum/a[L+1]);
                }
                op[i]++;
            }
        }
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    for(int i=1; i<=n; i++){
        scanf("%d",&op[i]);
    }
    DFS(1, a[1]);
    printf("%d %d\n",res_max, res_min);
    return 0;
}

#endif

#ifdef instructor

int a[20], op[5], n, maxi=-2147000000, mini=2147000000;
void DFS(int L, int res){
    if(L==n){
        if(res>maxi) maxi = res;
        if(res<mini) mini = res;
    }
    else{
        if(op[0]>0){
            op[0]--;
            DFS(L+1, res+a[L]);
            op[0]++;
        }
        if(op[1]>0){
            op[1]--;
            DFS(L+1, res-a[L]);
            op[1]++;
        }
        if(op[2]>0){
            op[2]--;
            DFS(L+1, res*a[L]);
            op[2]++;
        }
        if(op[3]>0){
            op[3]--;
            DFS(L+1, res/a[L]);
            op[3]++;
        }
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    int i;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for(i=0; i<4; i++){
        scanf("%d",&op[i]);
    }
    DFS(1, a[0]);
    printf("%d\n%d\n",maxi, mini);
    return 0;
}
#endif