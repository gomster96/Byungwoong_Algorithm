#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
using namespace std;

#define instructor

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    int n = 0;
    scanf("%d",&n);
    int tmp;
    int seq = 1;
    stack<int> s;
    for(int i=0; i<n; i++){
        scanf("%d",&tmp);
        
        if(!s.empty()){
            if(s.top() < tmp) {
                printf("impossible\n");
                return 0;
            }
        }
        else if(i!=0 && s.empty() && tmp != seq ){
            printf("impossible\n");
            return 0;
        }
        s.push(tmp);
        printf("P");
        while(!s.empty() && s.top() == seq){
            printf("O");
            s.pop();
            seq++;
        }
    }
    printf("\n");
    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);

    stack<int> s;
    int i, j=1, n, m;
    scanf("%d",&n);
    vector<int> a(n+1);
    for(i=1; i<=n; i++){
        a[i] = i;
    }
    vector<char> str;
    for(i=1; i<=n; i++){
        scanf("%d", &m);
        s.push(m);
        str.push_back('P');
        while(1){
            if(s.empty()) break;
            if(a[j]==s.top()){
                s.pop();
                j++;
                str.push_back('O');
            }
            else{
                break;
            }
        }
    }
    if(!s.empty()) printf("impossible\n");
    else{
        for(i=0; i<str.size(); i++){
            printf("%c",str[i]);
        }
    }
    return 0;
}
#endif