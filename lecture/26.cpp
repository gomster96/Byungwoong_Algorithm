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
    vector<int> a(n);
    vector<int> k(n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        k[i] = 1;
    }
    
    
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[i] < a[j]){
                k[i]++;
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%d\n",k[i]);
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