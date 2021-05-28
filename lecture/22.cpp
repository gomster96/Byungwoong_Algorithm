#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define mine

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    int n, k;
    scanf("%d %d",&n,&k);
    vector<int>a(n);
    int pre = 0, next = k;
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    int sum = 0;
    for(int i=0; i<k; i++){
        sum+=a[i];
    }
    int max = sum;
    for(int i=k; i<=n-k; i++){
        sum -= a[pre++];
        sum += a[next++];
        if(sum > max) max = sum;
    }
    printf("%d\n",max);
    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);

    return 0;
}
#endif