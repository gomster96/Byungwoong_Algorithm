#include<bits/stdc++.h>

using namespace std;

int dRC[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int cache[4][102][102];
char mp[102][102];
int res = 2147000000;
pair<int,int> findWall(int r, int c, int direction){

    while(1){
        
        r = r+dRC[direction][0];
        c = c+dRC[direction][1];
        if(mp[r][c] == '0' ){
            cout<<"aaaaaaaa"<<endl;
            break;
        }
        if(mp[r][c] == 'B' || mp[r][c] == 'R' || mp[r][c] == '#'){
            return make_pair(r-dRC[direction][0], c-dRC[direction][1]);
        }
    }
    
    return make_pair(r,c);
}

int DFS(int L, int rR, int cR, int rB, int cB, int direction){
    if(L > 10){
        return 100;
    }
    
    int& ret = cache[direction][rR][cR];
    
    if(ret != -1) return ret;
    
    ret = 15;
    for(int i=0; i<4; i++){
        // 방향이 중복되거나 원 방향으로 돌아가는 경우 
        
        if((i+direction)%2 == 0) continue;
        

        pair<int, int> tR = findWall(rR, cR, i);
        int rrR = tR.first;
        int ccR = tR.second;
        
        pair<int, int> tB = findWall(rB, cB, i);
        int rrB = tB.first;
        int ccB = tB.second;
        // 게임이 잘못 끝난 경우
        cout<<rR<<" " << cR << " " << i << endl;
        if(mp[rrB][ccB] == '0') return 15;
        if(rR == rrR && cR == ccR) continue;
        if(mp[rrR][ccR] == '0'){
            
            if(res > L+1){
                res = L+1;
            }
            return res;
        }
        ret = min(ret, DFS(L+1, rrR, ccR, rrB, ccB, i));
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("../input.txt","rt",stdin);
    memset(mp, '*', sizeof(mp));
    memset(cache, -1, sizeof(cache));
    int R, C;
    cin >> R >> C;
    int rr, cr;
    int rb, cb;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> mp[i][j];
            if(mp[i][j] == 'R'){
                rr = i;
                cr = j;
            }
            if(mp[i][j] == 'B'){
                rb = i;
                cb = j;
            }

        }
    }
    for(int i=0; i<4; i++){
        DFS(0, rr, cr, rb, cb, i);
    }
    
    cout<<res<<endl;
    return 0;   
}


