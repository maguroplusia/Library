#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../Graph/Dijkstra.cpp"

int main() {
    cin >> N;
    int M,r;
    cin >> M >> r;
    for(int i = 0;i < M;i++) {
        int s,t;
        ll d;
        cin >> s >> t >> d;
        graph[s].push_back(edge{t,d});
    }
    Dijkstra(r);
    for(int i = 0;i < N;i++) {
        if(d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}
