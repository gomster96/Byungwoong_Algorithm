#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define mine

#ifdef mine
int data[101];
int tmp[101];

void divide(int lt, int rt){
    int mid;
    int p1, p2, p3;
    if(lt<rt){
        mid = (lt+rt)/2;
        divide(lt, mid);
        divide(mid+1, rt);
        p1 = p3 = lt;
        p2 = mid+1;
        // printf("%d %d %d %d %d %d\n",lt, mid, rt, p1, p2, p3);
        
        while(1){
            // printf("%d %d %d %d %d\n",lt, rt, p1, p2, p3);
            if(p2 == rt+1){
                while(p1 <= mid){
                    tmp[p3++] = data[p1++];
                }
                break;
            }
            else if(p1 == mid+1){
                while(p2 <= rt){
                    tmp[p3++] = data[p2++];   
                }
                break;
            }

            if(data[p1]<data[p2]) tmp[p3++] = data[p1++];
            else tmp[p3++] = data[p2++];
        }
        for(int i=lt; i<=rt; i++){
            data[i] = tmp[i];
        }
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    int n = 0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&data[i]);
    }
    divide(1, n);
    for(int i=1; i<=n; i++){
        printf("%d\n",data[i]);
    }
    return 0;
}

#endif

#ifdef instructor

void divide(int lt, int rt){
    int mid;
    int p1, p2, p3;
    if(lt<rt){
        mid = (lt+rt)/2;
        divide(lt, mid);
        divide(mid+1, rt);

        p1 = lt;
        p2 = mid+1;
        p3 = lt;
        while(p1 <= mid && p2 <= rt){
            if(data[p1] < data[p2]) tmp[p3++] = data[p1++]; 
            else data[p3++] = data[p2++];
        }
        while(p1<=mid) tmp[p3++] = data[p1++];
        while(p2<=rt) tmp[p3++] = data[p2++];

        for(int i=lt; i<=rt; i++){
            data[i] = tmp[i];
        }
    }
}


int data[10], tmp[10];
int main(){
    freopen("input.txt","rt",stdin);
    int n, i;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d",&data[i]);
    }
    divide(1,n);
    for(i=1; i<=n; i++){
        scanf("%d", data[i]);
    }
    

    return 0;
}
#endif