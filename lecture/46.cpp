#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define instructor

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    int n = 0, k = 0;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i =0; i<n; i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    int i = -1;
    while(k>0){
        i++;
        if(i>=n) i = 0;
        if(a[i]==0) continue;
        a[i]--;
        k--;
    }
    while(1){
        if(i>=n) i = 0;
        if(a[i]==0){
            i++;
        }
        else{
            printf("%d\n",i+1);
            break;
        }
    }
    return 0;
}

#endif

#ifdef instructor
int a[2001];
int main(){
    freopen("input.txt","rt",stdin);
    int n, k, i, p=0, cnt = 0, tot = 0;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d",&a[i]);
        tot+=a[i];
    }
    scanf("%d",&k);
    if(k>=tot){
        printf("-1\n");
        return 0;
    }
    while(1){
        p++;
        if(p>n) p=1;
        if(a[p]==0) continue;
        a[p]--;
        cnt++;
        if(cnt==k) break;
    }
    while(1){
        p++;
        if(p>n) p =1;
        if(a[p]!=0) break;
    }
    printf("%d\n",p);
    return 0;
}
#endif