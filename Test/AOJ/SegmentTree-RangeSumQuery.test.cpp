#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../DataStructure/SegmentTree.cpp"

int main() {
    int N,Q;
    cin >> N >> Q;
    SegmentTree<int> seg(N,0,
    [](int a,int b){return a + b;},
    [](int a,int b){return a + b;});
    for(int i = 0;i < Q;i++) {
        int t;
        cin >> t;
        if(t == 0) {
            int p,x;
            cin >> p >> x;
            p--;
            seg.set_val(p,x);
        }
        else {
            int s,t;
            cin >> s >> t;
            s--;
            t--;
            cout << seg.fold(s,t + 1) << endl;
        }
    }
}
