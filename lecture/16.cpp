#include<iostream>
#include<stdlib.h>

using namespace std;

#define mine

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    char str[101];
    int a[101] = {0,};
    scanf("%s",str);
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]>=97){
            a[str[i]-70]++;
        }
        else{
            a[str[i]-64]++;
        }
    }
    str[0] =  '\0';
    ///// string의 buffer 지우는 방법
    scanf("%s",str);
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]>=97){
            a[str[i]-70]--;
        }
        else{
            a[str[i]-64]--;
        }
    }
    for(int i=0; i<101; i++){
        if(a[i]!=0){
            printf("No");
            return 0;
        } 
    }
    printf("Yes");
    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);

    return 0;
}
#endif