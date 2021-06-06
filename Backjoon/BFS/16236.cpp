#include<bits/stdc++.h>

using namespace std;

int N;
int mp[22][22];
bool ch[22][22];
int dy[4] = {-1, 0, 0, 1};
// dx를 실수
int dx[4] = {0, -1, 1, 0};
struct fish{
    int r, c, val;
    fish(int aa, int bb, int cc){
        r = aa;
        c = bb;
        val = cc;
    }
    bool operator<(const fish& f) const{
        if(r == f.r) return c < f.c;
        return r < f.r;
    }
};

fish BFS(int r, int c, int shark){
    vector<fish> ans;
    queue<fish> q;
    q.push(fish(r, c, 0));
    mp[r][c] = 0;

    int distance = 0;

    while(!q.empty()){
        fish ret = q.front();
        ch[ret.r][ret.c] = true;
        q.pop();
        if(distance != 0 && ret.val >= distance ) continue;
        for(int i=0; i<4; i++){
            int rr = ret.r + dy[i];
            int cc = ret.c + dx[i];

            if(!ch[rr][cc] && mp[rr][cc]<=shark && rr > 0 && rr<=N && cc>0 && cc<=N){

                if(mp[rr][cc] < shark && mp[rr][cc] != 0){
                    
                    if(distance == 0){
                        distance = ret.val+1;
                    }   
                    ans.push_back(fish(rr, cc, ret.val+1));
                    ch[rr][cc] = true;
                }
                else{
                    
                    ch[rr][cc] = true;
                    q.push(fish(rr,cc,ret.val+1));
                }
            }
        }
       
    }
    sort(ans.begin(), ans.end());
    if(ans.empty()) return fish(0,0, -1);
    return ans[0];
        // fish res = ans[0];
        // ans.clear();
        // return res;
}

int getShark(int r, int c){

    int shark = 2;
    int sharkCount = 0;
    int res = 0;
    int rr = r, cc = c;
    while(1){
        memset(ch, false, sizeof(ch));
        mp[rr][cc] = 0;
        ch[rr][cc] = true;
        fish s = BFS(rr,cc, shark);
        
        if(s.val == -1) return res;
        res += s.val;
        sharkCount++;
        if(sharkCount == shark){
            sharkCount = 0;
            shark++;
        }
        rr = s.r;
        cc = s.c;
        
    }
    
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    cin >> N;
    int R, C;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> mp[i][j];
            if(mp[i][j] == 9){
                R = i;
                C = j;
            }
        }
    }
    
    cout<<getShark(R,C)<<endl;

    return 0;
}


// int BFS(int r, int c){

//     queue<fish> q;
//     queue<fish> ans;
//     q.push(fish(r, c, 0));
//     mp[r][c] = 0;

//     int shark = 2;
//     int sharkCount = 0;
//     int res = 0;
    
//     while(!q.empty()){
//         fish ret = q.front();
//         ch[ret.r][ret.c] = true;
//         q.pop();
//         for(int i=0; i<4; i++){
//             int rr = ret.r + dy[i];
//             int cc = ret.c + dx[i];

//             if(!ch[rr][cc] && mp[rr][cc]<=shark && rr > 0 && rr<=N && cc>0 && cc<=N){

//                 if(mp[rr][cc] < shark && mp[rr][cc] != 0){
                    
//                     mp[rr][cc] = 0;

//                     res = res + ret.val+1;
//                     sharkCount++;
//                     if(sharkCount == shark){                        
//                         sharkCount = 0; 
//                         shark++;
//                     }
                    
//                     while(!q.empty()) q.pop();

//                     memset(ch, false, sizeof(ch));
//                     q.push(fish(rr, cc, 0));
//                     break;
//                 }
//                 else{
                    
//                     ch[rr][cc] = true;
//                     q.push(fish(rr,cc,ret.val+1));
//                 }
//             }
//         }
//     }
    
//     return res;
// }
