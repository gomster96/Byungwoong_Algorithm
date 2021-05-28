#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define instructor

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    

    return 0;
}

#endif

#ifdef instructor
int map[51][51];
int main(){
    freopen("input.txt","rt",stdin);
    int n = 0, m = 0, i, j, a, b, c;
    scanf("%d %d",&n, &m);
    for(i=1; i<=m; i++){
        scanf("%d %d %d",&a, &b, &c);
        map[a][b] = c;
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            printf("%d",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#endif