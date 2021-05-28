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
    int k =2;
    
    while(1){
        int t = k;
        int sum = 0;
        while(t!=0){
            sum += t;
            t--;
        }
        if(sum > n) break;
        if((n-sum)%k ==0){
            t++;
            while(t<k){
                printf("%d + ",(n-sum)/k+t);
                t++;
            }
            printf("%d = %d",(n-sum)/k+t,n);
            printf("\n");
        }
        
        k++;
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