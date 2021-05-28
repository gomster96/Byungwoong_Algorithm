#include<iostream>
#include<stdlib.h>

using namespace std;
#define instructor
#ifdef mind
int main(){
    freopen("input.txt","rt",stdin);

    int n = 0;
    scanf("%d",&n);
    int t = n;
    int k = 0;
    int sum = 0;
    int count = 9;
    int wholeCount = 0;
    while(1){
        
        t = t/10;
        k++;
        wholeCount += count;
        sum += count*k;
        if(t/10 == 0) break;
        count = count*10;
    }
    sum += k*(n-wholeCount);
    printf("sum:%d\n",sum);
    return 0;
}
#endif
#ifdef instructor
    int main(){

        freopen("input.txt","rt",stdin);
        int n, sum = 0, c = 1, d = 9, res = 0;
        scanf("%d",&n);
        while(sum+d < n){
            res = res+(c*d);
            sum = sum+d;
            c++;
            d = d*10;
        }
        res = res+((n-sum)*c);
        printf("%d\n",res);

        return 0;
    }
#endif
////15153
/// 0~9 10
/// 10~99 90
/// 100~999 900