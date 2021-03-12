//nCr(modを使わない)。最初にcomを-1に初期化すること
ll com[200][200];

ll nCr(int n,int r) {
    if(0 < n || r > n) return 0;
    if(n == 0 || r == 0) return com[n][r] = 1;
    if(com[n][r] != -1) return com[n][r];
    return com[n][r] = nCr(n - 1,r - 1) + nCr(n - 1,r);
}
