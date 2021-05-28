#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define instructor
/// 나는 효과적인 코딩법을 몰라서 포기함

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    int n = 0;
    scanf("%d",&n);
    vector<int> num(n+1);
    vector<int> answer;
    int key = 2;
    for(int i=)
    for(int i=2; i<=n/2; i++){
        while()
    }
    
    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);
    int n ;
    int i, j, tmp;
    scanf("%d",&n);
    vector<int> ch(n+1);

    for(i=2; i<=n; i++){
        tmp = i;
        j = 2;
        while(1){
            if(tmp % j == 0){
                tmp = tmp/j;
                ch[j]++;
            }
            else j++;
            if(tmp==1) break;
        }
    }
    printf("%d! = ",n);
    for(i=2; i<=n; i++){
        if(ch[i]!=0) printf("%d ",ch[i]);
    }
    return 0;
}
#endif