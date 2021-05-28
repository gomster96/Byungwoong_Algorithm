#include<bits/stdc++.h>

using namespace std;

int w, h;
int a[52][52];
int cnt;
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void DFS(int r, int c){

    for(int i=0; i<8; i++){
        int rr = r+dy[i];
        int cc=  c+dx[i];
        if(a[rr][cc] == 1){
            a[rr][cc] = 0;
            DFS(rr, cc);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);

    

    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        cnt = 0;
        memset(a, 0, sizeof(a));

        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                cin >> a[i][j];
            }
        }
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                if(a[i][j] == 1){
                    cnt++;
                    a[i][j] = 0;
                    DFS(i,j);
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}


