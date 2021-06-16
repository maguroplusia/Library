---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/BellmanFord.test.cpp
    title: Test/AOJ/BellmanFord.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/BellmanFord.cpp\"\nstruct edge{\n    int from,to;\n\
    \    long long cost;\n};\n\nvector<long long> BellmanFord(const int& N,const int&\
    \ M,const vector<edge>& es,const int& s) {\n    vector<long long> dist(N,INF);\n\
    \    dist[s] = 0;\n\n    for(int i = 0;i < N * 2;i++) {\n        for(const auto&\
    \ [from,to,cost]:es) {\n            if(dist[from] < INF && dist[from] + cost <\
    \ dist[to])  {\n                if(i >= N - 1) dist[to] = -INF;\n            \
    \    else dist[to] = dist[from] + cost;\n            }\n        }\n    }\n\n \
    \   return dist;\n}\n\nbool FindNegativeLoop(const int& N,const int& M,const vector<edge>&\
    \ es) {\n    vector<long long> dist(N);\n\n    for(int i = 0;i < N;i++) {\n  \
    \      for(const auto& [from,to,cost]:es) {\n            if(chmin(dist[to],dist[from]\
    \ + cost) && i == N - 1) return true;\n        }\n    }\n\n    return false;\n\
    }\n"
  code: "struct edge{\n    int from,to;\n    long long cost;\n};\n\nvector<long long>\
    \ BellmanFord(const int& N,const int& M,const vector<edge>& es,const int& s) {\n\
    \    vector<long long> dist(N,INF);\n    dist[s] = 0;\n\n    for(int i = 0;i <\
    \ N * 2;i++) {\n        for(const auto& [from,to,cost]:es) {\n            if(dist[from]\
    \ < INF && dist[from] + cost < dist[to])  {\n                if(i >= N - 1) dist[to]\
    \ = -INF;\n                else dist[to] = dist[from] + cost;\n            }\n\
    \        }\n    }\n\n    return dist;\n}\n\nbool FindNegativeLoop(const int& N,const\
    \ int& M,const vector<edge>& es) {\n    vector<long long> dist(N);\n\n    for(int\
    \ i = 0;i < N;i++) {\n        for(const auto& [from,to,cost]:es) {\n         \
    \   if(chmin(dist[to],dist[from] + cost) && i == N - 1) return true;\n       \
    \ }\n    }\n\n    return false;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BellmanFord.cpp
  requiredBy: []
  timestamp: '2021-06-16 21:34:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/BellmanFord.test.cpp
documentation_of: Graph/BellmanFord.cpp
layout: document
title: Bellman-Ford
---

## 説明

重み付き（有向）グラフにおける最短経路問題を解くアルゴリズム。グラフの辺の重みは負になってもよい。また負閉路（重みの総和が負になる閉路）の検出も可能。

- `vector<long long> BellmanFord(int N,int M,vector<edge> es,int s)` : `N`頂点`M`辺のグラフ`es`の頂点`s`から全頂点の最短距離を求める。`s` からのパスが存在しない場合は `INF` を、負閉路の影響で最短距離が求まらない場合は `-INF` が返り値の配列に格納される。計算量 $O(NM)$
- `bool FindNegativeLoop(int N,int M,vector<edge> es,int s)` : グラフに負閉路が含まれているかどうかを確かめる。計算量 $O(NM)$
