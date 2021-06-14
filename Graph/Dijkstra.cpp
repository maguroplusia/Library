struct edge{
    int to;
    ll cost;
};

int N;
vector<vector<edge>> graph;
vector<int> pre;

vector<ll> Dijkstra(int s) {
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que;
    vector<ll> dist(N,INF);
    pre = vector<int>(N,-1);
    dist[s] = 0;
    que.push({0,s});
    while(!que.empty()) {
        auto [cost,v] = que.top();
        que.pop();
        if(dist[v] < cost) continue;
        for(const auto& [to,d]:graph[v]) {
            if(chmin(dist[to],dist[v] + d)) {
                pre[to] = v;
                que.push({dist[to],to});
            }
        }
    }
    return dist;
}

vector<int> GetPath(int t) {
    vector<int> path;
    while(t != -1) {
        path.push_back(t);
        t = pre[t];
    }
    reverse(path.begin(),path.end());
    return path;
}
