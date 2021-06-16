#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../DataStructure/SegmentTree.cpp"

int main() {
    int N,Q;
    cin >> N >> Q;
    SegmentTree<long long> seg(N,(long long)0,
    [](long long a,long long b){return a + b;},
    [](long long a,long long b){return a + b;});
    for(int i = 0;i < N;i++) {
        long long A;
        cin >> A;
        seg.set(i,A);
    }
    seg.build();
    for(int i = 0;i < Q;i++) {
        int t;
        cin >> t;
        if(t == 0) {
            int p;
            long long x;
            cin >> p >> x;
            seg.update(p,x);
        }
        else {
            int l,r;
            cin >> l >> r;
            cout << seg.query(l,r) << endl;
        }
    }
}
