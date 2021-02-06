//頂点fromから頂点toへのコストcostの辺
struct edge{
    int from,to;
    ll cost;
};

edge es[3010]; //辺
ll dist[3010]; //最短距離
int N,M; //頂点数、辺数

//s番目の頂点から各頂点への最短距離を求める（ただしs番目の頂点から負閉路を辿って行ける場合は-INF）
void BellmanFord(int s) {
    for(int i = 0;i < N;i++) {
        dist[i] = INF;
    }
    dist[s] = 0;
    for(int i = 0;i < N * 2;i++) {
        for(auto e:es) {
            if(dist[e.from] < INF && dist[e.from] + e.cost < dist[e.to])  {
                if(i >= N - 1) {
                    dist[e.to] = -INF;
                }
                else {
                    dist[e.to] = dist[e.from] + e.cost;
                }
            }
        }
    }
}

//trueなら負の閉路が存在する
bool find_negative_roop() {
    memset(dist,0,sizeof(dist));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            edge e = es[j];
            if(dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                if(i == N - 1) return true;
            }
        }
    }
    return false;
}
