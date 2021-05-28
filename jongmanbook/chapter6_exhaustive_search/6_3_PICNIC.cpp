#include<bits/stdc++.h>
using namespace std;

#define instructor

#ifdef mine

int cnt = 0;
int ch[11];
int n = 0, c= 0, m = 0;

void DFS(vector<int> *v, int cc){
    if(cc == n/2){
        cnt++;
    }
    else{
        for(int i=0; i<n; i++){
            if(ch[i] == 1) continue;
            for(int j=0; j<v[i].size(); j++){
                if(ch[i] == 0 && ch[j] == 0){
                    ch[i] = ch[j] = 1;
                    DFS(v, cc+1);
                    ch[i] = ch[j] = 0;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);

    
    cin >> c;
    for(int k = 0; k<c; k++){
        cin >> n >> m;
        vector<int> a[11];
        int t1, t2;
        
        fill_n(ch, 11, 0);
        
        for(int i=0; i<m; i++){
            cin >> t1 >> t2;
            a[t1].push_back(t2);
        }
        DFS(a, 0);
        cout<<cnt<<endl;
        cnt = 0;
        
    }

    return 0;
}

#endif

#ifdef instructor

int n;
bool areFriends[10][10];

int countPairings(bool taken[10]){
    int firstFree = -1;
    for(int i=0; i<n; i++){
        if(!taken[i]){
            firstFree = i;
            break;
        }
    }
    if(firstFree == -1) return 1;
    int ret = 0;
    for(int pairWith = firstFree+1; pairWith<n; pairWith++){
        if(!taken[pairWith] && areFriends[firstFree][pairWith]){
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    ///// 중요한 부분! 만약 친구가 없을 경우..!
    return ret;
}

// int countPairings(bool taken[10]){
//     int firstFree = -1;
//     for(int i=0; i<n; i++){
//         if(!taken[i]){
//             firstFree = i;
//             break;
//         }
//     }

//     if(firstFree == -1) return 1;
//     int ret = 0;

//     for(int pairWith = firstFree+1; pairWith < n; pairWith++){
//         if(!taken[pairWith] && areFriends[firstFree][pairWith]){
//             taken[firstFree] = taken[pairWith] = true;
//             cout<<"firstFree : " << firstFree << " pairWith : " << pairWith<<endl;
//             ret += countPairings(taken);
//             taken[firstFree] = taken[pairWith] = false;
//         }
//     }
//     return ret;
// }


int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);

    int c, m;
    
    cin >> c;
    for(int k = 0; k<c; k++){
        cin >> n >> m;
        
        int t1, t2;
        bool taken[11];
        
        fill_n(taken, 11, false);
        for(int i =0; i<m; i++){
            cin >> t1 >> t2;
            areFriends[t1][t2] = true;
            areFriends[t2][t1] = true;
        }
        cout<<countPairings(taken) << endl;
        
        memset(areFriends, false, sizeof(areFriends));
        
    }

    return 0;
}

#endif