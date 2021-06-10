#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

long long N, M;
vector<long long> desk;
long long checkTime(long long time){
    long long ret = 0;
    for(int i=0; i<desk.size(); i++){
        ret = ret + (time / desk[i]);
    }
    return ret;
}

long long res = 1e18;
long long BinarySearch(long long lt, long long rt){
    if(lt > rt){
        return res;
    }
    else{
        long long mid = (lt + rt) / 2;
        long long midVal = checkTime(mid);

        if(midVal >= M){
            if(res > mid) res = mid;
            return BinarySearch(lt, mid-1);
        }
        else{
            return BinarySearch(mid+1, rt);
        }
    }
}

int main(){

    // freopen("../input.txt","rt",stdin);

    scanf("%lld %lld",&N, &M);

    long long tmp = 0;
    // long long mmin = 2147000000;
    for(int i=0; i<N; i++){
        scanf("%lld",&tmp);
        // if(tmp < mmin) mmin = tmp;
        desk.push_back(tmp);
    }
    sort(desk.begin(), desk.end());
    // printf("%lld\n",BinarySearch(1, mmin*M)) ;
    printf("%lld\n",BinarySearch(1, desk[N-1]*M)) ;
    return 0;
}

// 틀린이유 1 : 출력시 long long 이면 print도 lld로 해주기
// 틀린이유 2 : long long type을 반환시키는 것이면 long long으로 적어주어야 한다. 
