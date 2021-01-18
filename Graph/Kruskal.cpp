//UnionFindライブラリを呼び出すこと
struct edge {
    int u,v;
    ll cost;
};

bool comp(const edge &e1,const edge &e2) {
    return e1.cost < e2.cost;
}

int N,M; //頂点の本数、点の個数
edge graph[200010];

ll Kruskal() {
    sort(graph,graph + M,comp);
    Union_find uf(N);
    ll ret = 0;
    for(int i = 0;i < M;i++) {
        edge e = graph[i];
        if(!uf.same(e.u,e.v)) {
            uf.unite(e.u,e.v);
            ret += e.cost;
        }
    }
    return ret;
}
