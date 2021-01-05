//頂点fromから頂点toへのコストcostの辺
struct edge{
	int from,to;
    ll cost;
};

edge es[2010]; //辺
ll d[2010]; //最短距離
int N,M; //頂点数、辺数

//s番目の頂点から各頂点への最短距離を求める（ただしs番目の頂点から負閉路を辿って行ける場合は-INF）
void BellmanFord(int s) {
	for(int i = 0;i < N;i++) {
		d[i] = INF;
	}
	d[s] = 0;
	for(int i = 0;i < N * 2;i++) {
		for(auto x:es) {
			if(d[e.from] < INF && d[e.from] + e.cost < d[e.to])  {
				if(i >= N - 1) {
					d[e.to] = -INF;
				}
				else {
					d[e.to] = d[e.from] + e.cost;
				}
			}
		}
	}
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
