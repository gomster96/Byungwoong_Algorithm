#include<iostream>
#include<stdlib.h>

using namespace std;

#define mine

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    int n = 0;
    int num;
    int predict;
    int answer;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d %d",&num, &predict);
        answer = num*(1+num)/2;
        
        if(predict == answer) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);

    return 0;
}
#endif