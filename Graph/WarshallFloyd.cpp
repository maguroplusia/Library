vector<vector<long long>> WarshallFloyd(const int& N,const vector<vector<long long>> dist) {
    vector<vector<long long>> ret = dist;
    for(int k = 0;k < N;k++) {
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < N;j++) {
                if(ret[i][k] != INF && ret[k][j] != INF) {
                    chmin(ret[i][j],ret[i][k] + ret[k][j]);
                }
            }
        }
    }
    return ret;
}
