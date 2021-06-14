struct edge{
    int to;
    ll cost;
};

int N;
vector<edge> graph[200010];
vector<ll> dist;
vector<int> pre;

void Dijkstra(int s) {
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>> que;
    dist = vector<ll>(N,INF);
    pre = vector<int>(N,-1);
    dist[s] = 0;
    que.push({0,s});

    while(!que.empty()) {
        auto [cost,v] = que.top();
        que.pop();
        if(dist[v] < cost) continue;
        for(const auto& [d,to]:graph[v]) {
            if(chmin(dist[to],dist[v] + d)) {
                pre[to] = v;
                que.push({dist[to],to});
            }
        }
    }
}

vector<int> get_path(int t) {
    vector<int> path;
    while(t != -1) {
        path.push_back(t);
        t = pre[t];
    }
    reverse(path.begin(),path.end());
    return path;
}
