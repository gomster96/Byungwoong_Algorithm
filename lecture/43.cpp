#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

#define instructor

#ifdef mine

vector<int> a;

int check(int num, int m){
    int sum = 0;
    for(int i=0; i<a.size(); i++){
        if(m == 0) return -1;
        if(sum+a[i]>=num){
            sum = 0;
            m--;
        }
        sum+=a[i];
        
    }
    if(m<=0){
        return -1;
    }
    return 1;
}

int main(){
    freopen("input.txt","rt",stdin);
    int n, m;
    scanf("%d %d",&n,&m);
    int sum = 0;
    int tmp;    
    for(int i=0; i<n; i++){
        scanf("%d",&tmp);
        a.push_back(tmp);
        sum+= tmp;
    }
    int lt = 0, rt = sum;
    int mid = 0;
    while(lt<rt){
        mid = (lt+rt)/2;
        if(check(mid,m)==1){
            rt = mid - 1;
        }
        else{
            lt = mid+1;
        }
        
    }
    printf("%d\n",mid);
    /// sum / m 보단 커야해 
    return 0;
}

#endif

#ifdef instructor

int a[1001], n;

int Count(int s){
    int i, cnt=1, sum=0;
    for(i=1; i<=n; i++){
        if(sum+a[i]>s){
            cnt++;
            sum=a[i];
        }
        else sum = sum+a[i];
    }
    return cnt;
}

int main(){
    freopen("input.txt","rt",stdin);
    int m, i, lt=1, rt=0, mid, res, maxx = -2147000000;
    scanf("%d %d",&n, &m);
    for(i=1; i<=n; i++){
        scanf("%d",&a[i]);
        rt = rt+a[i];
        if(a[i]>maxx) maxx = a[i];
    }

    while(lt<=rt){
        mid = (lt+rt)/2;
        if(mid >= maxx && Count(mid) <= m){
            res = mid;
            rt = mid - 1;
        }
        else{
            lt = mid+1;
        }
    }
    printf("%d\n",res);

    return 0;
}
#endif