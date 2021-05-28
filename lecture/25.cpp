#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define mine

#ifdef mine

int main(){
    //// 빠르게 짜는법을 모르겠음 ... 
    freopen("input.txt","rt",stdin);
    int n =0;
    scanf("%d",&n);
    vector<int>  a(n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    vector<int>  k(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i]>a[j]) k[j]++;
        }
    }
    for(int i=0; i<n; i++){
        printf("%d\n",k[i]+1);
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