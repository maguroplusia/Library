#include<bits/stdc++.h>
class SCC {
    int n;
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> rgraph;//辺を逆にはったグラフ
    std::vector<int> vs; //帰りがけ順の並び
    std::vector<bool> used; //既に頂点に訪れたか
    std::vector<int> cmp; //属する強連結成分のトポロジカル順序


    void dfs(int v) {
        used[v] = true;
        for(auto x:graph[v]) {
            if(not used[x]) dfs(x);
        }
        vs.push_back(v);
    }

    void rdfs(int v,int k) {
        used[v] = true;
        cmp[v] = k;
        for(auto x:rgraph[v]) {
            if(!used[x]) rdfs(x,k);
        }
    }

public:

    SCC(int n): n(n) {
        graph.resize(n);
        rgraph.resize(n);
        used.resize(n);
        cmp.resize(n);
    }

    void add_edge(int from,int to) {
        graph[from].push_back(to);
        rgraph[to].push_back(from);
    }

    //返り値は分解した後の頂点の数
    int scc() {
        vs.clear();
        for(int v = 0;v < n;v++) {
            if(not used[v]) dfs(v);
        }

        for(int i = 0;i < n;i++) {
            used[i] = false;
        }

        int k = 0;
        for(int i = vs.size() - 1;i >= 0;i--) {
            if(not used[vs[i]]) rdfs(vs[i],k++);
        }
        return k;
    }

    int operator[](int k) {return cmp[k];}

    bool same(int a,int b) {
        return cmp[a] == cmp[b];
    }
};
