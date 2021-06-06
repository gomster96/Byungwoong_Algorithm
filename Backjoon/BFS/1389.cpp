#include<bits/stdc++.h>

using namespace std;

int N, M;
bool ch[101];
bool chVal[101];
vector<int> a[101];
int main(){
    ios_base::sync_with_stdio(false);
    freopen("../input.txt","rt",stdin);
    
    cin >> N >>M;
    int ta, tb;
    for(int i=1; i<=M; i++){
        cin >> ta >> tb;
        a[ta].push_back(tb);
        a[tb].push_back(ta);
    }
    int res = 0;
    int resSum = 2147000000;
    for(int i=1; i<=N; i++){
        memset(ch, false, sizeof(ch));
        memset(chVal, false, sizeof(chVal));
        queue<pair<int, int> >q;
        ch[i] = true;
        q.push(make_pair(i, 0));
        int sum = 0;
        while(!q.empty()){
            int ret = q.front().first;
            int val = q.front().second;
            if(!chVal[ret]){
                chVal[ret] = true;
                sum += val;
            }
            q.pop();
            if(!ch[ret]) continue;
            
            for(int i=0; i<a[ret].size(); i++){
                
                if(!ch[a[ret][i]]){
                    ch[a[ret][i]] = true;
                    q.push(make_pair(a[ret][i], val+1));
                    
                }
            }
        }
        if(sum < resSum){
            res = i;
            resSum = sum;
        }
    }
    
    // cout << res << endl;

    return 0;
}


