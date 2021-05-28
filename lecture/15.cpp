#include<iostream>
#include<stdlib.h>

using namespace std;

#define mine

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    int n = 0;
    scanf("%d",&n);
    int count = 0;
    for(int i=2; i<=n; i++){
        int key = 1;
        for(int j = 2; j*j<=i; j++){
            if(i%j == 0){
                key = 0;
                break;
            }
        }
        if(key == 1) count++;
    }
    printf("%d\n",count);
    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);

    return 0;
}
#endif