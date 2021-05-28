#include<bits/stdc++.h>
using namespace std;



int S, N, K, R1, R2, C1, C2;

int checkWhite(int findR, int findC, int r1, int c1, int r2, int c2){
    int gap = (N-K) / 2;
    if(findR >= r1+gap && findR <= r2 - gap && findC >= c1+gap && findC <= c2-gap ){
        return 1;
    }
    else{
        return 0;
    }
}

void solve(int s, int findR, int findC, int r1, int c1, int r2, int c2){
    
    if(s == 1){
        if(checkWhite(findR, findC, r1, c1, r2, c2) == 1) cout << '1';
        else cout << '0';
        return;
    }

    int key = (r2 - r1 +1) / 3;
    
    if(key == 1){
        cout << '0';
        return ;
    }
    int rBlackStart = r1 + key;
    int cBlackStart = c1 + key;
    int rBlackEnd = r2 - key;
    int cBlackEnd = c2 - key;

    if(findR >= rBlackStart && findR<=rBlackEnd && findC >= cBlackStart && findC <= cBlackEnd){
        cout<<'1';
        return;
    }
    else{
        if(findR < rBlackStart){
            if(findC < cBlackStart){
                solve(s-1,findR, findC, r1, c1, rBlackStart-1, cBlackStart-1);
            }
            else if(findC > cBlackEnd){
                solve(s-1,findR, findC, r1, cBlackEnd+1, rBlackStart-1, c2);
            }
            else{   
                solve(s-1, findR, findC, r1, cBlackStart, rBlackStart-1, cBlackEnd);
            }
        }
        else if(findR > rBlackEnd){
            if(findC < cBlackStart){
                solve(s-1,findR, findC, rBlackEnd+1, c1, r2, cBlackStart-1);
            }
            else if(findC > cBlackEnd){
                solve(s-1,findR, findC, rBlackEnd+1, cBlackEnd+1, r2, c2);
            }
            else{   
                solve(s-1,findR, findC, rBlackEnd+1, cBlackStart, r2, cBlackEnd);
            }   
        }
        else{
            if(findC < cBlackStart){
                solve(s-1,findR, findC, rBlackStart, c1, rBlackEnd, cBlackStart-1);
            }
            else if(findC > cBlackEnd){
                solve(s-1,findR, findC, rBlackStart, cBlackEnd+1, rBlackEnd, c2);
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);

    // cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;
    scanf("%d %d %d %d %d %d %d", &S, &N, &K, &R1, &R2, &C1, &C2);
    R1 +=1;
    R2 +=1;
    C1 +=1;
    C2 +=1;
    int length = N * pow(3, S-1);
    if(S == 0){
        cout<<'0';
        return 0;
    }
    for(int i = R1; i<=R2; i++){
        for(int j=C1; j<=C2; j++){
            solve(S, i, j, 1, 1, length, length);
        }
        if(i == R2) break;
        cout << endl;
    }
    
    
    return 0;
}


