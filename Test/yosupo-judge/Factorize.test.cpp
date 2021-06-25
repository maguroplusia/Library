#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../Math/Factorize.cpp"

int main() {
    int Q;
    cin >> Q;
    for(int tmp = 0;tmp < Q;tmp++) {
        long long N;
        cin >> N;
        vector<long long> ret = factorize(N);
        cout << (int)ret.size() << " ";
        for(const auto& x:ret) cout << x << " ";
        cout << endl;
    }
}
