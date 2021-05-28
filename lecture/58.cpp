#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define instructor

#ifdef mine

void D(int v){
    if(v > 7) return;
    else{
        printf("%d\n",v);
        D(v*2); //왼쪽 노드
        D(v*2+1); //오른쪽 노드
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    D(1);
    return 0;
}

#endif

#ifdef instructor

void D(int v){
    if(v>7) return;
    else{
        printf("%d\n",v);
        D(v*2);
        D(v*2+1);
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    D(1);

    return 0;
}
#endif