#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../DataStructure/SlidingWindowAggregation.cpp"

constexpr long long MOD = 998244353;

using S = pair<long long,long long>;

S op(S A,S B) {
    return {A.first * B.first % MOD,(B.first * A.second + B.second) % MOD};
}

int main() {
    int Q;
    cin >> Q;
    SWAG<S> swag(op);
    for(int i = 0;i < Q;i++) {
        int q;
        cin >> q;
        if(q == 0) {
            long long a,b;
            cin >> a >> b;
            swag.push({a,b});
        }
        else if(q == 1) {
            swag.pop();
        }
        else {
            long long x;
            cin >> x;
            if(swag.empty()) cout << x << endl;
            else {
                S res = swag.fold_all();
                cout << (res.first * x + res.second) % MOD << endl;
            }
        }
    }
}