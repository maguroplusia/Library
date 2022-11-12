struct Comb {
    int size;
    long long mod;
    std::vector<long long> factorial;
    std::vector<long long> inversion_factorial;
    std::vector<long long> inversion;

    Comb(int n,long long mod): size(n),mod(mod) {
        factorial.resize(n + 1);
        inversion_factorial.resize(n + 1);
        inversion.resize(n + 1);
        factorial[0] = factorial[1] = 1;
        inversion_factorial[0] = inversion_factorial[1] = 1;
        inversion[1] = 1;
        for (long long i = 2; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i % mod;
            inversion[i] = mod - inversion[mod % i] * (mod / i) % mod;
            inversion_factorial[i] = inversion_factorial[i - 1] * inversion[i] % mod;
        }
    }

    long long comb(int n, int k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return factorial[n] * (inversion_factorial[k] * inversion_factorial[n - k] % mod) % mod;
    }
};
