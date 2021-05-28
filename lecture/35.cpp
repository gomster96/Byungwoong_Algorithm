#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

#define mine

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    int n = 0;
    scanf("%d",&n);
    vector<int> a(n+1);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n; i++){
        int k = n-i;
        while(k!=1){
            k--;
            if(a[k-1]>0 && a[k]<0) swap(a[k-1],a[k]);
        }
    }
    for(int i=0; i<n; i++){
        printf("%d\n",a[i]);
    }
    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);

    return 0;
}
#endif