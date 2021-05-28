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
    int tmp = 0;
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    vector<int> res(n);
    int s = 0;
    for(int i=n; i>=1; i--){
        if(s == 0){
            res[s++] = i;
        }
        else{
            int count = a[i];
            for(int j = n-1; j>count; j--){
                res[j] = res[j-1];
            }
            res[count] = i;
            s++;
        }
    }
    for(int i=0; i<n; i++){
        printf("%d\n",res[i]);
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