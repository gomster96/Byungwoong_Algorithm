#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define mine

#ifdef mine
vector<int> dist;
int n, c;

int check(int length){
    int count = 1;
    int my_check = dist[0];
    for(int i=0; i<n; i++){
        if(dist[i]-my_check >= length){
            my_check = dist[i];
            count++;
            printf("length: %d mycheck: %d\n",length, my_check);
        }
    }
    return count;
}

int main(){
    freopen("input.txt","rt",stdin);
    
    int lt = 0, mid, rt=0, res = 0;
    scanf("%d %d",&n,&c);
    int tmp;
    for(int i=0; i<n; i++){
        scanf("%d", &tmp);
        dist.push_back(tmp);
    }
    sort(dist.begin(), dist.end());
    lt = dist[0];
    rt = dist[n-1] - lt;
    while(lt<=rt){
        mid = (lt+rt)/2;
        
        if(check(mid) < c){
            rt = mid-1;
        }
        else{
            res = mid;
            lt = mid+1;
        }
        printf("%d %d %d \n",lt, rt, res);
    }
    printf("%d\n",res);
    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);

    return 0;
}
#endif