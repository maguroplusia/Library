#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../Graph/LowestCommonAncestor.cpp"

int main() {
    cin >> N;
    int Q;
    cin >> Q;
    for(int i = 0;i < N - 1;i++) {
        int p;
        cin >> p;
        graph[i + 1].push_back(p);
        graph[p].push_back(i + 1);
    }
    init(N);
    for(int i = 0;i < Q;i++) {
        int u,v;
        cin >> u >> v;
        cout << LCA(u,v) << endl;
    }
}
