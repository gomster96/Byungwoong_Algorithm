#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
using namespace std;

#define instructor

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);

    return 0;
}

#endif

#ifdef instructor

int ch[10001], d[3] = {1, -1, 5};

int main(){
    freopen("input.txt","rt",stdin);

    int s, e, x, pos;
    queue<int> Q;
    scanf("%d %d",&s, &e);
    ch[s] = 1;
    Q.push(s);
    while(!Q.empty()){
        x = Q.front();
        Q.pop();
        for(int i=0; i<3; i++){
            pos = x+d[i];
            if(pos<=0 || pos > 10000) continue;
            if(pos==e){
                printf("%d\n",ch[x]); /// 출발을 1 로 했으니 도착 바로 전 지점이 결국 횟수
            }
            if(ch[pos]==0){
                ch[pos] = ch[x] + 1;
                Q.push(pos);
            }
        }
    }

    return 0;
}
#endif