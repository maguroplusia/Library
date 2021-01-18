---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/AOJ/Prim.test.cpp
    title: Test/AOJ/Prim.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/Prim.cpp\"\nll cost[20010][20010]; // cost[u][v]\u306F\
    \u8FBAe=(u,v)\u306E\u30B3\u30B9\u30C8\nll mincost[20010]; // \u96C6\u5408X\u304B\
    \u3089\u306E\u3078\u8FBA\u306E\u6700\u5C0F\u30B3\u30B9\u30C8\nbool used[20010];\
    \ //\u3059\u3067\u306B\u9802\u70B9i\u304CX\u306B\u542B\u307E\u308C\u3066\u3044\
    \u308B\u304B\nint N; //\u9802\u70B9\u306E\u500B\u6570\n\nll prim() {\n    for(int\
    \ i = 0;i < N;i++) {\n        mincost[i] = INF;\n        used[i] = false;\n  \
    \  }\n    mincost[0] = 0;\n    ll res = 0;\n    while(true) {\n        int v =\
    \ -1;\n        //X\u306B\u5C5E\u3055\u306A\u3044\u9802\u70B9\u306E\u3046\u3061\
    X\u304B\u3089\u306E\u8FBA\u306E\u30B3\u30B9\u30C8\u304C\u6700\u5C0F\u306B\u306A\
    \u308B\u9802\u70B9\u3092\u63A2\u3059\n        for(int u = 0;u < N;u++) {\n   \
    \         if(!used[u] && (v == -1 || mincost[u] < mincost[v])) {\n           \
    \     v = u;\n            }\n        }\n        if(v == -1) {\n            break;\n\
    \        }\n        used[v] = true; //\u9802\u70B9v\u3092X\u306B\u8FFD\u52A0\n\
    \        res += mincost[v];\n        for(int u = 0;u < V;u++) {\n            chmin(mincost[u],mincost[v]);\n\
    \        }\n    }\n    return res;\n}\n"
  code: "ll cost[20010][20010]; // cost[u][v]\u306F\u8FBAe=(u,v)\u306E\u30B3\u30B9\
    \u30C8\nll mincost[20010]; // \u96C6\u5408X\u304B\u3089\u306E\u3078\u8FBA\u306E\
    \u6700\u5C0F\u30B3\u30B9\u30C8\nbool used[20010]; //\u3059\u3067\u306B\u9802\u70B9\
    i\u304CX\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\nint N; //\u9802\u70B9\
    \u306E\u500B\u6570\n\nll prim() {\n    for(int i = 0;i < N;i++) {\n        mincost[i]\
    \ = INF;\n        used[i] = false;\n    }\n    mincost[0] = 0;\n    ll res = 0;\n\
    \    while(true) {\n        int v = -1;\n        //X\u306B\u5C5E\u3055\u306A\u3044\
    \u9802\u70B9\u306E\u3046\u3061X\u304B\u3089\u306E\u8FBA\u306E\u30B3\u30B9\u30C8\
    \u304C\u6700\u5C0F\u306B\u306A\u308B\u9802\u70B9\u3092\u63A2\u3059\n        for(int\
    \ u = 0;u < N;u++) {\n            if(!used[u] && (v == -1 || mincost[u] < mincost[v]))\
    \ {\n                v = u;\n            }\n        }\n        if(v == -1) {\n\
    \            break;\n        }\n        used[v] = true; //\u9802\u70B9v\u3092\
    X\u306B\u8FFD\u52A0\n        res += mincost[v];\n        for(int u = 0;u < V;u++)\
    \ {\n            chmin(mincost[u],mincost[v]);\n        }\n    }\n    return res;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Prim.cpp
  requiredBy: []
  timestamp: '2021-01-18 18:22:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/AOJ/Prim.test.cpp
documentation_of: Graph/Prim.cpp
layout: document
redirect_from:
- /library/Graph/Prim.cpp
- /library/Graph/Prim.cpp.html
title: Graph/Prim.cpp
---
