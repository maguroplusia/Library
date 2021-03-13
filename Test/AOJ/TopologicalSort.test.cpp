#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../Graph/TopologicalSort.cpp"

int main() {
    cin >> N;
    int M;
    cin >> M;
    for(int i = 0;i < M;i++) {
        int s,t;
        cin >> s >> t;
        graph[s].push_back(t);
    }
    vector<int> ret = topological_sort();
    for(int i = 0;i < N;i++) {
        cout << ret.at(i) << endl;
    }
}
