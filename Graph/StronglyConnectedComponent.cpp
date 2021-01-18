class SCC {
    int N;
    vector<int> graph[200010];
    vector<int> rgraph[200010];//辺を逆にはったグラフ
    vector<int> vs; //帰りがけ順の並び
    bool used[200010]; //既に頂点に訪れたか
    int cmp[200010]; //属する強連結成分のトポロジカル順序


    void dfs(int v) {
        used[v] = true;
        for(auto x:graph[v]) {
            if(!used[x]) dfs(x);
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

    SCC(int n) {
        N = n;
    }

    void add_edge(int from,int to) {
        graph[from].push_back(to);
        rgraph[to].push_back(from);
    }

    //返り値は分解した後の頂点の数
    int scc() {
        memset(used,0,sizeof(used));
        vs.clear();
        for(int v = 0;v < N;v++) {
            if(!used[v]) dfs(v);
        }
        memset(used,0,sizeof(used));
        int k = 0;
        for(int i = vs.size() - 1;i >= 0;i--) {
            if(!used[vs[i]]) rdfs(vs[i],k++);
        }
        return k;
    }

    bool same(int a,int b) {
        return cmp[a] == cmp[b];
    }
}
