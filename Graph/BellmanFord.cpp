//頂点fromから頂点toへのコストcostの辺
struct edge{
    int from,to;
    ll cost;
};

int N,M; //頂点数、辺数
vector<edge> es; //辺

vector<ll> BellmanFord(int s) {
    vector<ll> dist(N,INF);
    dist[s] = 0;

    for(int i = 0;i < N * 2;i++) {
        for(const auto& [from,to,cost]:es) {
            if(dist[from] < INF && dist[from] + cost < dist[to])  {
                if(i >= N - 1) dist[to] = -INF;
                else dist[to] = dist[from] + cost;
            }
        }
    }

    return dist;
}

//trueなら負の閉路が存在する
bool FindNegativeLoop() {
    vector<ll> dist(N);
    for(int i = 0;i < N;i++) {
        for(const auto& [from,to,cost]:es) {
            if(chmin(dist[to],dist[from] + cost) && i == N - 1) return true;
        }
    }
    return false;
}
