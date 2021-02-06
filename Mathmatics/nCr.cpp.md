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
  bundledCode: "#line 1 \"Mathmatics/nCr.cpp\"\nll fac[1000010], finv[1000010], inv[1000010];\n\
    \n// \u30C6\u30FC\u30D6\u30EB\u3092\u4F5C\u308B\u524D\u51E6\u7406\nvoid COMinit()\n\
    {\n    fac[0] = fac[1] = 1;\n    finv[0] = finv[1] = 1;\n    inv[1] = 1;\n   \
    \ for (int i = 2; i < 1000010; i++)\n    {\n        fac[i] = fac[i - 1] * i %\
    \ MOD;\n        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;\n        finv[i]\
    \ = finv[i - 1] * inv[i] % MOD;\n    }\n}\n\n// \u4E8C\u9805\u4FC2\u6570\u8A08\
    \u7B97\nlong long COM(int n, int k)\n{\n    if (n < k)\n        return 0;\n  \
    \  if (n < 0 || k < 0)\n        return 0;\n    return fac[n] * (finv[k] * finv[n\
    \ - k] % MOD) % MOD;\n}\n"
  code: "ll fac[1000010], finv[1000010], inv[1000010];\n\n// \u30C6\u30FC\u30D6\u30EB\
    \u3092\u4F5C\u308B\u524D\u51E6\u7406\nvoid COMinit()\n{\n    fac[0] = fac[1] =\
    \ 1;\n    finv[0] = finv[1] = 1;\n    inv[1] = 1;\n    for (int i = 2; i < 1000010;\
    \ i++)\n    {\n        fac[i] = fac[i - 1] * i % MOD;\n        inv[i] = MOD -\
    \ inv[MOD % i] * (MOD / i) % MOD;\n        finv[i] = finv[i - 1] * inv[i] % MOD;\n\
    \    }\n}\n\n// \u4E8C\u9805\u4FC2\u6570\u8A08\u7B97\nlong long COM(int n, int\
    \ k)\n{\n    if (n < k)\n        return 0;\n    if (n < 0 || k < 0)\n        return\
    \ 0;\n    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mathmatics/nCr.cpp
  requiredBy: []
  timestamp: '2021-01-03 18:39:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathmatics/nCr.cpp
layout: document
redirect_from:
- /library/Mathmatics/nCr.cpp
- /library/Mathmatics/nCr.cpp.html
title: Mathmatics/nCr.cpp
---
