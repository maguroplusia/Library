//頂点fromから頂点toへのコストcostの辺
struct edge{
	int from,to;
    ll cost;
};

edge es[200010]; //辺
ll d[200010]; //最短距離
int N,M; //頂点数、辺数

//s番目の頂点から各頂点への最短距離を求める（ただし始点から終点までの間に負閉路がある場合はfalseを返す）
bool BellmanFord(int s,int g) {
	for(int i = 0;i < N;i++) {
		d[i] = INF;
	}
	d[s] = 0;
	for(int i = 0;i < N * 2;i++) {
		for(auto x:es) {
			if(d[e.from] < INF && d[e.from] + e.cost < d[e.to])  {
				if(i >= N - 1 && e.to == g) {
					return false;
				}
				else if(i >= N - 1) {
					d[e.to] = -INF;
				}
				else {
					d[e.to] = d[e.from] + e.cost;
				}
			}
		}
	}
	return d[g];
}

//trueなら負の閉路が存在する
bool find_negative_roop() {
	memset(d,0,sizeof(d));
	for(int i = 0;i < N;i++) {
		for(int j = 0;j < M;j++) {
			edge e = es[j];
			if(d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				if(i == N - 1) return true;
			}
		}
	}
	return false;
}
