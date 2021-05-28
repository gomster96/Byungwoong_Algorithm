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
    vector<int> k(n);
    vector<int> a(n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n-1; i++){
        k[abs(a[i+1]-a[i])-1]++;
    }
    for(int i=0; i<n-1; i++){
    
        if(k[i]!=1) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);

    return 0;
}
#endif