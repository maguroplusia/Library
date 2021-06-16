#define PROBLEM "https://yukicoder.me/problems/447"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../Mathematics/ChineseRemainderTheorem.cpp"

int main() {
    long long X1,Y1,X2,Y2,X3,Y3;
    cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
    pair<long long,long long> ret = CRT({X1,X2,X3},{Y1,Y2,Y3});
    if(ret.second == -1) cout << -1 << endl;
    else {
        if(ret.first == 0) cout << ret.second << endl;
        else cout << ret.first << endl;
    }
}
