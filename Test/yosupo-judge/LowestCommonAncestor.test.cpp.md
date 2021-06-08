---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/LowestCommonAncestor.cpp
    title: Graph/LowestCommonAncestor.cpp
  - icon: ':question:'
    path: Other/Template.cpp
    title: Other/Template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"Test/yosupo-judge/LowestCommonAncestor.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"Other/Template.cpp\"\ntypedef long long ll;\n\
    \ntemplate<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return\
    \ true; } return false; }\ntemplate<typename T> inline bool chmin(T &a, T b) {\
    \ if (a > b) { a = b; return true; } return false; }\n\ntemplate<typename T>\n\
    T modpow(T N, T P, T M){\n    if(P == 0) return 1;\n    if(P < 0) return 0;\n\
    \    if(P % 2 == 0){\n        T t = modpow(N, P/2, M);\n        if(M == -1) return\
    \ t * t;\n        return t * t % M;\n    }\n    if(M == -1) return N * modpow(N,P\
    \ - 1,M);\n    return N * modpow(N, P-1, M) % M;\n}\n#line 1 \"Graph/LowestCommonAncestor.cpp\"\
    \nint N;\nvector<int> graph[500010];\n\nint root = 0;\n\nint parent[50][500010];\n\
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
    \        }\n    }\n    return parent[0][u];\n}\n#line 8 \"Test/yosupo-judge/LowestCommonAncestor.test.cpp\"\
    \n\nint main() {\n    cin >> N;\n    int Q;\n    cin >> Q;\n    for(int i = 0;i\
    \ < N - 1;i++) {\n        int p;\n        cin >> p;\n        graph[i + 1].push_back(p);\n\
    \        graph[p].push_back(i + 1);\n    }\n    init(N);\n    for(int i = 0;i\
    \ < Q;i++) {\n        int u,v;\n        cin >> u >> v;\n        cout << LCA(u,v)\
    \ << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#include\"../../Other/Template.cpp\"\n#include\"../../Graph/LowestCommonAncestor.cpp\"\
    \n\nint main() {\n    cin >> N;\n    int Q;\n    cin >> Q;\n    for(int i = 0;i\
    \ < N - 1;i++) {\n        int p;\n        cin >> p;\n        graph[i + 1].push_back(p);\n\
    \        graph[p].push_back(i + 1);\n    }\n    init(N);\n    for(int i = 0;i\
    \ < Q;i++) {\n        int u,v;\n        cin >> u >> v;\n        cout << LCA(u,v)\
    \ << endl;\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - Graph/LowestCommonAncestor.cpp
  isVerificationFile: true
  path: Test/yosupo-judge/LowestCommonAncestor.test.cpp
  requiredBy: []
  timestamp: '2021-06-08 16:42:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-judge/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-judge/LowestCommonAncestor.test.cpp
- /verify/Test/yosupo-judge/LowestCommonAncestor.test.cpp.html
title: Test/yosupo-judge/LowestCommonAncestor.test.cpp
---
