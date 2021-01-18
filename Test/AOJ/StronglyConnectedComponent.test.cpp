#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../Graph/StronglyConnectedComponent.cpp"

int main() {
    int N,M;
    cin >> N >> M;
    SCC scc(N);
    for(int i = 0;i < M;i++) {
        int s,t;
        cin >> s >> t;
        scc.add_edge(s,t);
    }
    scc.scc();
    int Q;
    cin >> Q;
    for(int i = 0;i < Q;i++) {
        int u,v;
        cin >> u >> v;
        cout << scc.same(u,v) << endl;
    }
}
