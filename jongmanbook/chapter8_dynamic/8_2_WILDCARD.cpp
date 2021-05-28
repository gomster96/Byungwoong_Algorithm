#include<bits/stdc++.h>
using namespace std;

#define mine

#ifdef mine

    // -1은 아직 답이 계산 되지 않았음을 의미함
    // 1은 해당 입력들이 서로 대응됨을 의미함
    // 0은 해당 입력들이 서로 대응되지 않음을 의미함

int cache[101][101];
// 패턴과 문자열
string W, S;
// 와일드카드 패턴 W가 문자열 S에 대응되는지 여부를 반환한다.
bool matchMemorized(int w, int s){
    // 메모이제이션
    int& ret = cache[w][s];
    if(ret != -1) return ret;

    // W[w] 와 S[s]를 맞춰나간다
    while(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])){
        w++;
        s++;
    }
    // 더이상 대응되지 않으면 왜 while문이 끝났는지 확인해야한다.
    // 2. 패턴 끝에 도달해서 끝난경우 : 문자열도 끝나야함
    if(w == W.size()) return ret = (s == S.size());

    if(W[w] == '*'){
        /// *은 모든것을 다 포용할 수 있기 때문에 s를 증가시켜줌
        for(int skip = 0; skip+s <= S.size(); skip++){
            if(matchMemorized(w+1, s+skip)){
                return ret = 1;
            }
        }
    }
    return ret = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("../input.txt","rt",stdin);
    time_t timeStart, timeEnd;
    timeStart = time(NULL);

    


    timeEnd = time(NULL);
    cout << "execute time: "<<(double)(timeEnd - timeStart) << endl;
    
    return 0;
}

#endif
#ifdef instructor
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