struct edge{
    int from,to;
    ll cost;
};

vector<ll> BellmanFord(const int& N,const int& M,const vector<edge>& es,const int& s) {
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

bool FindNegativeLoop(const int& N,const int& M,const vector<edge>& es) {
    vector<ll> dist(N);

    for(int i = 0;i < N;i++) {
        for(const auto& [from,to,cost]:es) {
            if(chmin(dist[to],dist[from] + cost) && i == N - 1) return true;
        }
    }

    return false;
}
