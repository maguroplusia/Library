class UnionFind {
    vector<int> par;
    vector<int> cluster_siz;
    int siz;
public:

    UnionFind(int n) {
        par.resize(n);
        cluster_siz.resize(n);
        siz = n;
        for(int i = 0;i < n;i++) {
            par[i] = i;
            cluster_siz[i] = 1;
        }
    }

    int find(int x) {
        if(par[x] == x) {
            return x;
        }
        else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int x,int y) {
        x = find(x);
        y = find(y);
        if(x == y) {
            return;
        }
        siz--;
        if(cluster_siz[x] < cluster_siz[y]) {
            swap(x,y);
        }
        par[y] = x;
        cluster_siz[x] += cluster_siz[y];
    }

    bool same(int x,int y) {
        return find(x) == find(y);
    }

    int cluster_size(int x) {
        return cluster_siz[find(x)];
    }

    int size() { return siz;}
};
