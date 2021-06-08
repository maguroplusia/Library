typedef long long ll;

template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
T modpow(T N, T P, T M){
    if(P == 0) return 1;
    if(P < 0) return 0;
    if(P % 2 == 0){
        T t = modpow(N, P/2, M);
        if(M == -1) return t * t;
        return t * t % M;
    }
    if(M == -1) return N * modpow(N,P - 1,M);
    return N * modpow(N, P-1, M) % M;
}
