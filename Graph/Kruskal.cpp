#include"../DataStructure/UnionFind.cpp"

struct edge {
    int u,v;
    long long cost;

    bool operator<(const edge& b) const {
        return cost < b.cost;
    }
};

int N,M;
edge graph[200010];

long long Kruskal() {
    sort(graph,graph + M);
    UnionFind uf(N);
    long long ret = 0;
    for(int i = 0;i < M;i++) {
        edge e = graph[i];
        if(!uf.same(e.u,e.v)) {
            uf.unite(e.u,e.v);
            ret += e.cost;
        }
    }
    return ret;
}
