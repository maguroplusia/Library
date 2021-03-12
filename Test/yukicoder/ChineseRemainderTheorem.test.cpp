#define PROBLEM "https://yukicoder.me/problems/447"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../Mathematics/ChineseRemainderTheorem.cpp"

int main() {
    ll X1,Y1,X2,Y2,X3,Y3;
    cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
    pair<ll,ll> ret = CRT({X1,X2,X3},{Y1,Y2,Y3});
    if(ret.second == -1) cout << -1 << endl;
    else cout << ret.first << endl;
}
