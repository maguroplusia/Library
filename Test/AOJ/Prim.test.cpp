#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A&lang=jp"

#include<bits/stdc++.h>
using namespace std;

#include"../../Other/Template.cpp"
#include"../../Graph/Prim.cpp"

int main() {
    cin >> N;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            cin >> cost[i][j];
            if(cost[i][j] == -1) cost[i][j] = INF;
        }
    }
    cout << prim() << endl;
}
