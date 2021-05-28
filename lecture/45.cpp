#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define instructor

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    int n = 0 , k = 0;
    scanf("%d %d",&n, &k);
    vector<int> a(n);
    for(int i=0; i<n; i++){
        a[i] = i+1;
    }
    int count = 0;
    int cc = 0;
    int j = -1;
    int res = 0;
    while(count < n){
        
        j++;
        
        if(j >= n) j = 0;
        if(a[j] == 0) continue;
        else{
            cc++;
            // printf("%d\n",cc);
            if(cc == 3){
                res = a[j];
                printf("%d\n",res);
                count++;
                a[j] = 0;
                cc = 0;
            }
            
        }
        
    }
    printf("%d\n",res);
    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);

    int n, k, pos=0, bp = 0, cnt = 0;
    scanf("%d %d",&n, &k);
    vector<int> prince(n+1);
    while(1){
        pos++;
        if(pos>n) pos = 1;
        if(prince[pos]==0){
            cnt++;
            if(cnt == k) {
                prince[pos] = 1;
                cnt = 0;
                bp++;
            }
        }
        if(bp==n-1) break;
    }
    for(int i=1; i<=n; i++){
        if(prince[i]==0){
            printf("%d\n",i);
            break;
        }
    }

    return 0;
}
#endif