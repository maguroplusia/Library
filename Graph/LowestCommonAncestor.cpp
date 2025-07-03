struct LCA {
    int n;
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> parent;
    std::vector<int> depth;

    LCA(int n_, std::vector<std::vector<int>> graph_, int root): n(n_), graph(graph_) {
        parent.resize(40,std::vector<int>(n));
        depth.resize(n, -1);
        std::queue<int> que;
        depth[root] = 0;
        que.push(root);
        while(not que.empty()) {
            int v = que.front();
            que.pop();
            for(auto& x: graph[v]) {
                if(depth[x] == -1) {
                    depth[x] = depth[v] + 1;
                    parent[0][x] = v;
                    que.push(x);
                }
            }
        }
        for(int i = 0;i < 49;i++) {
            for(int j = 0;j < n;j++) {
                parent[i + 1][j] = parent[i][parent[i][j]];
            }
        }
    }

    int lca(int a, int b) {
        if(depth[a] > depth[b]) {
            swap(a,b);
        }
        for(int k = 0;k < 50;k++) {
            if((depth[a] - depth[b]) >> k & 1) {
                b = parent[k][b];
            }
        }
        if(a == b) return a;
        for(int k = 49;k >= 0;k--) {
            if(parent[k][a] != parent[k][b]) {
                a = parent[k][a];
                b = parent[k][b];
            }
        }
        return parent[0][a];
    }
};