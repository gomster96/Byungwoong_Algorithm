#include<bits/stdc++.h>
using namespace std;

#define instructor

#ifdef mine



int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    int n =0, m = 0, c, b;
    cin >> n >> m;
    vector<pair<int, int> > a;
    for(int i=1; i<=n; i++){
        cin >> c >> b;
        a.push_back(make_pair(c,b));
    }
    vector<int> dt(m+1, 0);
    
    
    int res = -2147000000;
    for(int i=0; i<n; i++){
        for(int j=a[i].second; j<=m; j++){
            if(ch[a[i]][j] != 0){

            }

            dt[j] = max(dt[j], dt[j-a[i].second]+a[i].first);
            if(dt[j] > res) res = dt[j];
            cout << dt[j] << endl;
        }
    }
    cout << res << endl;
    return 0;
}

#endif
#ifdef instructor
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    int n, m, ps, pt;
    cin >> n>> m;
    vector<int> dy(m+1);

    for(int i=0; i<n; i++){
        cin >> ps >> pt;
        for(int j=m; j>=pt; j--){
            dy[j] = max(dy[j], dy[j-pt]+ps);
        }
    }
    cout<< dy[m]<<endl;
    
    return 0;
}
#endif