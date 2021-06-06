#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a[501];
bool ch[501];


int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);

    cin >> n >> m;
    int ta, tb;
    for(int i=1; i<=m; i++){
        cin >> ta >> tb;
        a[ta].push_back(tb);
        a[tb].push_back(ta);
    }

    queue<pair<int, int> > q;
    ch[1] = true;
    q.push(make_pair(1,0));
    int cnt = 0;
    while(!q.empty()){
        int ret = q.front().first;
        int val = q.front().second;
        q.pop();   
        if(val == 2) continue;
        for(int i=0; i<a[ret].size(); i++){
            if(!ch[a[ret][i]]){
               ch[a[ret][i]] = true; 
               cnt++;
               q.push(make_pair(a[ret][i], val+1));
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}


