#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define more_use

#ifdef use_map
#include<map>
// map 은 주로 알파벳이나 문자열 count할때 사용함

int main(){
    freopen("input.txt","rt",stdin);
    map<char, int> ch;
    map<char, int> ::iterator it; ///// map을 접근하기 위한 반복자를 선언하는것 /// 약간 포인터으 ㅣ느낌
    char a[100];
    cin >> a;
    for(int i=0; a[i]!='\0'; i++){
        ch[a[i]]++;
        ///// 이러면 key값은 a[i], value값은 int형
    }
    ///// map 자료구조에 반복문을 사용하는 것
    for(it=ch.begin(); it!=ch.end(); it++){
        cout << it->first<< ' ' << it->second << "\n"; //// \n이게 줄바꿈이 더 빠름
        //// it를 pointer와 같이 생각하여야 하기 때문에 -> 이걸 사용
    }
    return 0;
}

#endif

#ifdef more_use

#include<map>
#include<string>
int main(){
    freopen("input.txt","rt",stdin);
    map<string, int> ch;
    map<string, int>::iterator it;
    char a[100];
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >>a;
        ch[a]++;  /// 이러면 a에들어간 단어가 key가 되고 그 value가 개수가 됨
    }
    for(it = ch.begin(); it != ch.end(); it++){
        cout << it->first << ' ' << it->second << "\n";
    }
    return 0;
}
#endif