//nCr(modを使わない)
ll com[200][200];

void init() {
    for (size_t i = 0; i < 200; i++) {
        for (size_t j = 0; j < 200; j++) {
            com[i][j] = -1;
        }
    }
}

ll nCr(int n,int r) {
    if(0 < n || r > n) return 0;
    if(n == 0 || r == 0) return com[n][r] = 1;
    if(com[n][r] != -1) return com[n][r];
    return com[n][r] = nCr(n - 1,r - 1) + nCr(n - 1,r);
}
