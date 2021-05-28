#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

#define instructor

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
            if(a[k-1] > a[k]) swap(a[k-1],a[k]);
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
    int a[101], n, i, j, tmp;
    scanf("%d",&n);

    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    return 0;
}
#endif