template<typename T>
struct Edge {
    int to;
    T cost;
};

std::vector<int> pre;

template<typename T>
std::vector<T> dijkstra(const int& node,const vector<vector<Edge<T>>>& graph,const int& start) {
    std::priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> que;
    vector<T> dist(node,numeric_limits<T>::max());
    pre = vector<int>(node,-1);
    dist[start] = 0;
    que.push({0,start});

    while(!que.empty()) {
        auto [cost,v] = que.top();
        que.pop();
        if(dist[v] < cost) continue;
        for(const auto& [to,d]:graph[v]) {
            if(dist[to] > dist[v] + d) {
                dist[to] = dist[v] + d;
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
