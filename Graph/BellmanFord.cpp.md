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
  bundledCode: "#line 1 \"Graph/BellmanFord.cpp\"\n//\u9802\u70B9from\u304B\u3089\u9802\
    \u70B9to\u3078\u306E\u30B3\u30B9\u30C8cost\u306E\u8FBA\nstruct edge{\n    int\
    \ from,to;\n    ll cost;\n};\n\nint N,M; //\u9802\u70B9\u6570\u3001\u8FBA\u6570\
    \nvector<edge> es; //\u8FBA\n\nvector<ll> BellmanFord(int s) {\n    vector<ll>\
    \ dist(N,INF);\n    dist[s] = 0;\n\n    for(int i = 0;i < N * 2;i++) {\n     \
    \   for(const auto& [from,to,cost]:es) {\n            if(dist[from] < INF && dist[from]\
    \ + cost < dist[to])  {\n                if(i >= N - 1) dist[to] = -INF;\n   \
    \             else dist[to] = dist[from] + cost;\n            }\n        }\n \
    \   }\n\n    return dist;\n}\n\n//true\u306A\u3089\u8CA0\u306E\u9589\u8DEF\u304C\
    \u5B58\u5728\u3059\u308B\nbool FindNegativeLoop() {\n    vector<ll> dist(N);\n\
    \    for(int i = 0;i < N;i++) {\n        for(const auto& [from,to,cost]:es) {\n\
    \            if(chmin(dist[to],dist[from] + cost) && i == N - 1) return true;\n\
    \        }\n    }\n    return false;\n}\n"
  code: "//\u9802\u70B9from\u304B\u3089\u9802\u70B9to\u3078\u306E\u30B3\u30B9\u30C8\
    cost\u306E\u8FBA\nstruct edge{\n    int from,to;\n    ll cost;\n};\n\nint N,M;\
    \ //\u9802\u70B9\u6570\u3001\u8FBA\u6570\nvector<edge> es; //\u8FBA\n\nvector<ll>\
    \ BellmanFord(int s) {\n    vector<ll> dist(N,INF);\n    dist[s] = 0;\n\n    for(int\
    \ i = 0;i < N * 2;i++) {\n        for(const auto& [from,to,cost]:es) {\n     \
    \       if(dist[from] < INF && dist[from] + cost < dist[to])  {\n            \
    \    if(i >= N - 1) dist[to] = -INF;\n                else dist[to] = dist[from]\
    \ + cost;\n            }\n        }\n    }\n\n    return dist;\n}\n\n//true\u306A\
    \u3089\u8CA0\u306E\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\nbool FindNegativeLoop()\
    \ {\n    vector<ll> dist(N);\n    for(int i = 0;i < N;i++) {\n        for(const\
    \ auto& [from,to,cost]:es) {\n            if(chmin(dist[to],dist[from] + cost)\
    \ && i == N - 1) return true;\n        }\n    }\n    return false;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BellmanFord.cpp
  requiredBy: []
  timestamp: '2021-06-14 21:31:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/BellmanFord.test.cpp
documentation_of: Graph/BellmanFord.cpp
layout: document
title: Bellman-Ford
---

## 説明

重み付き（有向）グラフにおける最短経路問題を解くアルゴリズム。グラフの辺の重みは負になってもよい。また負閉路（重みの総和が負になる閉路）の検出も可能。

- `int N,M` : $N$ はグラフの頂点の数、 $M$ はグラフの辺の数。
- `vector<edge> es` : グラフの辺の情報。`edge` は `int to,long long cost` で構成される。
- `vector<long long> BellmanFord(int s)` : 頂点`s`から全頂点の最短距離を求める。`s` からのパスが存在しない場合は `INF` を、負閉路の影響で最短距離が求まらない場合は `-INF` が返り値の配列に格納される。計算量 $O(NM)$
- `bool FindNegativeLoop()` : グラフに負閉路が含まれているかどうかを確かめる。計算量 $O(NM)$
