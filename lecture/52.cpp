#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define instructor

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    int n = 0;
    scanf("%d",&n);
    
    return 0;
}

#endif

#ifdef instructor
int a[1501];
int main(){
    freopen("input.txt","rt",stdin);
    int n, i, p2, p3, p5, min = 2147000000;
    scanf("%d",&n);
    a[1] = 1;
    p2=p3=p5=1;
    for(i=2; i<=n; i++){
        if(a[p2]*2 < a[p3]*3) min = a[p2]*2;
        else min = a[p3]*3;
        if(a[p5]*5 < min) min = a[p5]*5;
        if(a[p2]*2 == min) p2++;
        if(a[p3]*3 == min) p3++;
        if(a[p5]*5 == min) p5++;
        a[i]==min;
    }
    printf("%d\n",a[n]);
    return 0;
}
#endif