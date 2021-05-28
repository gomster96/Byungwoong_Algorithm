#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define mine

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    int n = 0;
    int min = 0;
    scanf("%d",&n);
    vector<int> a(n+1);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }

    for(int i = 0; i<n; i++){
        min = i;
        for(int j=i+1; j<n; j++){
            if(a[min] > a[j]){
                min = j;
            }
        }
        int tmp = a[min];
        a[min] = a[i];
        a[i] = tmp;
    }
    for(int i=0; i<n; i++){
        printf("%d \n",a[i]);
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