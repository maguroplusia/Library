---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/WarshallFloyd.test.cpp
    title: Test/AOJ/WarshallFloyd.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/WarshallFloyd.cpp\"\nint N; //\u9802\u70B9\u6570\n\
    long long dist[500][500]; //d[u][v]\u306F\u8FBAe=(u,v)\u306E\u30B3\u30B9\u30C8\
    \uFF08\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306FINF\u3001\u305F\u3060\u3057\
    d[i][i]=0\u3068\u3059\u308B\uFF09\n\nvoid init() {\n    for(int i = 0;i < 500;i++)\
    \ {\n        for(int j = 0;j < 500;j++) {\n            if(i == j) {\n        \
    \        dist[i][j] = 0;\n            }\n            else {\n                dist[i][j]\
    \ = INF;\n            }\n        }\n    }\n}\n\nvoid WarshallFloyd() {\n    for(int\
    \ k = 0;k < N;k++) {\n        for(int i = 0;i < N;i++) {\n            for(int\
    \ j = 0;j < N;j++) {\n                if(dist[i][k] != INF && dist[k][j] != INF)\
    \ {\n                    chmin(dist[i][j],dist[i][k] + dist[k][j]);\n        \
    \        }\n            }\n        }\n    }\n}\n"
  code: "int N; //\u9802\u70B9\u6570\nlong long dist[500][500]; //d[u][v]\u306F\u8FBA\
    e=(u,v)\u306E\u30B3\u30B9\u30C8\uFF08\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    \u306FINF\u3001\u305F\u3060\u3057d[i][i]=0\u3068\u3059\u308B\uFF09\n\nvoid init()\
    \ {\n    for(int i = 0;i < 500;i++) {\n        for(int j = 0;j < 500;j++) {\n\
    \            if(i == j) {\n                dist[i][j] = 0;\n            }\n  \
    \          else {\n                dist[i][j] = INF;\n            }\n        }\n\
    \    }\n}\n\nvoid WarshallFloyd() {\n    for(int k = 0;k < N;k++) {\n        for(int\
    \ i = 0;i < N;i++) {\n            for(int j = 0;j < N;j++) {\n               \
    \ if(dist[i][k] != INF && dist[k][j] != INF) {\n                    chmin(dist[i][j],dist[i][k]\
    \ + dist[k][j]);\n                }\n            }\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/WarshallFloyd.cpp
  requiredBy: []
  timestamp: '2021-06-16 21:47:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/WarshallFloyd.test.cpp
documentation_of: Graph/WarshallFloyd.cpp
layout: document
redirect_from:
- /library/Graph/WarshallFloyd.cpp
- /library/Graph/WarshallFloyd.cpp.html
title: Graph/WarshallFloyd.cpp
---
