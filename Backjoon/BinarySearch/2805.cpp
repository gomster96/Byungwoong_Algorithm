#include<bits/stdc++.h>

using namespace std;

// 틀린이유 1 long long 으로 선언해주는 것을 생각하지 못함

int N, M;
vector<int> arr;
int res;
int resVal = 2147000000;
long long getSum(int num){
    long long sum = 0;
    for(int i=1; i<=N; i++){
        if(arr[i] > num){
            sum += arr[i]-num;
        }
    }
    return sum;
}

int BinarySearch(int lt, int rt){
    if(lt>rt){
        return res;
    }
    else{
        int mid = (lt+rt) / 2;
        long long ret = getSum(mid);
        if(ret == M){
            return mid;
        }
        else if(ret > M){
            if(resVal > ret){
                res = mid;
            }
            return BinarySearch(mid+1, rt);
        }
        else{
            return BinarySearch(lt, mid-1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("../input.txt","rt",stdin);
    cin >> N >> M;
    int tmp;
    arr.push_back(0);
    for(int i=1; i<=N; i++){
        cin >> tmp;
        arr.push_back(tmp);
        
    }
    sort(arr.begin(), arr.end());
    /// 두번째 틀린이유 아무생각없이 arr[1]을 넣었음 모든 나무의 크기도 같을수 있음을 생각했어야한다. 
    cout<<BinarySearch(1, arr[N])<<endl;
    // cout<<BinarySearch(arr[1], arr[N])<<endl;
    return 0;
}


