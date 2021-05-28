#include<iostream>
#include<stdlib.h>

using namespace std;

#define mine

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    
    int a[10] = {0,};
    /// 왜 이렇게 초기화를 다 해줘야 하는거지??
    char str[101];
    scanf("%s",str);
    
    for(int i=0; str[i]!='\0'; i++){
        a[str[i]-'0']++;
    }
    int max = -1;
    int ans = 0;
    for(int i=0; i<10; i++){
        if(a[i]>=max){
            max = a[i];
            ans = i;
            
        }
    }
    printf("%d\n",ans);

    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);

    return 0;
}
#endif