#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define instructor

#ifdef mine
int a[11] = {0,};
int ch[11] = {0,};
int n = 0;
int flag = 1;
void DFS(int L){
    if(flag == 0) return;

    if(L > n){
        int sum = 0;
        for(int i=1; i<=n; i++){
            if(ch[i]==1) sum += a[i];
            else sum -= a[i];
        }
        if(sum == 0){
            printf("YES\n");
            flag = 0;
        }
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
    int tmp;
    for(int i=1; i<=n; i++){
        scanf("%d",&tmp);
        a[i] = tmp;
    }
    DFS(1);
    if(flag == 1) printf("No\n");
    

    return 0;
}

#endif

#ifdef instructor
//// 나는 그냥 이전문제랑 비슷하게 풀었는데 강사는 더해주는 거를 택했음
//// 더 좋은 아이디어라고 생각함 for문을 돌지 않아도 되기 떄문에
int n, a[11], total = 0;
bool flag = false;
void DFS(int L, int sum){
    if(sum>(total/2)) return; /// 코드의 효율ㄹ성을 위해 필요한 부분 나도 이런것도 생각할 수 있어야함
    if(flag == true) return ;
    if(L==n+1){
        if(sum == (total-sum)){
            flag = true;
        }
    }
    else{
        DFS(L+1, sum+a[L]);
        DFS(L+1, sum);
    }
}

int main(){
    freopen("input.txt","rt",stdin);

    int i;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d",&a[i]);
        total += a[i];
    }
    DFS(1, 0);
    //// lever, 원소의 합
    if(flag) printf("YES\n");
    else printf("No\n");
    return 0;
}
#endif