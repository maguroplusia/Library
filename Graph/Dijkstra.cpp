struct edge{
	int to;
	ll cost;
};

int N; //頂点数
vector<edge> graph[200010];
ll d[200010]; //頂点sからの最短距離
int pre[200010];

void Dijkstra(int s) {
	//greater<P>を指定することでfirstが小さい順に取り出せる
	priority_queue<P,vector<P>,greater<P>> que;
	fill(d,d + N,INF);
	fill(pre,pre + N,-1);
	d[s] = 0;
	que.push(P(0,s));

	while(!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if(d[v] < p.first) {
			continue;
		}
        for(auto x:graph[v]) {
            if(chmin(d[x.to],d[v] + x.cost)) {
                pre[x.to] = v;
                que.push(P(d[x.to],x.to));
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
