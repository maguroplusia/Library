---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/UnionFind.cpp
    title: Union-Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/AOJ/Kruskal.test.cpp
    title: Test/AOJ/Kruskal.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/UnionFind.cpp\"\nclass UnionFind {\n    vector<int>\
    \ par;\n    vector<int> siz;\n\npublic:\n\n    UnionFind(int n) {\n        par.resize(n);\n\
    \        siz.resize(n);\n        for(int i = 0;i < n;i++) {\n            par[i]\
    \ = i;\n            siz[i] = 1;\n        }\n    }\n\n    int find(int x) {\n \
    \       if(par[x] == x) {\n            return x;\n        }\n        else {\n\
    \            return par[x] = find(par[x]);\n        }\n    }\n\n    void unite(int\
    \ x,int y) {\n        x = find(x);\n        y = find(y);\n        if(x == y) {\n\
    \            return;\n        }\n        if(siz[x] < siz[y]) {\n            swap(x,y);\n\
    \        }\n        par[y] = x;\n        siz[x] += siz[y];\n    }\n\n    bool\
    \ same(int x,int y) {\n        return find(x) == find(y);\n    }\n\n    int size(int\
    \ x) {\n        return siz[find(x)];\n    }\n};\n#line 2 \"Graph/Kruskal.cpp\"\
    \n\nstruct edge {\n    int u,v;\n    ll cost;\n\n    bool operator<(const edge&\
    \ b) const {\n        return cost < b.cost;\n    }\n};\n\nint N,M;\nedge graph[200010];\n\
    \nll Kruskal() {\n    sort(graph,graph + M);\n    UnionFind uf(N);\n    ll ret\
    \ = 0;\n    for(int i = 0;i < M;i++) {\n        edge e = graph[i];\n        if(!uf.same(e.u,e.v))\
    \ {\n            uf.unite(e.u,e.v);\n            ret += e.cost;\n        }\n \
    \   }\n    return ret;\n}\n"
  code: "#include\"../DataStructure/UnionFind.cpp\"\n\nstruct edge {\n    int u,v;\n\
    \    ll cost;\n\n    bool operator<(const edge& b) const {\n        return cost\
    \ < b.cost;\n    }\n};\n\nint N,M;\nedge graph[200010];\n\nll Kruskal() {\n  \
    \  sort(graph,graph + M);\n    UnionFind uf(N);\n    ll ret = 0;\n    for(int\
    \ i = 0;i < M;i++) {\n        edge e = graph[i];\n        if(!uf.same(e.u,e.v))\
    \ {\n            uf.unite(e.u,e.v);\n            ret += e.cost;\n        }\n \
    \   }\n    return ret;\n}\n"
  dependsOn:
  - DataStructure/UnionFind.cpp
  isVerificationFile: false
  path: Graph/Kruskal.cpp
  requiredBy: []
  timestamp: '2021-06-16 19:56:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/AOJ/Kruskal.test.cpp
documentation_of: Graph/Kruskal.cpp
layout: document
redirect_from:
- /library/Graph/Kruskal.cpp
- /library/Graph/Kruskal.cpp.html
title: Graph/Kruskal.cpp
---
