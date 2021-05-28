#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define instructor

#ifdef mine
int n = 0, m = 0;

struct pizDis{
    int dis;
    pair<int, int> pizLoc;
    pizDis(int a, int b, int c){
        dis = a;
        pizLoc = make_pair(b,c);
    }
    bool operator< (const pizDis& k) const{
        return dis>k.dis;
    }
};

int main(){
    freopen("input.txt","rt",stdin);
    scanf("%d %d",&n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]==2){
                pizzaCount++;
            }
            else if(map[i][j]==1){
                homeCount++;
            }
        }
    }
    return 0;
}

#endif

#ifdef instructor

vector<pair<int, int> > pz;
vector<pair<int, int> > hs;
int ch[20], m, res=2147000000, dis, sum = 0;
void DFS(int L, int s){
    if(L==m){
        sum=0;
        for(int i=0; i<hs.size(); i++){
            int x1 = hs[i].first;
            int y1 = hs[i].second;
            dis = 2147000000;
            for(int j=0; j<m; j++){
                int x2 = pz[ch[j]].first;
                int y2 = pz[ch[j]].second;
                dis = min(dis, abs(x1-x2)+abs(y1-y2));
            }
            sum=sum+dis;
        }
        if(sum<res) res=sum;
    }
    else{
        ///// 조합으로 비교할 피자가게를 선정 그중 최고인 것을 답으로 만들기 
        for(int i=s; i<pz.size(); i++){
            ch[L] = i;
            DFS(L+1, i+1);
        }
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    int n, a;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a;
            if(a==1) hs.push_back(make_pair(i,j));
            else if(a==2) pz.push_back(make_pair(i,j));
        }
    }
    DFS(0,0);
    cout<<res;


    return 0;
}
#endif