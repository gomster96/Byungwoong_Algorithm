#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define instructor

#ifdef mine

struct schedule{
    int money, day;
    schedule(int a, int b){
        money = a;
        day = b;
    }
    bool operator<(const schedule& t) const{
        if(day!=t.day) return day < t.day;
        else return money < t.money;
    }
};

int main(){
    freopen("input.txt","rt",stdin);
    int n = 0, m = 0, D = 0;
    scanf("%d",&n);
    
    priority_queue<schedule> pQ;
    for(int i=1; i<=n; i++){
        scanf("%d %d",&m, &D);
        pQ.push(schedule(m,D));
    }
    int sum = 0;
    
    
    
    while(!pQ.empty()){

        schedule key = pQ.top();
        sum += key.money;
        pQ.pop();
        while(key.day >= pQ.top().day){
            pQ.top().day = key.day-1;
        }
        
    }

    return 0;
}

#endif

#ifdef instructor

struct Data{
    int money;
    int when;
    Data(int a, int b){
        money = a;
        when = b;
    }
    bool operator<(Data &b){
        return when>b.when;
    }
};

int main(){
    freopen("input.txt","rt",stdin);

    int n, i, j, a, b, res=0, max=-2147000000;
    vector<Data> T;
    priority_queue<int> pQ;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d %d",&a, &b);
        T.push_back(Data(a,b));
        if(b>max){
            max = b;
        }
    }
    sort(T.begin(), T.end());
    j = 0;
    for(i=max; i>=1; i--){
        for( ; j<n; j++){
            if(T[j].when<i) break;
            pQ.push(T[j].money);;
        }
        if(!pQ.empty()){
            res+=pQ.top();
            pQ.pop();
        }
    }
    return 0;
}
#endif