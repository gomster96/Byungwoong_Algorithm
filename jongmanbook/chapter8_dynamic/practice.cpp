#include<bits/stdc++.h>
using namespace std;

// code 8.10

int lis(const vector<int>& A){
    // basecase
    if(A.empty()) return 0;
    int ret = 0;
    for(int i=0; i<A.size(); i++){
        vector<int> B;
        for(int j=i+1; j<A.size(); j++){
            if(A[i] < A[j]) B.push_back(A[j]);
        }
        ret = max(ret, 1+lis(B));
    }
    return ret;
}

int n;
// int cache[100], S[100];
// Sstart에서 시작하는 증가부분 수열중 최대 길이를 반환한다.
int lis2(int start){
    int &ret = cache[start];
    if(ret != -1) return ret;
    // 항상 S[start]는 있기때문에 최하길이는 1
    ret = 1;
    for(int next = start+1; next<n; next++){
        if(S[start] < S[next])
            ret = max(ret, lis2(next)+1);
    }
    return ret;
}
int lis3(int start){
    int& ret = cache[start+1];
    if(ret != -1) return ret;

    ret = 1;
    for(int next = start+1; next < n; next++){
        if(start == -1 || S[start] < S[next]){
            ret = max(ret, lis3(next)+1);
        }
    }
    return ret; 
}

int n, m, A[100], B[100];
int cache[101][101];
int NEGINF = -2147000000;
int jlis(int indexA, int indexB){
    int& ret = cache[indexA+1][indexB+1];
    if(ret != -1) return ret;

    ret = 2;
    long long a = (indexA == -1 ? NEGINF : A[indexA]);
    long long b = (indexB == -1 ? NEGINF : B[indexB]);
    long long maxElement = max(a,b);

    for(int nextA = indexA+1; nextA < n; nextA++){
        if(maxElement < A[nextA]){
            ret = max(ret, jlis(nextA, indexB) + 1);
        }
    }
    for(int nextB = indexB+1; nextB < m; nextB++){
        if(maxElement <  B[nextB]){
            ret = max(ret, jlis(indexA, nextB) + 1);
        }
    }

    return ret;
}