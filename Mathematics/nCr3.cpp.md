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
  bundledCode: "#line 1 \"Mathematics/nCr3.cpp\"\n//nCr(mod\u3092\u4F7F\u308F\u306A\
    \u3044)\nll com[200][200];\n\nvoid init() {\n    for (size_t i = 0; i < 200; i++)\
    \ {\n        for (size_t j = 0; j < 200; j++) {\n            com[i][j] = -1;\n\
    \        }\n    }\n}\n\nll nCr(int n,int r) {\n    if(0 < n || r > n) return 0;\n\
    \    if(n == 0 || r == 0) return com[n][r] = 1;\n    if(com[n][r] != -1) return\
    \ com[n][r];\n    return com[n][r] = nCr(n - 1,r - 1) + nCr(n - 1,r);\n}\n"
  code: "//nCr(mod\u3092\u4F7F\u308F\u306A\u3044)\nll com[200][200];\n\nvoid init()\
    \ {\n    for (size_t i = 0; i < 200; i++) {\n        for (size_t j = 0; j < 200;\
    \ j++) {\n            com[i][j] = -1;\n        }\n    }\n}\n\nll nCr(int n,int\
    \ r) {\n    if(0 < n || r > n) return 0;\n    if(n == 0 || r == 0) return com[n][r]\
    \ = 1;\n    if(com[n][r] != -1) return com[n][r];\n    return com[n][r] = nCr(n\
    \ - 1,r - 1) + nCr(n - 1,r);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/nCr3.cpp
  requiredBy: []
  timestamp: '2021-04-20 16:28:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathematics/nCr3.cpp
layout: document
redirect_from:
- /library/Mathematics/nCr3.cpp
- /library/Mathematics/nCr3.cpp.html
title: Mathematics/nCr3.cpp
---
