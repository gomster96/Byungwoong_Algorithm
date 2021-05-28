#include<bits/stdc++.h>
using namespace std;

#define instructor

#ifdef mine

string reverse(string::iterator& it){
    char head = *it;
    ++it;
    if(head == 'b' || head =='w') return string(1,head);

    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight ;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","rt",stdin);
    string str;
    cin >> str;
    string::iterator it = str.begin();
    cout << reverse(it) << endl;
    
    return 0;
}

#endif
#ifdef instructor

string reverse(string::iterator& it){
    /// 이렇게 string 또한 iterator를 사용하여 pointer 를 쓸 수 있음
    char head = *it;
    it++;
    if(head == 'b' || head == 'w') return string(1,head);

    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(){
    ios_base::sync_with_stdio(false);
    string str;
    cin >> str;
    string::iterator it = str.begin();
    cout <<reverse(it) << endl;
    return 0;
}
#endif