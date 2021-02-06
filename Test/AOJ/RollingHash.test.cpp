#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../String/RollingHash.cpp"

int main() {
    string T,P;
    cin >> T >> P;
    if(T.size() < P.size()) return 0;
    RollingHash rh;
    vector<uint64_t> t = rh.build(T);
    vector<uint64_t> p = rh.build(P);
    uint64_t cnt = rh.query(p,0,P.size());
    for(int i = 0;i < T.size() - P.size() + 1;i++) {
        if(rh.query(t,i,i + P.size()) == cnt) cout << i << endl;
    }
}
