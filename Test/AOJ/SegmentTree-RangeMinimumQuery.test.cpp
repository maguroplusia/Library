#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../DataStructure/SegmentTree.cpp"

int main() {
    int N,Q;
    cin >> N >> Q;
    SegmentTree<int> seg(N,numeric_limits<int>::max(),
    [](int a,int b){return min(a,b);},
    [](int a,int b){return b;});
    for(int i = 0;i < Q;i++) {
        int t;
        cin >> t;
        if(t == 0) {
            int p,x;
            cin >> p >> x;
            seg.set_val(p,x);
        }
        else {
            int s,t;
            cin >> s >> t;
            cout << seg.fold(s,t + 1) << endl;
        }
    }
}
