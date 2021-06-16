long long com[2000010];

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

void COM(int n) {
    com[0] = 1;
    for(int i = 1;i < min(n + 1,2000010long long);i++) {
        com[i] = com[i - 1] * (n - (i - 1)) % MOD * modinv(i,MOD) % MOD;
    }
    return;
}
