#include<bits/stdc++.h>
using namesapce std;

#include"../../Other/Template.cpp"
#include"../../Datastructure/SegmentTree.cpp"

int main() {
    int N,Q;
    cin >> N >> Q;
    SegmentTree<ll> seg(N,0,
    [](ll a,ll b){return a + b;},
    [](ll a,ll b){return a + b;});
    for(int i = 0;i < N;i++) {
        ll A;
        cin >> A;
        seg.set(A);
    }
    seg.build();
    for(int i = 0;i < Q;i++) {
        int t;
        cin >> t;
        if(t == 0) {
            int p;
            ll x;
            seg.update(p,x);
        }
        else {
            int l,r;
            cin >> l >> r;
            cout << seg.query(l,r) << endl;
        }
    }
}
