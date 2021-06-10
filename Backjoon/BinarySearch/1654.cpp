#include<bits/stdc++.h>

using namespace std;

int N, K;
vector<int> a;

//// 문제에서 lt, rt, 그리고 최대값 m까지 long long으로 받아야 답이 해결된다.
//// 바보같이 최대값이 2147000000이지만 이는 2^32보다 작은값이다... 하지만 문제에서 mid를 계산할때
//// int형의 범위를 넘어버린다. 따라서 lt와 rt도 long long으로 해주어야한다 . 

long long getNumberOfLine(int num, int length){
    long long cnt = 0;
    // 0보다 크다가 아니라 크거나 같다이다.... 여기서 문제 틀림
    while(num-length >= 0){
        cnt++;
        num = num-length;
    }
    return cnt;
}
int res = 0;
int BinarySearch(long long lt, long long rt){
    if(lt > rt){
        return res;
    }
    else{
        
        long long mid = (lt+rt) / 2;

        long long numOfLine = 0;
        for(int i=0; i<N; i++){
            numOfLine += getNumberOfLine(a[i], mid);
        }

        /// 항상 정확히 필요한 부분까지만 하면 되는거라고 생각했지만 N개보다 더 많이 만드는것도 N개를 만드는것에 포함된다. 
        if(numOfLine >= K){
            if(mid > res){
                
                res = mid;
            }
            return BinarySearch(mid+1, rt);
        }
        else {
            return BinarySearch(lt, mid-1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);

    cin >> N >> K;
    int tmp;
    int m = 0;
    for(int i=0; i<N; i++){
        cin >> tmp;
        a.push_back(tmp);
        if(tmp > m ) m = tmp;
    }

    cout<<BinarySearch(1, m) << endl;
    return 0;
}


