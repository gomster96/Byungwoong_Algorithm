#include<bits/stdc++.h>
using namespace std;

#define mine

#ifdef mine
int k = 0, n = 0;

int a[5][5];
int py, px;
int dx[4][3] = {{0, 1, 1},{0, 1, 0},{0, 0, -1},{0, 0, 1}};
int dy[4][3] = {{0, 0, 1},{0, 0, 1},{0, 1, 1},{0, 1, 1}};
int flag = 0;

void BFS(int L){
    int x = -1, y = -1;
    for(int j=1; j<=n; j++){
        for(int i=1; i<=n; i++){
            if(a[i][j] == 0){     
                x = i;
                y = j;
                break;
            }
        }
        if(x != -1) break;
    }
    
    if(x == -1 && y == -1){
        flag = 1;
        return;
    }
    
    for(int i=0; i<4; i++){
        int possi = 1;
        
        for(int j=0; j<3; j++){
            if(x+dx[i][j] == 0 || x+dx[i][j] > n || y+dy[i][j] == 0 || y+dy[i][j] > n || a[x+dx[i][j]][y+dy[i][j]] != 0){
                possi = 0;
                break;
            }
        }
        
        if(possi == 1){
            
            for(int j=0; j<3; j++){
                a[x+dx[i][j]][y+dy[i][j]] = L;
            }
            BFS(L+1);
            
            if(flag == 1) return;
            for(int j=0; j<3; j++){
                a[x+dx[i][j]][y+dy[i][j]] = 0;
            }
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);
   
    
    cin >> k;
    n = pow(2, k);
    cin >> px >> py;
    
    memset(a, 0, sizeof(a));
    a[px][py] = -1;
    BFS(1);
    if(flag == 1){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout << a[j][n-i+1] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout<<-1<<endl;
    }
    
    
    
    return 0;
}

#endif
