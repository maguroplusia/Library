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
  bundledCode: "#line 1 \"Graph/WarshallFloyd.cpp\"\nvector<vector<long long>> WarshallFloyd(const\
    \ int& N,const vector<vector<long long>> dist) {\n    vector<vector<long long>>\
    \ ret = dist;\n    for(int k = 0;k < N;k++) {\n        for(int i = 0;i < N;i++)\
    \ {\n            for(int j = 0;j < N;j++) {\n                if(ret[i][k] != INF\
    \ && ret[k][j] != INF) {\n                    chmin(ret[i][j],ret[i][k] + ret[k][j]);\n\
    \                }\n            }\n        }\n    }\n    return ret;\n}\n"
  code: "vector<vector<long long>> WarshallFloyd(const int& N,const vector<vector<long\
    \ long>> dist) {\n    vector<vector<long long>> ret = dist;\n    for(int k = 0;k\
    \ < N;k++) {\n        for(int i = 0;i < N;i++) {\n            for(int j = 0;j\
    \ < N;j++) {\n                if(ret[i][k] != INF && ret[k][j] != INF) {\n   \
    \                 chmin(ret[i][j],ret[i][k] + ret[k][j]);\n                }\n\
    \            }\n        }\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/WarshallFloyd.cpp
  requiredBy: []
  timestamp: '2021-06-18 20:59:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/WarshallFloyd.test.cpp
documentation_of: Graph/WarshallFloyd.cpp
layout: document
title: Warshall-Floyd
---

## 説明
重み付き（有向）グラフにおける全頂点間の最短距離を求める。

- `vector<vector<long long>> WarshallFloyd(int N,vector<vector<long long>> dist)` : `dist[i][j]` = 頂点`i`と頂点`j`を結ぶ辺の距離（ただし`i`と`j`の間に辺が存在しないならば`INF`）である頂点数が`N`のグラフに対して、全頂点間の最短距離を求める。返り値は2次元配列に格納される（ただし頂点間に経路が存在しないならば`INF`）。計算量 $O(N^3)$

tips : このアルゴリズムは負の辺でも動作する。返り値の配列を`ret`とすると、`ret[i][i] < 0`となる`i`が存在するならばグラフには負閉路が含まれている。
