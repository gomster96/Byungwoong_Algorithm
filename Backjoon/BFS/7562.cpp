#include<bits/stdc++.h>

using namespace std;

int T, N;
int mp[302][302];
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
struct Knight{
    int r, c, val;
    Knight(int a1, int a2, int a3){
        r= a1;
        c = a2;
        val = a3;

    }
};
int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N;
        memset(mp, 0, sizeof(mp));
        int ta, tb;
        cin >> ta >> tb;
        Knight start = Knight(ta+1, tb+1, 0);
        cin >> ta >> tb;
        Knight end = Knight(ta+1, tb+1, 0);

        queue<Knight> q;
        q.push(start);
        mp[start.r][start.c] = -1;
        int flag = 0;
        int res = 0;
        while(!q.empty() && flag == 0){
            Knight knight = q.front();
            // cout << knight.r << " " <<knight.c  << " " << knight.val <<endl;
            q.pop();
            for(int i=0; i<8; i++){
                int rr = knight.r + dy[i];
                int cc = knight.c + dx[i];
                if(mp[rr][cc] == 0 && rr > 0 && cc>0 && rr<=N && cc<=N){
                    if(rr == end.r && cc == end.c){
                        res = knight.val + 1;
                        flag = 1;
                        break;
                    }
                    mp[rr][cc] = -1;
                    q.push(Knight(rr, cc, knight.val+1));
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}


