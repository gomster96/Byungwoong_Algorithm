#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

#define instructor

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    int n, m;
    scanf("%d %d",&n,&m);
    vector<int> a(n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    sort(a.begin(), a.end());
    int lt = 0;
    int rt = n-1;
    int mid = 0;
    while(lt<rt){
        mid = (lt+rt)/2;
        if(a[mid]>m) rt = mid-1;
        else lt = mid+1;
        
    }
    printf("%d\n",lt+1);

    // for(int i=0; i<n; i++){
    //     printf("%d\n",a[i]);
    // }




    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);

    int n, i, key, lt =0, rt, mid;
    scanf("%d %d",&n,&key);
    vector<int> a(n);

    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    sort(a.begin(), a.end());
    //// begin은 첫번째 주소를 가르키는 포인터, end는 마지막의 그 다음번째 주소를 가르키는 포인터
    while(lt<=rt){
        mid = (lt+rt)/2;
        if(a[mid]==key){
            printf("%d\n",mid+1);
            return 0;
        }
        else if(a[mid] > key){
            rt = mid-1;
        }
        else{
            lt = mid+1;
        }
    }

    return 0;
}
#endif