#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../Graph/Dijkstra.cpp"

int main() {
    int N,M,r;
    cin >> N >> M >> r;
    vector<vector<edge>> graph(N);
    for(int i = 0;i < M;i++) {
        int s,t;
        long long d;
        cin >> s >> t >> d;
        graph[s].push_back({t,d});
    }
    vector<long long> dist = Dijkstra(N,graph,r);
    for(int i = 0;i < N;i++) {
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}
