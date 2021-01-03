ll cost[20010][20010]; // cost[u][v]は辺e=(u,v)のコスト
ll mincost[20010]; // 集合Xからのへ辺の最小コスト
bool used[20010]; //すでに頂点iがXに含まれているか
int V;

int prim() {
    for(int i = 0;i < V;i++) {
        mincost[i] = INF;
        used[i] = false;
    }
    mincost[0] = 0;
    int res = 0;
    while(true) {
        int v = -1;
        //Xに属さない頂点のうちXからの辺のコストが最小になる頂点を探す
        for(int u = 0;u < V;u++) {
            if(!used[u] && (v == -1 || mincost[u] < mincost[v])) {
                v = u;
            }
        }
        if(v == -1) {
            break;
        }
        used[v] = true; //頂点vをXに追加
        res += mincost[v];
        for(int u = 0;u < V;u++) {
            chmin(mincost[u],mincost[v]);
        }
    }
    return res;
}
