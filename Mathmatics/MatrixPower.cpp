//行列の積を求める（ただしAの横の要素数とBの縦の要素数が異なったらRE）
vector<vector<ll>> matpro(vector<vector<ll>> A,vector<vector<ll>> B) {
    assert(A.at(0).size() == B.size());
    int N = A.size();
    int M = B.at(0).size();
    int K = A.at(0).size();
    vector<vector<ll>> res(N,vector<ll>(M));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            for(int k = 0;k < K;k++) {
                res.at(i).at(j) += A.at(i).at(k) * B.at(k).at(j);
            }
        }
    }
    return res;
}

//行列累乗、A^Pを求める
vector<vector<ll>> matpow(ll P,vector<vector<ll>> A) {
    int M = A.size();
    vector<vector<ll>> res(M,vector<ll>(M));
    for(int i = 0;i < M;i++) {
        res.at(i).at(i) = 1;
    }
    if(P == 0) {
        return res;
    }
    if(P % 2 == 0) {
        vector<vector<ll>> cnt = matpow(P / 2,A);
        return matpro(cnt,cnt);
    }
    return matpro(A,matpow(P - 1,A));
}
