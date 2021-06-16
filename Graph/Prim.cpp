long long cost[2010][2010]; // cost[u][v]は辺e=(u,v)のコスト
long long mincost[2010]; // 集合Xからのへ辺の最小コスト
bool used[2010]; //すでに頂点iがXに含まれているか
int N,M; //頂点の個数、辺の本数

long long prim() {
    for(int i = 0;i < N;i++) {
        mincost[i] = INF;
        used[i] = false;
    }
    mincost[0] = 0;
    long long res = 0;
    while(true) {
        int v = -1;
        //Xに属さない頂点のうちXからの辺のコストが最小になる頂点を探す
        for(int u = 0;u < N;u++) {
            if(!used[u] && (v == -1 || mincost[u] < mincost[v])) {
                v = u;
            }
        }
        if(v == -1) break;
        used[v] = true; //頂点vをXに追加
        res += mincost[v];
        for(int u = 0;u < N;u++) {
            chmin(mincost[u],cost[v][u]);
        }
    }
    return res;
}
