#include<bits/stdc++.h>

using namespace std;

bool ch[1000001];
// F 전체 층, S 지금 위치, G가야할 층 
int F, S, G, U, D;
struct Elve{
    int state, cnt;
    Elve(int a, int b){
        state = a;
        cnt = b;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    
    cin >> F >> S>> G>> U>>D;
    int res = -1;
    queue<Elve> q;
    q.push(Elve(S,0));
    while(!q.empty()){
        Elve nElve = q.front();
        q.pop();

        if(nElve.state == G){
            res = nElve.cnt;
            break;
        }

        int up = nElve.state + U;
        int down = nElve.state - D;
        if(up <= F){
            if(!ch[up]){
                ch[up] = true;
                q.push(Elve(up,nElve.cnt+1));
            }
        }
        if(down >= 1){
            if(!ch[down]){
                ch[down] = true;
                q.push(Elve(down,nElve.cnt+1));
            }
        }
    }

    if(res == -1) cout << "use the stairs"<<endl;
    else cout << res << endl;

    return 0;
}


