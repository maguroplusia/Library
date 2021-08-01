template<typename T>
struct edge {
    int to;
    T cost;
};

vector<int> pre;

template<typename T>
vector<T> Dijkstra(const int& N,const vector<vector<edge<T>>>& graph,const int& s) {
    priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> que;
    vector<T> dist(N,numeric_limits<T>::max());
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

vector<int> GetPath(cosnt int& t) {
    vector<int> path;

    while(t != -1) {
        path.push_back(t);
        t = pre[t];
    }

    reverse(path.begin(),path.end());
    return path;
}
