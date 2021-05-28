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
    int sum = 0;
    while(n/10!=0){
        int t = n/10;
        int k = n%10;
        if(k>=3){
            sum+=t+1;
        }
        else{
            sum+=t;
        }
        n = n/10;
    }
    if(n>=3){
        sum+=1;
    }
    printf("%d\n",sum);
    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);
    int lt=1, cur, rt, k=1;
    int res = 0;
    int n =0;
    int sum = 0;
    scanf("%d",&n);
    while(lt!=0){
        lt = n/(k*10);
        cur = (n/k)%10;
        rt = n%k;

        if(cur>3){
            res = res+((lt+1)*k);
        }
        else if(cur<3){
            res = res+(lt*k);
        }
        else{
            res  = res+(lt*k)+(rt+1);
        }

        k = k*10;

    }
    printf("%d\n",res);
    return 0;
}
#endif