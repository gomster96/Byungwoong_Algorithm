#include<bits/stdc++.h>
using namespace std;

#define mine

#ifdef mine

char mp[66][66];
int n = 0;

string findQuadTree( int size, int row, int col){
    
    if(size == 1){
        if(mp[row][col] == '1'){
            return "1";
        }
        else{
            return "0";
        }
    }
    else{
        // cout<<"size: "<<size<<endl;
        //// size/4 가 아니라 size/2 이어야 한다!!
        string a = findQuadTree( size/2, row, col);
        string b = findQuadTree( size/2, row, col+size/2);
        string c = findQuadTree( size/2, row+size/2, col);
        string d = findQuadTree( size/2, row+size/2, col+size/2);
        //// 내가 틀린이유! 여기서 1001 1001 1001 1001 이렇게 4개가 나오면 그냥 1001을 한개 출력하게 만듬
        if(a == b && b == c && c == d && a.size() == 1){
            return a;
        }
        else{
            return "(" + a + b + c + d + ")";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
   
    // freopen("input.txt","rt",stdin);

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> mp[i][j];
        }
    }
    // cout<<n<<endl;
    string res = findQuadTree( n, 1, 1);
    // res = res + ")";
    cout << res << endl;

   
    
    return 0;
}

#endif
