#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../Graph/BellmanFord.cpp"

int main() {
    cin >> N >> M;
    int r;
    cin >> r;
    for(int i = 0;i < M;i++) {
        int s,t;
        ll d;
        cin >> s >> t >> d;
        es[i] = (edge{s,t,d});
    }
    Bellmanford(r);
    bool isnegative = false;
    for(int i = 0;i < N;i++) {
        if(d[i] == -INF) isnegative = true;
    }
    if(isnegative) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for(int i = 0;i < N;i++) {
        if(d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}
