#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../Graph/BellmanFord.cpp"

int main() {
    int N,M,r;
    cin >> N >> M >> r;
    vector<Edge<long long>> es(M);
    for(int i = 0;i < M;i++) {
        int s,t;
        long long d;
        cin >> s >> t >> d;
        es[i] = {s,t,d};
    }
    vector<long long> dist = bellman_ford(N,M,es,r);
    bool isnegative = false;
    for(int i = 0;i < N;i++) {
        if(dist[i] == -numeric_limits<long long>::max()) isnegative = true;
    }
    if(isnegative) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for(int i = 0;i < N;i++) {
        if(dist[i] == numeric_limits<long long>::max()) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}
