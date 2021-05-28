#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define instructor

#ifdef mine

int main(){
    freopen("input.txt","rt",stdin);
    int n, res;
    cin >> n;
    vector<int>  a(n+1);
    vector<pair<int, int> > dt(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int maxCount = 0;
    
    
    dt[1] = make_pair(a[1], 1);
    int lastNum = a[1];
    for(int i=2; i<=n; i++){
        int cnt = 0;
        for(int j=i; j>=1; j--){
            if( a[i]>a[j]){
                cnt++;
            }
        }
        
        if(cnt > maxCount){
            maxCount = cnt;
            
        }
    }

    return 0;
}

#endif

#ifdef instructor
int main(){
    freopen("input.txt","rt",stdin);

    int n, res = 0;
    cin >> n;
    vector<int> arr(n+1), dy(n+1);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    dy[1] = 1;
    for(int i=2; i<=n; i++){
        int max = 0;
        for(int j=i-1; j>=1; j--){
            if(arr[j] < arr[i] && dy[j] > max){
                max = dy[j];
            }
        }
        dy[i] = max+1;
        if(dy[i]>res) res = dy[i];
    }
    
    cout << res << endl;

    return 0;
}
#endif