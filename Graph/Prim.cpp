#include<bits/stdc++.h>
template<typename T>
struct Edge {
    int to;
    T cost;
};

template<typename T>
long long prim(int n, int m, std::vector<std::vector<Edge<T>>> graph) {
    std::vector<T> mincost(n);
    std::vector<bool> used(n);
    for(int i = 0;i < n;i++) {
        mincost[i] = INF;
        used[i] = false;
    }
    mincost[0] = 0;
    long long res = 0;

    std::vector<std::vector<Edge<T>>> minimum_spanning_graph(n);
    while(true) {
        int v = -1;
        //Xに属さない頂点のうちXからの辺のコストが最小になる頂点を探す
        for(int u = 0;u < n;u++) {
            if(!used[u] && (v == -1 || mincost[u] < mincost[v])) {
                v = u;
            }
        }
        if(v == -1) break;
        used[v] = true; //頂点vをXに追加
        res += mincost[v];
        for(auto& [to,cost]: graph[v]) { 
            chmin(mincost[to],cost);
        }
    }
    return res;
}
