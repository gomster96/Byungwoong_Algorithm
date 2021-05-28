#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
using namespace std;

#define instructor

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);

    return 0;
}

#endif

#ifdef instructor

int stack[100], top=-1;

void push(int x){
    stack[++top] = x;
}
int pop(){
    return stack[top--];
}

int main(){
    freopen("input.txt","rt",stdin);

    int n, k;
    char str[20] = "0123456789ABCDEF";
    scanf("%d %d",&n, &k);
    //stack<int> s;
    while(n>0){
        push(n%k);
        // s.push(n%k)
        n=n/k;
    }
    while(top!=-1){ //!s.empty()
        printf("%c",str[pop()]);
    }
    return 0;
}
#endif