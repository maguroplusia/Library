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
  bundledCode: "#line 1 \"Mathematics/nCr.cpp\"\nstruct Comb {\n    int size;\n  \
    \  long long mod;\n    std::vector<long long> factorial;\n    std::vector<long\
    \ long> inversion_factorial;\n    std::vector<long long> inversion;\n\n    Comb(int\
    \ n,long long mod): size(n),mod(mod) {\n        factorial.resize(n + 1);\n   \
    \     inversion_factorial.resize(n + 1);\n        inversion.resize(n + 1);\n \
    \       factorial[0] = factorial[1] = 1;\n        inversion_factorial[0] = inversion_factorial[1]\
    \ = 1;\n        inversion[1] = 1;\n        for (long long i = 2; i <= n; i++)\
    \ {\n            factorial[i] = factorial[i - 1] * i % mod;\n            inversion[i]\
    \ = mod - inversion[mod % i] * (mod / i) % mod;\n            inversion_factorial[i]\
    \ = inversion_factorial[i - 1] * inversion[i] % mod;\n        }\n    }\n\n   \
    \ long long comb(int n, int k) {\n        if (n < k) return 0;\n        if (n\
    \ < 0 || k < 0) return 0;\n        return factorial[n] * (inversion_factorial[k]\
    \ * inversion_factorial[n - k] % mod) % mod;\n    }\n};\n"
  code: "struct Comb {\n    int size;\n    long long mod;\n    std::vector<long long>\
    \ factorial;\n    std::vector<long long> inversion_factorial;\n    std::vector<long\
    \ long> inversion;\n\n    Comb(int n,long long mod): size(n),mod(mod) {\n    \
    \    factorial.resize(n + 1);\n        inversion_factorial.resize(n + 1);\n  \
    \      inversion.resize(n + 1);\n        factorial[0] = factorial[1] = 1;\n  \
    \      inversion_factorial[0] = inversion_factorial[1] = 1;\n        inversion[1]\
    \ = 1;\n        for (long long i = 2; i <= n; i++) {\n            factorial[i]\
    \ = factorial[i - 1] * i % mod;\n            inversion[i] = mod - inversion[mod\
    \ % i] * (mod / i) % mod;\n            inversion_factorial[i] = inversion_factorial[i\
    \ - 1] * inversion[i] % mod;\n        }\n    }\n\n    long long comb(int n, int\
    \ k) {\n        if (n < k) return 0;\n        if (n < 0 || k < 0) return 0;\n\
    \        return factorial[n] * (inversion_factorial[k] * inversion_factorial[n\
    \ - k] % mod) % mod;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/nCr.cpp
  requiredBy: []
  timestamp: '2022-11-12 23:12:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathematics/nCr.cpp
layout: document
redirect_from:
- /library/Mathematics/nCr.cpp
- /library/Mathematics/nCr.cpp.html
title: Mathematics/nCr.cpp
---
