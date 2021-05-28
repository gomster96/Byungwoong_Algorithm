#include<bits/stdc++.h>

using namespace std;

int N;
char a[102][102];
bool ch[102][102];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int normalCnt = 0, oddCnt = 0;
void nomalPeople(int r, int c, char color){

    for(int i=0; i<4; i++){
        int rr = r+dy[i];
        int cc = c+dx[i];
        if(a[rr][cc] == color && ch[rr][cc] == false){
            ch[rr][cc] = true;
            nomalPeople(rr, cc, color);
        }
    }
}

void oddPeople(int r, int c, char color){
    if(color == 'B'){
            for(int i=0; i<4; i++){
                int rr = r+dy[i];
                int cc = c+dx[i];
                if(a[rr][cc] == color && ch[rr][cc] == false){
                    ch[rr][cc] = true;
                    oddPeople(rr, cc, color);
            }
        }
    }
    else{
        for(int i=0; i<4; i++){
                int rr = r+dy[i];
                int cc = c+dx[i];
                if((a[rr][cc] == 'R' || a[rr][cc] == 'G') && ch[rr][cc] == false){
                    ch[rr][cc] = true;
                    oddPeople(rr, cc, color);
                }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    // freopen("../input.txt","rt",stdin);
    cin >> N;
    // 이미 처리한 문자는 #으로 바꾸기
    

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> a[i][j];
        }
    }
    memset(ch, false, sizeof(ch));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(ch[i][j] == false){
                ch[i][j] = true;
                nomalPeople(i, j, a[i][j]);
                normalCnt++;
            }
        }
    }
    memset(ch, false, sizeof(ch));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(ch[i][j] == false){
                ch[i][j] = true;
                oddPeople(i, j, a[i][j]);
                oddCnt++;
            }
        }
    }
    cout << normalCnt << " " << oddCnt << '\n';
    return 0;
}


