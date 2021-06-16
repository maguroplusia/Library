#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../Graph/Kruskal.cpp"

int main() {
    cin >> N >> M;
    for(int i = 0;i < M;i++) {
        int s,t;
        ll w;
        cin >> s >> t >> w;
        graph[i] = edge{s,t,w};
    }
    cout << Kruskal() << endl;
}
