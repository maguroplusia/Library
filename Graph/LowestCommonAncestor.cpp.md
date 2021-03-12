---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-judge/LowestCommonAncestor.test.cpp
    title: Test/yosupo-judge/LowestCommonAncestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/LowestCommonAncestor.cpp\"\nint N;\nvector<int> graph[500010];\n\
    \nint root = 0;\n\nint parent[50][500010];\nint depth[500010];\n\nvoid dfs(int\
    \ v,int p,int d) {\n    parent[0][v] = p;\n    depth[v] = d;\n    for(int i =\
    \ 0;i < graph[v].size();i++) {\n        if(graph[v][i] != p) {\n            dfs(graph[v][i],v,d\
    \ + 1);\n        }\n    }\n}\n\nvoid init(int V) {\n    dfs(root,-1,0);\n    for(int\
    \ k = 0;k + 1 < 50;k++) {\n        for(int v = 0;v < V;v++) {\n            if(parent[k][v]\
    \ < 0) {\n                parent[k + 1][v] = -1;\n            }\n            else\
    \ {\n                parent[k + 1][v] = parent[k][parent[k][v]];\n           \
    \ }\n        }\n    }\n}\n\nint LCA(int u,int v) {\n    if(depth[u] > depth[v])\
    \ {\n        swap(u,v);\n    }\n    for(int k = 0;k < 50;k++) {\n        if((depth[v]\
    \ - depth[u]) >> k & 1) {\n            v = parent[k][v];\n        }\n    }\n \
    \   if(u == v) return u;\n    for(int k = 49;k >= 0;k--) {\n        if(parent[k][u]\
    \ != parent[k][v]) {\n            u = parent[k][u];\n            v = parent[k][v];\n\
    \        }\n    }\n    return parent[0][u];\n}\n"
  code: "int N;\nvector<int> graph[500010];\n\nint root = 0;\n\nint parent[50][500010];\n\
    int depth[500010];\n\nvoid dfs(int v,int p,int d) {\n    parent[0][v] = p;\n \
    \   depth[v] = d;\n    for(int i = 0;i < graph[v].size();i++) {\n        if(graph[v][i]\
    \ != p) {\n            dfs(graph[v][i],v,d + 1);\n        }\n    }\n}\n\nvoid\
    \ init(int V) {\n    dfs(root,-1,0);\n    for(int k = 0;k + 1 < 50;k++) {\n  \
    \      for(int v = 0;v < V;v++) {\n            if(parent[k][v] < 0) {\n      \
    \          parent[k + 1][v] = -1;\n            }\n            else {\n       \
    \         parent[k + 1][v] = parent[k][parent[k][v]];\n            }\n       \
    \ }\n    }\n}\n\nint LCA(int u,int v) {\n    if(depth[u] > depth[v]) {\n     \
    \   swap(u,v);\n    }\n    for(int k = 0;k < 50;k++) {\n        if((depth[v] -\
    \ depth[u]) >> k & 1) {\n            v = parent[k][v];\n        }\n    }\n   \
    \ if(u == v) return u;\n    for(int k = 49;k >= 0;k--) {\n        if(parent[k][u]\
    \ != parent[k][v]) {\n            u = parent[k][u];\n            v = parent[k][v];\n\
    \        }\n    }\n    return parent[0][u];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/LowestCommonAncestor.cpp
  requiredBy: []
  timestamp: '2021-03-12 21:55:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-judge/LowestCommonAncestor.test.cpp
documentation_of: Graph/LowestCommonAncestor.cpp
layout: document
redirect_from:
- /library/Graph/LowestCommonAncestor.cpp
- /library/Graph/LowestCommonAncestor.cpp.html
title: Graph/LowestCommonAncestor.cpp
---
