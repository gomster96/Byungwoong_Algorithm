#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define mine

#ifdef mine

int n, r;
int ch[20];
//// 암기하기 
void DFS(int s, int L){
    if(L==r){
        ///// 이걸로 r개만큼 뽑는다는 것을 설정하기 
        for(int j=0; j<L; j++){
            cout << ch[j] << " ";
        }
        cout<<endl;
    }
    else{
        for(int i=s; i<n; i++){
            ch[L] = i;
            DFS(i+1, L+1); //// 그 다음꺼로 돌게 만들어서 가지를 하나 줄임 --> 즉 중복이 생길 일이 없음
            // ch 를 바꿔줄 필요 없음 -> 결국 바뀌니까
        }
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    cin>>n>>r;
    DFS(0,0);
    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);

    return 0;
}
#endif