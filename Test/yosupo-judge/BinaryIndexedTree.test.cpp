#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../DataStructure/BinaryIndexedTree.cpp"

int main() {
    int N,Q;
    cin >> N >> Q;
    vector<ll> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    BinaryIndexedTree<ll> bit(N);
    for(int i = 0;i < N;i++) {
        bit.add(i,vec.at(i));
    }
    for(int i = 0;i < Q;i++) {
        int l,r;
        cin >> l >> r;
        cout << bit.sum(l,r) << endl;
    }
}
