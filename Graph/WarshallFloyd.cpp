int N; //頂点数
ll d[500][500]; //d[u][v]は辺e=(u,v)のコスト（存在しない場合はINF、ただしd[i][i]=0とする）

void init() {
    for(int i = 0;i < 500;i++) {
        for(int j = 0;j < 500;j++) {
            if(i == j) {
                d[i][j] = 0;
            }
            else {
                d[i][j] = INF;
            }
        }
    }
}

void WarshallFloyd() {
	for(int k = 0;k < N;k++) {
		for(int i = 0;i < N;i++) {
			for(int j = 0;j < N;j++) {
				chmin(d[i][j],d[i][k] + d[k][j]);
			}
		}
	}
}
