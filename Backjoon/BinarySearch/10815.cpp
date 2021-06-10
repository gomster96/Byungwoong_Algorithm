#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<int> card;

int BinarySearch(int lt, int rt, int num){
    if(lt > rt) return 0;
    else{
        int mid = (lt+rt) / 2;
        if(card[mid] == num){
            return 1;
        }
        else if(card[mid] > num){
            return BinarySearch(lt, mid-1, num);
        }
        else{
            return BinarySearch(mid+1, rt, num);
        }
    }
}

int main(){
    /// cin.tie(0)을 안썻다고.... 시간초과가 떳다....
    /// 앞으로 그냥 scanf를 써야하는것인가..?
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    cin >> N;
    int tmp;
    for(int i=0; i<N; i++){
        cin >> tmp;
        card.push_back(tmp);
    }
    sort(card.begin(), card.end());
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> tmp;
        
        cout << BinarySearch(0, card.size()-1, tmp) << '\n';
    }
    
    return 0;
}


