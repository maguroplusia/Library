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
    constexpr int Inf = 1000000030;\nconstexpr ll INF= 2000000000000000000;\nconstexpr\
    \ ll MOD = 1000000007;\nconst double PI = 3.1415926535897;\ntypedef pair<ll,ll>\
    \ P;\ntypedef pair<ll,P> PP;\n\ntemplate<class T> inline bool chmax(T &a, T b)\
    \ {\n    if (a < b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n\
    }\n\ntemplate<class T> inline bool chmin(T &a, T b) {\n    if (a > b) {\n    \
    \    a = b;\n        return 1;\n    }\n    return 0;\n}\n\n\nll mod(ll val, ll\
    \ M) {\n    val = val % M;\n    if(val < 0) {\n        val += M;\n    }\n    return\
    \ val;\n}\n\ntemplate<typename T>\nT RS(T N, T P, T M){\n    if(P == 0) {\n  \
    \      return 1;\n    }\n    if(P < 0) {\n        return 0;\n    }\n    if(P %\
    \ 2 == 0){\n        ll t = RS(N, P/2, M);\n        if(M == -1) return t * t;\n\
    \        return t * t % M;\n    }\n    if(M == -1) {\n        return N * RS(N,P\
    \ - 1,M);\n    }\n    return N * RS(N, P-1, M) % M;\n}\n#line 1 \"Graph/LowestCommonAncestor.cpp\"\
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
  timestamp: '2021-03-12 21:55:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-judge/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-judge/LowestCommonAncestor.test.cpp
- /verify/Test/yosupo-judge/LowestCommonAncestor.test.cpp.html
title: Test/yosupo-judge/LowestCommonAncestor.test.cpp
---
