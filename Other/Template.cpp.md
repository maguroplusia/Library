---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/yosupo-judge/UnionFind.test.cpp
    title: Test/yosupo-judge/UnionFind.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Other/Template.cpp\"\ntypedef long long ll;\nconstexpr int\
    \ Inf = 1000000030;\nconstexpr ll INF= 2000000000000000000;\nconstexpr ll MOD\
    \ = 1000000007;\nconst double PI = 3.1415926535897;\ntypedef pair<ll,ll> P;\n\
    typedef pair<ll,P> PP;\n\ntemplate<class T> inline bool chmax(T &a, T b) {\n \
    \   if (a < b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n}\n\
    \ntemplate<class T> inline bool chmin(T &a, T b) {\n    if (a > b) {\n       \
    \ a = b;\n        return 1;\n    }\n    return 0;\n}\n\n\nll mod(ll val, ll M)\
    \ {\n    val = val % M;\n    if(val < 0) {\n        val += M;\n    }\n    return\
    \ val;\n}\n\ntemplate<typename T>\nT RS(T N, T P, T M){\n    if(P == 0) {\n  \
    \      return 1;\n    }\n    if(P < 0) {\n        return 0;\n    }\n    if(P %\
    \ 2 == 0){\n        ll t = RS(N, P/2, M);\n        if(M == -1) return t * t;\n\
    \        return t * t % M;\n    }\n    if(M == -1) {\n        return N * RS(N,P\
    \ - 1,M);\n    }\n    return N * RS(N, P-1, M) % M;\n}\n"
  code: "typedef long long ll;\nconstexpr int Inf = 1000000030;\nconstexpr ll INF=\
    \ 2000000000000000000;\nconstexpr ll MOD = 1000000007;\nconst double PI = 3.1415926535897;\n\
    typedef pair<ll,ll> P;\ntypedef pair<ll,P> PP;\n\ntemplate<class T> inline bool\
    \ chmax(T &a, T b) {\n    if (a < b) {\n        a = b;\n        return 1;\n  \
    \  }\n    return 0;\n}\n\ntemplate<class T> inline bool chmin(T &a, T b) {\n \
    \   if (a > b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n}\n\
    \n\nll mod(ll val, ll M) {\n    val = val % M;\n    if(val < 0) {\n        val\
    \ += M;\n    }\n    return val;\n}\n\ntemplate<typename T>\nT RS(T N, T P, T M){\n\
    \    if(P == 0) {\n        return 1;\n    }\n    if(P < 0) {\n        return 0;\n\
    \    }\n    if(P % 2 == 0){\n        ll t = RS(N, P/2, M);\n        if(M == -1)\
    \ return t * t;\n        return t * t % M;\n    }\n    if(M == -1) {\n       \
    \ return N * RS(N,P - 1,M);\n    }\n    return N * RS(N, P-1, M) % M;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Other/Template.cpp
  requiredBy: []
  timestamp: '2021-01-04 15:16:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/yosupo-judge/UnionFind.test.cpp
documentation_of: Other/Template.cpp
layout: document
redirect_from:
- /library/Other/Template.cpp
- /library/Other/Template.cpp.html
title: Other/Template.cpp
---
