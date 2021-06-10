#include<cstdio>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> house;
int N, C;

int checkWifi(int val){
    int cnt = 1;
    int prev = house[0];
    for(int i=1; i<N; i++){
        
        if(house[i] - prev >= val){
            cnt++;
            prev = house[i];
        }
    }
    return cnt;
}
int res = 0;

int BinarySearch(int lt, int rt){
    if(lt > rt) return res;
    else{
        int mid = (lt+rt)/2;

        int midVal = checkWifi(mid);
        // printf("mid: %d , midval: %d\n",mid, midVal);
        if(midVal >= C){
            /// 여기서 당연히 mid와 비교했어야하는데 midval과 비교하여틀렸다. 주의
            /// 또한 만약 midVal == C 이렇게하면 이 조건에 걸리지 않을 경우가 반드시 생긴다
            /// ex) 4 3, 1 3 5 7 이럴 경우 항상 케이스는 4가 나오므로 경우에 안걸리 수 있다.
            /// 따라서 그냥 C보다 클때 넣어주는 것으로 문제를 해줘야한다. 주의!
            res = max(res, mid);

            return BinarySearch(mid+1, rt);
        }
        else{
            return BinarySearch(lt, mid-1);
        }
    }
}

int main(){

    // freopen("../input.txt","rt",stdin);
    
    scanf("%d %d",&N, &C);
    int tmp;

    for(int i=0; i<N; i++){
        scanf("%d",&tmp);
        house.push_back(tmp);
    }
    sort(house.begin(), house.end());
    printf("%d\n",BinarySearch(1, house[N-1]-house[0]));
    
    return 0;
}


