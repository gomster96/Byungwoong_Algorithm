#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
using namespace std;

#define instructor

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    stack<char> s;

    char str[31];
    scanf("%s",str);

    for(int i=0; str[i]!='\0'; i++){
        if(str[i] == '(') s.push('(');
        else{
            if(s.empty()){
                printf("No\n");
                return 0;
            }
            else{
                s.pop();
            }
        }
    }
    if(!s.empty()){
        printf("No\n");
    }
    else printf("Yes\n");
    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);
    stack<char> s;
    char a[50];
    int i;
    scanf("%s",&a);
    for(i=0; a[i]!='\0'; i++)    {
        if(a[i]=='(') s.push(a[i]);
        else{
            if(s.empty()){
                printf("No\n");
                break;
            }
            else s.pop();
        }
    }
    if(s.empty()) printf("YES\n");
    else printf("No\n");;

    return 0;
}
#endif