#include<bits/stdc++.h>
using namespace std;

#define mine

#ifdef mine
int c, N;
int cache[101];
const int MOD = 1000000007;
int tiling(int n){
    if(n<=1) return 1;
    int& ret = cache[n];
    if(ret != -1) return ret;
    return ret = (tiling(n-1) + tiling(n-2))%MOD;
}
int asymTiling(int n){
    if(n%2 == 1){
        cache
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("../input.txt","rt",stdin);
    

    cin >> c;
    for(int i=0; i<c; i++){
        memset(cache, -1, sizeof(cache));
        cin >> N;
        // cache[1] = 1;
        // cache[2] = 2;
        cout << "N: "<< N<<endl;
        cout<<tiling(N) << endl;
        // cout << asymTiling(N) << endl;
    }

    
    
    return 0;
}

#endif
#ifdef instructor
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    time_t timeStart, timeEnd;
    timeStart = time(NULL);

    timeEnd = time(NULL);
    cout << "execute time: "<<(double)(timeEnd - timeStart) << endl;
    return 0;
}
#endif