// 코딩을 처음에 너무 어렵게 생각하여 말려버린 문제 

#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<int> a[10001];
bool ch[10001] = {false,};
vector<int> ans;
int cnt;

void DFS(int v){
    for(int i=0; i<a[v].size(); i++){
        if(!ch[a[v][i]]){
            ch[a[v][i]] = true;
            cnt++;
            DFS(a[v][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    // freopen("../input.txt","rt",stdin);
    

    cin >> N >> M;
    int ta, tb;
    
    for(int i=1; i<=M; i++){
        cin >> ta >> tb;
        a[tb].push_back(ta);
    }
    int resCnt = -1;
    for(int i=1; i<=N; i++){
        if(a[i].size()!= 0){
            memset(ch, false, sizeof(ch));
            cnt = 0;  
            /// 이거 넣는것도 실수  
            ch[i] = true;
            DFS(i);
            // 요것도 생각은 했는데 이런방법으로 구현 x
            if(resCnt < cnt){
                
                resCnt = cnt;
                ans.clear();
                ans.push_back(i);
            }
            else if(resCnt == cnt) ans.push_back(i);
            
        }
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}





// #include<bits/stdc++.h>

// using namespace std;

// int N, M;
// vector<int> a[10001];
// int ch[10001] ;
// bool cch[10001] = {false,};
// vector<pair<int, int> >ans;

// int DFS(int v){
//     int& ret = ch[v];
//     if(ret != -1) return ret;
//     ret = 1;
//     for(int i=0; i<a[v].size(); i++){
//         cch[a[v][i]] = true;
//         ret = ret + DFS(a[v][i]);
//         cch[a[v][i]] = false;
//     }

//     return ret;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     freopen("../input.txt","rt",stdin);
    
    // cin >> N >> M;
    // int ta, tb;
    // memset(ch, -1, sizeof(ch));
    // for(int i=1; i<=M; i++){
    //     cin >> ta >> tb;
    //     a[tb].push_back(ta);
    // }
    // for(int i=1; i<=N; i++){
    //     if(a[i].size()!= 0){
            
    //         ans.push_back(make_pair(-DFS(i), i));

    //     }
    // }
//     sort(ans.begin(), ans.end());
//     int m = 2147000000;

//     for(int i=0; i<ans.size(); i++){
//         if(m < ans[i].first) break;
//         else cout<< ans[i].second <<" ";
//         // else cout<<ans[i].first<<" "<< ans[i].second <<endl;
//         m = ans[i].first;    
//     }
//     cout<<"\n";
//     return 0;
// }


