#include<bits/stdc++.h>
using namespace std;

#define instructor

#ifdef mine

struct blo{
    int area, height, weight;
    blo(int a = 0, int b = 0, int c = 0){
        area = a;
        height = b;
        weight = c;
    }
    bool myCheck(const blo& bb) const{
        if(area < bb.area && weight < bb.weight) return true;
        else return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    int n ;
    cin >> n;
    int a, b, c;
    vector<blo> arr(n+1);
    vector<int> dt(n+1);
    for(int i=1; i<=n; i++){
        cin >> a >> b >> c;
        arr[i] = blo(a,b,c);
    }
    int res = 0;
    for(int i=1; i<=n; i++){
        int max = arr[i].height;
        for(int j=i-1; j>=1; j--){
            if(max < (dt[j] + arr[i].height)&& arr[i].myCheck(arr[j])){
                max = dt[j] + arr[i].height;
                //cout<<"max: " << max << " i: " << i << " j: " << j << endl;
            }
        }
        dt[i] = max;
        
        if(dt[i] > res) res = dt[i];
    }


    cout<<res<<endl;
    
    return 0;
}

#endif
#ifdef instructor

struct Brick{
    int s, h, w;
    Brick(int a, int b, int c){
        s = a, h = b, w = c;
    }
    bool operator<(const Brick &b) const{
        return s>b.s;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    int n, a, b, c, max_h = 0, res = 0;
    cin >> n;
    vector<Brick> Bricks;
    vector<int> dy(n, 0);
    for(int i=0; i<n; i++){
        cin>>a>>b>>c;
        Bricks.push_back(Brick(a, b, c));
    }
    sort(Bricks.begin(), Bricks.end());
    dy[0] = Bricks[0].h;
    res = dy[0];

    for(int i=1; i<n; i++){
        max_h = 0;
        for(int j=i-1; j>=0; j--){
            if(Bricks[j].w > Bricks[i].w && dy[j] > max_h){
                max_h = dy[j];
            }
        }
        dy[i] = max_h + Bricks[i].h;
        res = max(res, dy[i]);
    }
    cout << res << endl;
    return 0;
}
#endif