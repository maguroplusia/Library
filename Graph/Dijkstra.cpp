struct edge{
    int to;
    long long cost;
};

vector<int> pre;

vector<long long> Dijkstra(const int& N,const vector<vector<edge>>& graph,const int& s) {
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> que;
    vector<long long> dist(N,INF);
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
