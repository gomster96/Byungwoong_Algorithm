#include<bits/stdc++.h>
using namespace std;

#define instructor

#ifdef mine

int cache[10001];
string s;

int getDifficulty(int start){
    if(cache[start] != -1) return cache[start];
    int& ret = cache[start];

    //// start가 배열의 범위를 넘어설 경우 체크...
    int firstNum, secondNum, thirdNum, fourthNum, fifthNum;
    int length = s.length();
    if(start >= length || start+1 >= length || start+2 >= length) return -100000;
    firstNum = s[start] - '0';
    secondNum = s[start+1] - '0';
    thirdNum = s[start+2] - '0';
    if(start+3 >= length) fourthNum = -20;
    else fourthNum = s[start+3] - '0';
    
    if(start+4 >= length) fifthNum = -20;
    else fourthNum = s[start+4] - '0';

    if(firstNum == secondNum && secondNum == thirdNum){
        
        if(thirdNum == fourthNum) {
            ret = max(ret, getDifficulty(start+4));
            if(fourthNum == fifthNum) ret = max(ret, getDifficulty(start+5));
        }
        ret = max(ret, getDifficulty(start+3));
    }
    else if(firstNum == thirdNum){
        if(secondNum == fourthNum){
            ret = max(ret, getDifficulty(start+4));
            if(thirdNum == fifthNum){
                ret = max(ret, getDifficulty(start+5));
            }
        }
        ret = max(ret, getDifficulty(start+3));
    }
    else if(abs(secondNum-firstNum) == 1){
        int dif = secondNum-firstNum;
        if(fourthNum - thirdNum == dif){
            ret = max(ret, getDifficulty(start+4));
            if(fifthNum - fourthNum == dif){
                ret = max(ret, getDifficulty(start+5));
            }
        }
        ret = max(ret, getDifficulty(start+3));
    }
    else if(abs(thirdNum - secondNum) == abs(secondNum - firstNum)){
        int dif = secondNum-firstNum;
        if(fourthNum - thirdNum == dif){
            ret = max(ret, getDifficulty(start+4));
            if(fifthNum - fourthNum == dif){
                ret = max(ret, getDifficulty(start+5));
            }
        }
        ret = max(ret, getDifficulty(start+3));
    }
    else{
        ret = max(ret, getDifficulty(start+3));
        if(di)
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    freopen("../input.txt","rt",stdin);
    time_t timeStart, timeEnd;
    timeStart = time(NULL);

    int c = 0;
    cin >> c;
    for(int i=0; i<c; i++){
        
        cin >> s;
        memset(cache, -1, sizeof(cache));

    }

    timeEnd = time(NULL);
    cout << "execute time: "<<(double)(timeEnd - timeStart) << endl;
    
    return 0;
}

#endif
#ifdef instructor

const int INF = 987654321;
string N;

int classify(int a, int b){
    // 숫자 조각을 가져ㅕ온다.
    string M = N.substr(a, b-a+1);

    // 첫 글자만으로 이루어진 문자열과 같으면 난이도는 1
    if(M == string(M.size(), M[0])) return 1;
    // 등차수열인지 검사한다.
    bool progressive = true;
    for(int i=0; i<M.size()-1; i++){
        if(M[i+1] - M[i] != M[1] - M[0]){
            progressive = false;
        }
    }
    // 등차수열이고 공차가 1 혹은 -1이면 난이도는 2
    if(progressive && abs(M[1]-M[0]) == 1) return 2;

    // 두 수가 번갈아 등장하는지 확인한다.
    bool alternating = true;

    for(int i=0; i<M.size(); i++){
        if(M[i] != M[i%2]) alternating = false;
    }
    if(alternating) return 4;
    if(progressive) return 5;
    return 10;
}
int cache[10002];
int memorize(int begin){
    // 기저사례: 수열의 끝에 도달했을 경우
    if(begin == N.size()) return 0;
    // 메모이제이션
    int&ret = cache[begin];
    if(ret != -1) return ret;

    ret = INF;
    //// 한쪽에서 한번에 ret을 계산하는것이 값이 꼬이는 것을 없앨 수 있음
    for(int L = 3; L<=5; L++){
        if(begin+L <= N.size()) ret = min(ret, memorize(begin+L) + classify(begin, begin + L -1));
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