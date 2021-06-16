int N; //頂点数
long long dist[500][500]; //d[u][v]は辺e=(u,v)のコスト（存在しない場合はINF、ただしd[i][i]=0とする）

void init() {
    for(int i = 0;i < 500;i++) {
        for(int j = 0;j < 500;j++) {
            if(i == j) {
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = INF;
            }
        }
    }
}

void WarshallFloyd() {
    for(int k = 0;k < N;k++) {
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < N;j++) {
                if(dist[i][k] != INF && dist[k][j] != INF) {
                    chmin(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
