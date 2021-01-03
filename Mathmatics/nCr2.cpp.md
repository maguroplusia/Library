---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Mathmatics/nCr2.cpp\"\nll com[2000010];\n\nlong long modpow(long\
    \ long a, long long n, long long mod) {\n    long long res = 1;\n    while (n\
    \ > 0) {\n        if (n & 1) res = res * a % mod;\n        a = a * a % mod;\n\
    \        n >>= 1;\n    }\n    return res;\n}\n\nlong long modinv(long long a,\
    \ long long mod) {\n    return modpow(a, mod - 2, mod);\n}\n\nvoid COM(int n)\
    \ {\n    com[0] = 1;\n    for(int i = 1;i < min(n + 1,2000010ll);i++) {\n    \
    \    com[i] = com[i - 1] * (n - (i - 1)) % MOD * modinv(i,MOD) % MOD;\n    }\n\
    \    return;\n}\n"
  code: "ll com[2000010];\n\nlong long modpow(long long a, long long n, long long\
    \ mod) {\n    long long res = 1;\n    while (n > 0) {\n        if (n & 1) res\
    \ = res * a % mod;\n        a = a * a % mod;\n        n >>= 1;\n    }\n    return\
    \ res;\n}\n\nlong long modinv(long long a, long long mod) {\n    return modpow(a,\
    \ mod - 2, mod);\n}\n\nvoid COM(int n) {\n    com[0] = 1;\n    for(int i = 1;i\
    \ < min(n + 1,2000010ll);i++) {\n        com[i] = com[i - 1] * (n - (i - 1)) %\
    \ MOD * modinv(i,MOD) % MOD;\n    }\n    return;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mathmatics/nCr2.cpp
  requiredBy: []
  timestamp: '2021-01-03 18:39:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathmatics/nCr2.cpp
layout: document
redirect_from:
- /library/Mathmatics/nCr2.cpp
- /library/Mathmatics/nCr2.cpp.html
title: Mathmatics/nCr2.cpp
---
