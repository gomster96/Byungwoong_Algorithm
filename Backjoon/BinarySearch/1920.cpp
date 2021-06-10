#include<bits/stdc++.h>

using namespace std;


vector<int> num;
vector<int> numFind;
int N, M;

int BinarySearch(int lt, int rt, int n){
    int mid = (lt+rt) / 2;
    
    if(lt > rt){
        return 0;
    }
    else{
        if(n == num[mid]){
            return 1;
        }
        else if(n > num[mid]){
            return BinarySearch(mid+1, rt, n);
        }
        else if(n < num[mid]){
            return BinarySearch(lt, mid-1, n);
        }
    }
    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    cin >> N;
    int tmp;
    for(int i=0; i<N; i++){
        cin >> tmp;
        num.push_back(tmp);
    }
    sort(num.begin(), num.end());
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> tmp;
        numFind.push_back(tmp);
    }

    for(int i=0; i<M; i++){
        cout<<BinarySearch(0, num.size(), numFind[i])<<"\n";
    }
    return 0;
}


