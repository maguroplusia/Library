long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long comb(int n,int m,long long MOD) {
    std::vector<long long> res(m + 1);
    res[0] = 1;
    for(int i = 1;i <= m;i++) {
        res[i] = res[i - 1] * (n - (i - 1)) % MOD * modpow(i,MOD - 2,MOD) % MOD;
    }
    return;
}
