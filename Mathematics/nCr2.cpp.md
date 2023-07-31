---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Mathematics/nCr2.cpp\"\nlong long modpow(long long a, long\
    \ long n, long long mod) {\n    long long res = 1;\n    while (n > 0) {\n    \
    \    if (n & 1) res = res * a % mod;\n        a = a * a % mod;\n        n >>=\
    \ 1;\n    }\n    return res;\n}\n\nlong long comb(int n,int m,long long MOD) {\n\
    \    std::vector<long long> res(m + 1);\n    res[0] = 1;\n    for(int i = 1;i\
    \ <= m;i++) {\n        res[i] = res[i - 1] * (n - (i - 1)) % MOD * modpow(i,MOD\
    \ - 2,MOD) % MOD;\n    }\n    return;\n}\n"
  code: "long long modpow(long long a, long long n, long long mod) {\n    long long\
    \ res = 1;\n    while (n > 0) {\n        if (n & 1) res = res * a % mod;\n   \
    \     a = a * a % mod;\n        n >>= 1;\n    }\n    return res;\n}\n\nlong long\
    \ comb(int n,int m,long long MOD) {\n    std::vector<long long> res(m + 1);\n\
    \    res[0] = 1;\n    for(int i = 1;i <= m;i++) {\n        res[i] = res[i - 1]\
    \ * (n - (i - 1)) % MOD * modpow(i,MOD - 2,MOD) % MOD;\n    }\n    return;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/nCr2.cpp
  requiredBy: []
  timestamp: '2023-07-31 10:53:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathematics/nCr2.cpp
layout: document
redirect_from:
- /library/Mathematics/nCr2.cpp
- /library/Mathematics/nCr2.cpp.html
title: Mathematics/nCr2.cpp
---
