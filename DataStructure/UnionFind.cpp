class UnionFind {
    vector<int> par; //親
    vector<int> siz; //根ノードiの木に含まれる要素数。iが根ノード出ない場合無意味な値となる。

public:
    //n要素で初期化
    UnionFind(int n) {
        par.resize(n);
        siz.resize(n);
        for(int i = 0;i < n;i++) {
            par[i] = i;
            siz[i] = 1;
        }
    }

    //木の根を求める
    int find(int x) {
        if(par[x] == x) {
            return x;
        }
        else {
            return par[x] = find(par[x]);
        }
    }

    //ｘとｙの属する集合を併合
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

    //ｘとｙが同じ集合に属するか否か
    bool same(int x,int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return siz[find(x)];
    }
};
