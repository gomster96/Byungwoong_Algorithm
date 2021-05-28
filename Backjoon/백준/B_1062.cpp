#include<bits/stdc++.h>
using namespace std;

#define other

#ifdef mine
int c = 0, k = 0;
int ch[27];
int word[51][27];
int wordCh[51];
int res = -2147000000;

void DFS(int cur, int rK){
    if(rK < 0) return;
    
    int next = -1;
    for(int i=0; i<c; i++){
        if(wordCh == 0) next = i;
    }
    int tmprK = rK;
    wordCh[next] = 1;

    for(int i=0; ch[i] != '\0'; i++){
        if(ch[i] == word[next][i]) continue;
        else if(word[next][i] == 1){
            ch[i]++;
            tmprK--;
        } 
    }
    if(tmprK < 0){

    }

}


int main(){
    ios_base::sync_with_stdio(false);
    // freopen("input.txt","rt",stdin);
    time_t timeStart, timeEnd;
    timeStart = time(NULL);
    cin >> c >> k;
    for(int l=0; l<c; l++){
        string s;
        cin >> s;
        int cnt = 0;
        for(int i=0; s[i]!='\0'; i++){
            
            if(word[l][s[i]-96] == 0){
                word[l][s[i]-96] = 1;
                cnt++;
            }
            word[l][0] = cnt;
        }
    }
    for(int i=0; i<c; i++){
        if(word[i][0] > k) continue;
        int cnt = 0;
        int key = k-word[i][0];
        for(int j=0; j<c; j++){
            if(i == j) continue;
            
        }
    }
    
    for(int i=0; i<c; i++){
        wordCh[i] = 1;
        memset(ch, 0, sizeof(ch));
        for(int j=0; word[i][j]!='\0'; j++){
            ch[j] = word[i][j];
        }
        DFS(i, k-ch[0]);
        wordCh[i] = 0;
    }

    timeEnd = time(NULL);
    cout << "execute time: "<<(double)(timeEnd - timeStart) << endl;
    
    return 0;
}

#endif
#ifdef other

int N, K, ans, CNT;

int num[50];
set<int> base;

bool arr[50][26];
bool choice[26];

void DFS(int idx, int number){
    if(number == CNT){
        int Can = 0;
        for(int i=0; i<N; i++){
            int tt = 0;
            for(int j=0; j<26; j++){
                if(choice[j] && arr[i][j]) tt++;
            }
            if(tt>=num[i]) Can++;
        }
        ans = max(Can, ans);
        return;
    }
    if(idx >= 26) return;

    DFS(idx+1, number);
    if(base.count(idx)) return; 
    choice[idx] = true;
    DFS(idx+1, number+1);
    choice[idx] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    cin >> N >> K;
    base.insert('a' - 'a');
    base.insert('n'-'a');
    base.insert('t'-'a');
    base.insert('i'-'a');
    base.insert('c'-'a');
    for(int i=0; i<N; i++){
        string A;
        cin>> A;
        for(auto curr: A)
            if(!base.count(curr-'a'))
                arr[i][curr-'a'] = true;
    }
    for(int i=0; i<N; i++){
        int ccc = 0;
        for(int j=0; j<26; j++){
            if(arr[i][j]) ccc++;
        }
        num[i] = ccc;
    }
    CNT = K-5;
    if(CNT < 0) cout<<0<<endl;
    else{
        DFS(0,0);
        cout << ans << endl;
    }
    return 0;
}
#endif