struct edge{
    int to;
    ll cost;
};

int N; //頂点数
vector<edge> graph[200010];
ll dist[200010]; //頂点sからの最短距離
int pre[200010];

void Dijkstra(int s) {
    //greater<P>を指定することでfirstが小さい順に取り出せる
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>> que;
    fill(dist,dist + N,INF);
    fill(pre,pre + N,-1);
    dist[s] = 0;
    que.push(P(0,s));

    while(!que.empty()) {
        auto [cost,v] = que.top();
        que.pop();
        if(dist[v] < cost) continue;
        for(auto [d,to]:graph[v]) {
            if(chmin(dist[to],dist[v] + d)) {
                pre[to] = v;
                que.push({dist[to],to});
            }
        }
    }
}

//最短路を取得
vector<int> get_path(int t) {
    vector<int> path;
    while(t != -1) {
        path.push_back(t);
        t = pre[t];
    }
    reverse(path.begin(),path.end());
    return path;
}
