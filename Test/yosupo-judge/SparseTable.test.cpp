#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include<bits/stdc++.h>
using namesapce std;

#include"../../DataStructure/SparseTable.cpp"

int main() {
    int N,Q;
    cin >> N >> Q;
    vector<int> vec(N)
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    SparseTable st(vec);
    for(int i = 0;i < Q;i++) {
        int l,r;
        cin >> l >> r;
        cout << st.query(l,r) << endl;
    }
}
