#include<bits/stdc++.h>
using namespace std;

#define mine2

#ifdef mine

int check(vector<int> v){
    int flag = 1;
    for(int i=0; i<16; i++){
        if(v[i] != 12){
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    time_t timeStart, timeEnd;
    timeStart = time(NULL);

    int c = 0, tmp = 0;
    int n = 16;

    vector<int> swch[10];
    swch[0].push_back(0);
    swch[0].push_back(1);
    swch[0].push_back(2);
    swch[1].push_back(3);
    swch[1].push_back(7);
    swch[1].push_back(9);
    swch[1].push_back(11);
    swch[2].push_back(4);
    swch[2].push_back(10);
    swch[2].push_back(14);
    swch[2].push_back(15);
    swch[3].push_back(0);
    swch[3].push_back(4);
    swch[3].push_back(5);
    swch[3].push_back(6);
    swch[3].push_back(7);
    swch[4].push_back(6);
    swch[4].push_back(7);
    swch[4].push_back(8);
    swch[4].push_back(10);
    swch[4].push_back(12);
    swch[5].push_back(0);
    swch[5].push_back(2);
    swch[5].push_back(14);
    swch[5].push_back(15);
    swch[6].push_back(3);
    swch[6].push_back(14);
    swch[6].push_back(15);
    swch[7].push_back(4);
    swch[7].push_back(5);
    swch[7].push_back(7);
    swch[7].push_back(14);
    swch[7].push_back(15);
    swch[8].push_back(1);
    swch[8].push_back(2);
    swch[8].push_back(3);
    swch[8].push_back(4);
    swch[8].push_back(5);
    swch[9].push_back(3);
    swch[9].push_back(4);
    swch[9].push_back(5);
    swch[9].push_back(9);
    swch[9].push_back(13);
    
    
    
    cin >> c;
    for(int k=0; k<c; k++){
        queue<vector<int> > q;
        queue<int> cnt; 
        queue<vector<int> >swchCnt;

        vector<int> clk;
        vector<int> tmpCnt(10, 0);
        for(int i=0; i<n; i++){
            cin >> tmp;
            clk.push_back(tmp);
        }
        
        q.push(clk);
        cnt.push(0);
        swchCnt.push(tmpCnt);
        while(!q.empty()){
            
            vector<int> t = q.front();
            q.pop();
            int L = cnt.front();
            cnt.pop();
            vector<int> tc = swchCnt.front();
            swchCnt.pop();
            // cout<<"L: "<<L<<endl;
            if(check(t)){
                cout<<L<<endl;
                break;
            }
            
            for(int i=0; i<10; i++){
                if(tc[i] < 4){
                    for(int j=0; j<swch[i].size(); j++){
                        t[swch[i][j]]+=3;
                        if(t[swch[i][j]] == 15) t[swch[i][j]] = 3;
                    } 
                    tc[i]++;   
                    q.push(t);
                    cnt.push(L+1);    
                    swchCnt.push(tc);
                }
                
            }
        }

    }
    

    timeEnd = time(NULL);
    cout << "execute time: "<<(double)(timeEnd - timeStart) << endl;
    
    return 0;
}
#endif
#ifdef mine2

int ch[11];
vector<int> clk;
int res = 2147000000;
vector<int> swch[10];


int check(vector<int> v){
    int flag = 1;
    for(int i=0; i<16; i++){
        if(v[i] != 12){
            flag = 0;
            break;
        }
    }
    return flag;
}


int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    time_t timeStart, timeEnd;
    timeStart = time(NULL);

    int c = 0, tmp = 0;
    int n = 16;

    
    swch[0].push_back(0);
    swch[0].push_back(1);
    swch[0].push_back(2);
    swch[1].push_back(3);
    swch[1].push_back(7);
    swch[1].push_back(9);
    swch[1].push_back(11);
    swch[2].push_back(4);
    swch[2].push_back(10);
    swch[2].push_back(14);
    swch[2].push_back(15);
    swch[3].push_back(0);
    swch[3].push_back(4);
    swch[3].push_back(5);
    swch[3].push_back(6);
    swch[3].push_back(7);
    swch[4].push_back(6);
    swch[4].push_back(7);
    swch[4].push_back(8);
    swch[4].push_back(10);
    swch[4].push_back(12);
    swch[5].push_back(0);
    swch[5].push_back(2);
    swch[5].push_back(14);
    swch[5].push_back(15);
    swch[6].push_back(3);
    swch[6].push_back(14);
    swch[6].push_back(15);
    swch[7].push_back(4);
    swch[7].push_back(5);
    swch[7].push_back(7);
    swch[7].push_back(14);
    swch[7].push_back(15);
    swch[8].push_back(1);
    swch[8].push_back(2);
    swch[8].push_back(3);
    swch[8].push_back(4);
    swch[8].push_back(5);
    swch[9].push_back(3);
    swch[9].push_back(4);
    swch[9].push_back(5);
    swch[9].push_back(9);
    swch[9].push_back(13);
    
    
    
    cin >> c;
    for(int k=0; k<c; k++){
        memset(ch, 0, sizeof(ch));
        int tmp;
        for(int i=0; i<16; i++){
            cin >> tmp;
            clk.push_back(tmp);
        }
        
        DFS(0);
        cout<<res<<endl;
        res = 2147000000;
        for(int i=0; i<16; i++){
            clk.pop_back();
        }
    }
    

    timeEnd = time(NULL);
    cout << "execute time: "<<(double)(timeEnd - timeStart) << endl;
    
    return 0;
}

#endif
#ifdef instructor

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS+1]{
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

bool areAligned(const vector<int>& clocks);

void push(vector<int>&clocks, int swtch){
    for(int clock =0; clock<CLOCKS; clock++){
        if(linked[swtch][clock] == 'x'){
            clocks[clock] += 3;
            if(clocks[clock] == 15) clocks[clock] = 3;
        }
    }
}

int solve(vector<int>& clocks, int swtch){
    if(swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
    int ret = INF;
    for(int cnt = 0; cnt<4; cnt++){
        ret = min(ret, cnt+solve(clocks, swtch+1));
        push(clocks, swtch);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    time_t timeStart, timeEnd;
    timeStart = time(NULL);

    timeEnd = time(NULL);
    cout << "execute time: "<<(double)(timeEnd - timeStart) << endl;
    return 0;
}
#endif