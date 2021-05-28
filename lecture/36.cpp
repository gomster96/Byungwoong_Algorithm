/// 매우중요 삽입정렬 

#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define instructor

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    int n;
    scanf("%d",&n);
    vector<int> a(n+1);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=i; j>=0; j--){
            if(a[i]>a[j]) break;
            else {
                swap(a[i],a[j]);
            }
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

    int a[100], n, tmp, i, j;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for(i=1; i<n; i++){
        tmp = a[i];
        for(j=i-1; j>=0; j--){
            if(a[j]>tmp) a[j+1]=a[j];
            else break;
        }
        a[j+1] = tmp;
    }
    for(i=0; i<n; i++){
        printf("%d",&a[i]);
    }

    int a[100], n, tmp, i, j;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for(i=1; i<n; i++){
        tmp = a[i];
        for(j=i-1; j>=0; j--){
            if(a[j]>tmp) a[j+1] = a[j];
            else break;
        }
    }
    return 0;
}
#endif