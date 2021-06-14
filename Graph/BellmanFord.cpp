//頂点fromから頂点toへのコストcostの辺
struct edge{
    int from,to;
    ll cost;
};

int N,M; //頂点数、辺数
vector<edge> es; //辺
vector<ll> dist; //最短距離

//s番目の頂点から各頂点への最短距離を求める（ただしs番目の頂点から負閉路を辿って行ける場合は-INF）
void BellmanFord(int s) {
    dist = vector<ll>(N,INF);
    dist[s] = 0;

    for(int i = 0;i < N * 2;i++) {
        for(const auto& [from,to,cost]:es) {
            if(dist[from] < INF && dist[from] + cost < dist[to])  {
                if(i >= N - 1) dist[to] = -INF;
                else dist[to] = dist[from] + cost;
            }
        }
    }
}

//trueなら負の閉路が存在する
bool find_negative_roop() {
    dist = vector<ll>(N);
    for(int i = 0;i < N;i++) {
        for(const auto& [from,to,cost]:es) {
            if(chmin(dist[to],dist[from] + cost) && i == N - 1) return true;
        }
    }
    return false;
}
