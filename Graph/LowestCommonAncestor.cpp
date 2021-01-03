int N;
vector<int> graph[200010];

int root = 0;

int parent[50][200010];
int depth[200010];

void dfs(int v,int p,int d) {
    parent[0][v] = p;
    depth[v] = d;
    for(int i = 0;i < graph[v].size();i++) {
        if(graph[v][i] != p) {
            dfs(graph[v][i],v,d + 1);
        }
    }
}

void init(int V) {
    dfs(root,-1,0);
    for(int k = 0;k + 1 < 50;k++) {
        for(int v = 0;v < V;v++) {
            if(parent[k][v] < 0) {
                parent[k + 1][v] = -1;
            }
            else {
                parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }
}

int lca(int u,int v) {
    if(depth[u] > depth[v]) {
        swap(u,v);
    }
    for(int k = 0;k < 50;k++) {
        if((depth[v] - depth[u]) >> k & 1) {
            v = parent[k][v];
        }
    }
    if(u == v) {
        return u;
    }
    for(int k = 49;k >= 0;k--) {
        if(parent[k][u] != parent[k][v]) {
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}
