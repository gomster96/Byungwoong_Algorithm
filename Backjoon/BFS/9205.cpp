#include<bits/stdc++.h>

using namespace std;

struct loc{
    int x, y;
    loc(int a, int b){
        x= a;
        y = b;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    int t;
    int n;
    int ta, tb;
    cin >> t;
    vector<loc> store;
    bool ch[101];
    for(int tt = 0; tt<t; tt++){
        cin >> n;
        cin >> ta >> tb;
        
        memset(ch, false, sizeof(ch));
        queue<loc> q;
        q.push(loc(ta, tb));

        store.clear();
        for(int i=0; i<n; i++){
            cin >> ta >> tb;
            store.push_back(loc(ta, tb));
        }
        cin >> ta >> tb;
        loc end = loc(ta, tb);

        bool flag = false;
        
        while(!q.empty()){
            
            loc ret = q.front();
            q.pop();
            
            int dis = abs(ret.x - end.x) + abs(ret.y - end.y);
            
            if(dis <= 1000){
                flag = true;
                break;
            }
            
            // 편의점 가능여부 확인
            for(int i=0; i<store.size(); i++){
                dis = abs(ret.x - store[i].x) + abs(ret.y - store[i].y);
                if(!ch[i] && dis <= 1000){
                    ch[i] = true;
                    q.push(store[i]);
                }
            }
        }
        if(flag) cout << "happy"<<endl;
        else cout << "sad"<<endl;
    }
    return 0;
}


