#include<bits/stdc++.h>
using namespace std;

#define instructor

#ifdef mine

int mp[21][21];
int dt[21][21];
int n = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void DFS(int r, int c){
    if(r == n && c == n){
        return;
    }
    else{
        for(int i=0; i<4; i++){
            int rr = r+dy[i];
            int cc = c+dx[i];
            if(rr >=1 && rr <=n && cc >=1 && cc<=n && (dt[rr][cc] > (mp[rr][cc]+dt[r][c]) || dt[rr][cc] == 0)){
                dt[rr][cc] = mp[rr][cc]+dt[r][c];
                DFS(rr, cc);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    
    cin >> n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> mp[i][j];
        }
    }
    dt[1][1] = mp[1][1];
    DFS(1,1);
    cout<<dt[n][n] << endl;
    return 0;
}

#endif
#ifdef instructor

int arr[21][21], dt[21][21];

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);

    int n, cnt = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    dt[0][0] = arr[0][0];
    for(int i =1; i<n; i++){
        dt[0][i] = dt[0][i-1] + arr[0][i];
        dt[i][0] = dt[i-1][0] + arr[i][0];
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            dt[i][j] = min(dt[i-1][j], dt[i][j-1]) + arr[i][j];
        }
    }
    cout << dt[n-1][n-1];
    return 0;
}
#endif