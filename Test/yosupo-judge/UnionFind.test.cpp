#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include<bits/stdc++.h>
using namespace std;

#include"../../DataStructure/UnionFind.cpp"

int main() {
    int N,Q;
    cin >> N >> Q;
    UnionFind uf(N);
    for(int i = 0;i < Q;i++) {
        int t,a,b;
        cin >> t >> a >> b;
        if(t == 0) {
            uf.unite(a,b);
        }
        else {
            cout << uf.same(a,b) << endl;
        }
    }
}
