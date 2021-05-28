#include<bits/stdc++.h>
using namespace std;

#define mine

#ifdef mine

// int fastMaxSum(const vector<int> & A, int lo, int hi){
    
//     if(lo == hi) return A[lo];

//     int mid = (lo+hi)/2;

//     int left = 0, right = 0, sum = 0;
//     for(int i = mid; i>=lo; i--){
//         sum+=A[i];
//         left = max(left, sum);
//     }
//     sum = 0;
//     for(int j= mid+1; j <=hi; j++){
//         sum += A[j];
//         right = max(right, sum);
//     }

//     int single = max(fastMaxSum(A,lo,mid),fastMaxSum(A, mid+1, hi));

//     return max(left + right, single);
// }

int fastMaxSum(const vector<int> & A){
    int N = A.size(), ret = 0, psum = 0;
    for(int i=0; i<N; i++){
        psum = max(psum, 0) + A[i];
        ret = max(psum, ret);
        cout << "i: " << i << " psum: " << psum << " ret : " << ret << endl;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    vector<int> a;
    int n = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    // cout << fastMaxSum(a, 0, a.size()-1) << endl;
    cout << fastMaxSum(a) << endl;
    return 0;
}

#endif
#ifdef instructor
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);

    return 0;
}
#endif