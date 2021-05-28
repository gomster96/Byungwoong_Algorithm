#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define instructor

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    int s, n;
    scanf("%d %d",&s, &n);
    vector<int> a(s);
    int tmp = 0;
    int index = 0;
    for(int i=0; i<n; i++){
        scanf("%d",&tmp);
        int k = index;
        int key = 0;
        while(k != 0){
            if(tmp == a[k-1]){
                if(k-1==1){
                    int t = a[k-1];
                    a[k-1] = a[k-2];
                    a[k-2] = t;
                    k--;
                }
                else{
                    a[k] = a[k-2];
                    k--;
                }
                index--;
            }
            else{
                a[k] = a[k-1];
            }
            k--;
        }
        if(index < s) index++;
        a[0] = tmp;
        for(int j=0; j<index; j++){
            printf("%d ",a[j]);
        }
        printf("\n");
    }
    return 0;
}

#endif

#ifdef instructor
int C[20];
int main(){
    freopen("input.txt","rt",stdin);
    int s, n, a, i, j, pos;
    scanf("%d %d",&s, &n);
    for(i=1; i<=n;i++){
        scanf("%d",&a);
        pos = -1;
        for(j=0; j<s; j++) if(C[j]==a) pos = j;
        if(pos == -1){
            for(j=s-1; j>=1; j--) C[j] = C[j-1];
        }
        else{
            for(j=pos; j>=1; j--) C[j] = C[j-1];
        }
        C[j] = a;
    }
    for(i=0; i<s; i++) printf("%d ",C[i]);
    return 0;
}
#endif