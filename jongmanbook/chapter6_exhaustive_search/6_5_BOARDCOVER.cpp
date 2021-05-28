#include<bits/stdc++.h>
using namespace std;

#define instructor

#ifdef mine

int mp[22][22];
int c = 0, h = 0, w = 0;
int dy[4][3] = {{0, 1, 1}, {0, 1, 1}, {0, 0, 1}, {0, 0, 1}};
int dx[4][3] = {{0, -1, 0}, {0, 0, 1}, {0, 1, 1}, {0, 1, 0}};

int countBoard(){
    int nextH = -1;
    int nextW = -1;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(mp[i][j] == 1){
                nextH = i;
                nextW = j;
                break;
            }
        }
        if(nextH != -1 && nextW != -1) break;
    }
    if(nextH == -1 && nextW == -1) return 1;
    int res = 0;
    
    

    for(int i=0; i<4; i++){
        int flag = 1;
        for(int j=0; j<3; j++){
            if(mp[nextH+dy[i][j]][nextW+dx[i][j]] == 0){
                flag = 0;
            }
        }
        if(flag == 1){
            for(int j=0; j<3; j++){
                mp[nextH+dy[i][j]][nextW+dx[i][j]] = 0; 
            }
            res += countBoard();
            for(int j=0; j<3; j++){
                mp[nextH+dy[i][j]][nextW+dx[i][j]] = 1; 
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    
    cin >> c;
    for(int k=0; k<c; k++){
        cin >> h >> w;
        char tmp = 0;
        int dotCount = 0;
        memset(mp, 0, sizeof(mp));
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                cin >> tmp;
                if(tmp == '.'){
                    mp[i][j] = 1;
                    dotCount++;
                }
                
            }
        }
        
        if((dotCount % 3) != 0) cout<<0<<endl;
        else cout<<countBoard()<<endl;
        
    }
    return 0;
}

#endif
#ifdef instructor

const int coverType[4][3][2] = {
    {{0,0}, {1,0}, {0,1}},
    {{0,0}, {0,1}, {1,1}},
    {{0,0}, {1,0}, {1,1}},
    {{0,0}, {1,0}, {1,-1}}
};

bool sat(vector<vector<int> >&board, int y, int x, int type, int delta){
    bool ok = true;
    for(int i=0; i<3; i++){
        const int ny = y+coverType[type][i][0];
        const int nx = x+coverType[type][i][1];
        if(ny<0 || ny>=board.size() || nx <0 || nx>board[0].size()) ok = false;
        else if((board[ny][nx] += delta) > 1) ok = false;
    }
    return ok;
}

int cover(vector<vector<int> > &board){
    int y =-1, x= -1;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] == 0){
                y = i;
                x = j;
                break;
            }
        }
        if(y!=-1) break;
    }

    if(y == -1) return 1;
    int ret = 0;
    for(int type = 0; type<4; type++){
        if(sat(board, y, x, type, 1)){
            ret += cover(board);
            sat(board, y, x, type, -1);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    
    cin >> c;
    for(int k=0; k<c; k++){
        cin >> h >> w;
        char tmp = 0;
        int dotCount = 0;
        memset(mp, 0, sizeof(mp));
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                cin >> tmp;
                if(tmp == '.'){
                    mp[i][j] = 1;
                    dotCount++;
                }
                
            }
        }
        
        if((dotCount % 3) != 0) cout<<0<<endl;
        else cout<<countBoard()<<endl;
        
    }
    return 0;
}

#endif