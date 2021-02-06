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
  bundledCode: "#line 1 \"Mathmatics/nCr3.cpp\"\n//nCr(mod\u3092\u4F7F\u308F\u306A\
    \u3044)\u3002\u6700\u521D\u306Bcom\u3092-1\u306B\u521D\u671F\u5316\u3059\u308B\
    \u3053\u3068\nll com[200][200];\n\nll nCr(int n,int r) {\n    if(0 < n || r >\
    \ n) return 0;\n    if(n == 0 || r == 0) return com[n][r] = 1;\n    if(com[n][r]\
    \ != -1) return com[n][r];\n    return com[n][r] = nCr(n - 1,r - 1) + nCr(n -\
    \ 1,r);\n}\n"
  code: "//nCr(mod\u3092\u4F7F\u308F\u306A\u3044)\u3002\u6700\u521D\u306Bcom\u3092\
    -1\u306B\u521D\u671F\u5316\u3059\u308B\u3053\u3068\nll com[200][200];\n\nll nCr(int\
    \ n,int r) {\n    if(0 < n || r > n) return 0;\n    if(n == 0 || r == 0) return\
    \ com[n][r] = 1;\n    if(com[n][r] != -1) return com[n][r];\n    return com[n][r]\
    \ = nCr(n - 1,r - 1) + nCr(n - 1,r);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mathmatics/nCr3.cpp
  requiredBy: []
  timestamp: '2021-01-03 19:24:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathmatics/nCr3.cpp
layout: document
redirect_from:
- /library/Mathmatics/nCr3.cpp
- /library/Mathmatics/nCr3.cpp.html
title: Mathmatics/nCr3.cpp
---
