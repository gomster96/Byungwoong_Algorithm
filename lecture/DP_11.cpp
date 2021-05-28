#include<bits/stdc++.h>
using namespace std;

#define instructor

#ifdef mine
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    int n = 0;
    vector<int> a;
    cin >> n;
    int tmp = 0, val = 0;
    
    for(int i=0; i<n; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    cin >> val;
    vector<int> dt(val+1,0);
    for(int i=n-1; i>=0; i--){
        for(int j=a[i]; j<=val; j++){
            if( )
        }
    }
    return 0;
}

#endif
#ifdef instructor
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);

    int n, m;
    cin >> n;
    vector<int> coin(n);
    for(int i=0; i<n; i++) cin>>coin[i];
    cin >> m;
    vector<int> dy(m+1, 1000);
    dy[0] = 0;

    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=m; j++){
            dy[j] = min(dy[j], dy[j]-coin[i]+1);
        }
    }
    cout<<dy[m]<<endl;
    return 0;
}
#endif