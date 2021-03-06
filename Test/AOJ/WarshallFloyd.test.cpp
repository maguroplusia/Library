#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../Graph/WarshallFloyd.cpp"

int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<long long>> dist(N,vector<long long>(N,INF));
    for(int i = 0;i < N;i++) dist[i][i] = 0;
    for(int i = 0;i < M;i++) {
        int s,t;
        long long d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }
    dist = WarshallFloyd(N,dist);
    bool isnegative = false;
    for(int i = 0;i < N;i++) {
        if(dist[i][i] < 0) isnegative = true;
    }
    if(isnegative) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            if(dist[i][j] == INF) cout << "INF";
            else cout << dist[i][j];
            if(j != N - 1) cout << " ";
        }
        cout << endl;
    }
}
