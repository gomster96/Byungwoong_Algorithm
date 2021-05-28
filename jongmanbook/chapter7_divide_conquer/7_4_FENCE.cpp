#include<bits/stdc++.h>
using namespace std;

#define instructor

#ifdef mine
///// 나는 이분검색을 이용해서 높이를 찾아가려고 했으나 결국 이것은 해결할수없는 방법임 --> 찾아야 하는 값이 있지 않기 때문에! 
/// 찾아야 하는 값이 있다면 이분검색으로도 해결 할 수 있지만 이 문제같은경우에는 내가 찾아야 하는거기때문에 이분검색으로 불가.
int res = -2147000000;
int c = 0;
int n = 0;
int pan[20001];

int checkArea(int h){
    int area = 0;
    int resArea = 0;
    for(int i=1; i<=n; i++){
        if(pan[i] > h){
            area += pan[i];
        }
        else{
            if(area > resArea) resArea = area;
            area = 0;
        }
    }
    return resArea;
}

void findH(int sH, int bH){
    if(sH >= bH) return;
    int mid = (sH + bH) / 2;

}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    time_t timeStart, timeEnd;
    timeStart = time(NULL);
    
    
    int bigH = -2147000000;
    int smaH = 2147000000; 
    cin >> c;
    for(int k =0; k<c; k++){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> pan[i];
            if(pan[i] > bigH) bigH = pan[i];
            if(pan[i] < smaH) smaH = pan[i];
        }
        
        findH(smaH, bigH);

        memset(pan, 0, sizeof(int)*(n+1));
        res = -2147000000;
    }

    timeEnd = time(NULL);
    cout << "execute time: "<<(double)(timeEnd - timeStart) << endl;
    
    return 0;
}

#endif
#ifdef instructor

vector<int> h;

int solve(int left, int right){
    // 기저사례 : 판자가 하나밖에 없는 경우
    if(left == right) return h[left];
    //[left, mid], [mid+1, right]의 두 구간으로 문제를 분할한다
    int mid = (left + right) / 2;

    int ret = max(solve(left, mid), solve(mid+1, right));
    // 이중 사각형이 더 큰것을 찾기
    int lo = mid, hi = mid+1;

    int height = min(h[lo], h[hi]);
    
    ret = max(ret, height*2);

    while(left < lo || hi < right){
        if(hi < right && (lo == left || h[lo-1]<h[hi+1])){
            hi++;
            height = min(height, h[hi]);
        }
        else{
            lo--;
            height = min(height, h[lo]);
        }
        ret = max(ret, height*(hi - lo +1));
    }
    return ret;
}

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