#include<bits/stdc++.h>
using namespace std;

#define instructor

#ifdef mine
vector<pair<int, int> > a;
int n, m;
int res = 0;
void DFS(int sumWeight, int sumValue){

    for(int i=0; i<n; i++){
        if((sumWeight+a[i].first) > m){
            if(sumValue > res){
                res = sumValue;
                // cout<<"res: "<<res<<endl;
                // cout<<"weight: "<<sumWeight<<endl;
            }
        }
        else{
            sumWeight = sumWeight+a[i].first;
            sumValue = sumValue + a[i].second;
            DFS( sumWeight, sumValue);
            sumWeight = sumWeight - a[i].first;
            sumValue = sumValue - a[i].second;
        }
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    int b, c;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> b >> c;
        a.push_back(make_pair(b,c));
    }   
    DFS( 0, 0);
    cout<<res<<endl;
    return 0;
}

#endif
#ifdef instructor
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    int n, m, w, v;
    cin >> n>> m;
    vector<int> dy(m+1, 0);
    for(int i=0; i<n; i++){
        cin >> w >> v;
        for(int j=w; j<=m; j++){
            dy[j] = max(dy[j], dy[j-w]+v); ///// 이게 핵심 코드 
        }
    }
    cout << dy[m] << endl;;
    return 0;
}
#endif