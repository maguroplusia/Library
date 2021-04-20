#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../DataStructure/LazySegmentTree.cpp"

int main() {
    int N,Q;
    cin >> N >> Q;
    LazySegmentTree<int,int> seg(N,numeric_limits<int>::max(),-1,
                        [](int a,int b){return min(a,b);},
                        [](int a,int b){return b;},
                        [](int a,int b){return b;});
    for(int i = 0;i < Q;i++) {
        int type;
        cin >> type;
        if(type == 0) {
            int s,t,x;
            cin >> s >> t >> x;
            seg.update(s,t + 1,x);
        }
        else {
            int s,t;
            cin >> s >> t;
            cout << seg.query(s,t + 1) << endl;
        }
    }
}
