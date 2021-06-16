class UnionFind {
    vector<int> par;
    vector<int> siz;

public:

    UnionFind(int n) {
        par.resize(n);
        siz.resize(n);
        for(int i = 0;i < n;i++) {
            par[i] = i;
            siz[i] = 1;
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
        if(siz[x] < siz[y]) {
            swap(x,y);
        }
        par[y] = x;
        siz[x] += siz[y];
    }

    bool same(int x,int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return siz[find(x)];
    }
};
