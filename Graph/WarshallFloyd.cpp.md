---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/AOJ/WarshallFloyd.test.cpp
    title: Test/AOJ/WarshallFloyd.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/WarshallFloyd.cpp\"\nint N; //\u9802\u70B9\u6570\n\
    ll d[500][500]; //d[u][v]\u306F\u8FBAe=(u,v)\u306E\u30B3\u30B9\u30C8\uFF08\u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408\u306FINF\u3001\u305F\u3060\u3057d[i][i]=0\u3068\
    \u3059\u308B\uFF09\n\nvoid init() {\n    for(int i = 0;i < 500;i++) {\n      \
    \  for(int j = 0;j < 500;j++) {\n            if(i == j) {\n                d[i][j]\
    \ = 0;\n            }\n            else {\n                d[i][j] = INF;\n  \
    \          }\n        }\n    }\n}\n\nvoid WarshallFloyd() {\n\tfor(int k = 0;k\
    \ < N;k++) {\n\t\tfor(int i = 0;i < N;i++) {\n\t\t\tfor(int j = 0;j < N;j++) {\n\
    \t\t\t\tchmin(d[i][j],d[i][k] + d[k][j]);\n\t\t\t}\n\t\t}\n\t}\n}\n"
  code: "int N; //\u9802\u70B9\u6570\nll d[500][500]; //d[u][v]\u306F\u8FBAe=(u,v)\u306E\
    \u30B3\u30B9\u30C8\uFF08\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306FINF\u3001\
    \u305F\u3060\u3057d[i][i]=0\u3068\u3059\u308B\uFF09\n\nvoid init() {\n    for(int\
    \ i = 0;i < 500;i++) {\n        for(int j = 0;j < 500;j++) {\n            if(i\
    \ == j) {\n                d[i][j] = 0;\n            }\n            else {\n \
    \               d[i][j] = INF;\n            }\n        }\n    }\n}\n\nvoid WarshallFloyd()\
    \ {\n\tfor(int k = 0;k < N;k++) {\n\t\tfor(int i = 0;i < N;i++) {\n\t\t\tfor(int\
    \ j = 0;j < N;j++) {\n\t\t\t\tchmin(d[i][j],d[i][k] + d[k][j]);\n\t\t\t}\n\t\t\
    }\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/WarshallFloyd.cpp
  requiredBy: []
  timestamp: '2021-01-03 18:28:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/AOJ/WarshallFloyd.test.cpp
documentation_of: Graph/WarshallFloyd.cpp
layout: document
redirect_from:
- /library/Graph/WarshallFloyd.cpp
- /library/Graph/WarshallFloyd.cpp.html
title: Graph/WarshallFloyd.cpp
---
