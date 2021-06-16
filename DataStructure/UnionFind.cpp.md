---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/Kruskal.cpp
    title: Graph/Kruskal.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/Kruskal.test.cpp
    title: Test/AOJ/Kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-judge/UnionFind.test.cpp
    title: Test/yosupo-judge/UnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ x) {\n        return siz[find(x)];\n    }\n};\n"
  code: "class UnionFind {\n    vector<int> par;\n    vector<int> siz;\n\npublic:\n\
    \n    UnionFind(int n) {\n        par.resize(n);\n        siz.resize(n);\n   \
    \     for(int i = 0;i < n;i++) {\n            par[i] = i;\n            siz[i]\
    \ = 1;\n        }\n    }\n\n    int find(int x) {\n        if(par[x] == x) {\n\
    \            return x;\n        }\n        else {\n            return par[x] =\
    \ find(par[x]);\n        }\n    }\n\n    void unite(int x,int y) {\n        x\
    \ = find(x);\n        y = find(y);\n        if(x == y) {\n            return;\n\
    \        }\n        if(siz[x] < siz[y]) {\n            swap(x,y);\n        }\n\
    \        par[y] = x;\n        siz[x] += siz[y];\n    }\n\n    bool same(int x,int\
    \ y) {\n        return find(x) == find(y);\n    }\n\n    int size(int x) {\n \
    \       return siz[find(x)];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.cpp
  requiredBy:
  - Graph/Kruskal.cpp
  timestamp: '2021-06-16 19:56:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-judge/UnionFind.test.cpp
  - Test/AOJ/Kruskal.test.cpp
documentation_of: DataStructure/UnionFind.cpp
layout: document
title: Union-Find
---

## 説明

別名 Disjoint Set Union 。2つの要素が含まれている集合の併合や、2つの要素が同じ集合に含まれているかの判定などが高速に出来る。実装には根つき木を利用している。

- `UnionFind uf(int n)` : それぞれの要素数が 1 である n 個の集合を生成する。
- `int uf.find(int x)` : `x`が属する集合を表す根つき木の頂点を返す。計算量 $O(\alpha(n))$
- `void unite(int x,int y)` : `x`が属する集合と`y`が属する集合を併合する。計算量 $O(\alpha(n))$
- `bool same(int x,int y)` : `x`と`y`が同じ集合に属しているかを判定する。計算量 $O(\alpha(n))$
- `int size(int x)` : `x`が属している集合の要素数を返す。計算量 $O(\alpha(n))$

※ $\alpha(n)$ はアッカーマン関数の逆関数を表す。実用上は定数と見なせる。
