---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/Kruskal.cpp\"\n//UnionFind\u30E9\u30A4\u30D6\u30E9\
    \u30EA\u3092\u547C\u3073\u51FA\u3059\u3053\u3068\nstruct edge {\n    int u,v;\n\
    \    ll cost;\n};\n\nbool comp(const edge &e1,const edge &e2) {\n    return e1.cost\
    \ < e2.cost;\n}\n\nint N,M;\nedge graph[200010];\n\nll Kruskal() {\n    sort(graph,graph\
    \ + M,comp);\n    Union_find uf(N);\n    ll ret = 0;\n    for(int i = 0;i < M;i++)\
    \ {\n        edge e = graph[i];\n        if(!uf.same(e.u,e.v)) {\n           \
    \ uf.unite(e.u,e.v);\n            ret += e.cost;\n        }\n    }\n    return\
    \ ret;\n}\n"
  code: "//UnionFind\u30E9\u30A4\u30D6\u30E9\u30EA\u3092\u547C\u3073\u51FA\u3059\u3053\
    \u3068\nstruct edge {\n    int u,v;\n    ll cost;\n};\n\nbool comp(const edge\
    \ &e1,const edge &e2) {\n    return e1.cost < e2.cost;\n}\n\nint N,M;\nedge graph[200010];\n\
    \nll Kruskal() {\n    sort(graph,graph + M,comp);\n    Union_find uf(N);\n   \
    \ ll ret = 0;\n    for(int i = 0;i < M;i++) {\n        edge e = graph[i];\n  \
    \      if(!uf.same(e.u,e.v)) {\n            uf.unite(e.u,e.v);\n            ret\
    \ += e.cost;\n        }\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Kruskal.cpp
  requiredBy: []
  timestamp: '2021-01-03 18:28:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Kruskal.cpp
layout: document
redirect_from:
- /library/Graph/Kruskal.cpp
- /library/Graph/Kruskal.cpp.html
title: Graph/Kruskal.cpp
---