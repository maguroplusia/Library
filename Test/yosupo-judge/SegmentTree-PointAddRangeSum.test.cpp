#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../DataStructure/SegmentTree.cpp"

int main() {
    int N,Q;
    cin >> N >> Q;
    vector<long long> vec(N);
    for(auto& x : vec) cin >> x;
    SegmentTree<long long> seg(vec,(long long)0,
    [](long long a,long long b){return a + b;},
    [](long long a,long long b){return a + b;});
    for(int i = 0;i < Q;i++) {
        int t;
        cin >> t;
        if(t == 0) {
            int p;
            long long x;
            cin >> p >> x;
            seg.set_val(p,x);
        }
        else {
            int l,r;
            cin >> l >> r;
            cout << seg.fold(l,r) << endl;
        }
    }
}
