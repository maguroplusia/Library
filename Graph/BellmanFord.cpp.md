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
  bundledCode: "#line 1 \"Graph/BellmanFord.cpp\"\ntemplate<typename T>\nstruct Edge{\n\
    \    int from,to;\n    T cost;\n};\n\ntemplate<typename T>\nstd::vector<T> bellman_ford(const\
    \ int& node,const int& edge,const std::vector<Edge<T>>& graph,const int& start)\
    \ {\n    std::vector<T> dist(node,std::numeric_limits<T>::max());\n    dist[start]\
    \ = 0;\n\n    for(int i = 0;i < node * 2;i++) {\n        for(const auto& [from,to,cost]:\
    \ graph) {\n            if(dist[from] < std::numeric_limits<T>::max() && dist[from]\
    \ + cost < dist[to])  {\n                if(i >= node - 1) dist[to] = std::numeric_limits<T>::max()\
    \ * static_cast<T>(-1);\n                else dist[to] = dist[from] + cost;\n\
    \            }\n        }\n    }\n\n    return dist;\n}\n\ntemplate<typename T>\n\
    bool find_negative_loop(const int& node,const int& edge,const std::vector<Edge<T>>&\
    \ graph) {\n    std::vector<T> dist(node);\n\n    for(int i = 0;i < node;i++)\
    \ {\n        for(const auto& [from,to,cost]: graph) {\n            if(dist[to]\
    \ > dist[from] + cost && i == node - 1) {\n                return true;\n    \
    \        }\n        }\n    }\n\n    return false;\n}\n"
  code: "template<typename T>\nstruct Edge{\n    int from,to;\n    T cost;\n};\n\n\
    template<typename T>\nstd::vector<T> bellman_ford(const int& node,const int& edge,const\
    \ std::vector<Edge<T>>& graph,const int& start) {\n    std::vector<T> dist(node,std::numeric_limits<T>::max());\n\
    \    dist[start] = 0;\n\n    for(int i = 0;i < node * 2;i++) {\n        for(const\
    \ auto& [from,to,cost]: graph) {\n            if(dist[from] < std::numeric_limits<T>::max()\
    \ && dist[from] + cost < dist[to])  {\n                if(i >= node - 1) dist[to]\
    \ = std::numeric_limits<T>::max() * static_cast<T>(-1);\n                else\
    \ dist[to] = dist[from] + cost;\n            }\n        }\n    }\n\n    return\
    \ dist;\n}\n\ntemplate<typename T>\nbool find_negative_loop(const int& node,const\
    \ int& edge,const std::vector<Edge<T>>& graph) {\n    std::vector<T> dist(node);\n\
    \n    for(int i = 0;i < node;i++) {\n        for(const auto& [from,to,cost]: graph)\
    \ {\n            if(dist[to] > dist[from] + cost && i == node - 1) {\n       \
    \         return true;\n            }\n        }\n    }\n\n    return false;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/BellmanFord.cpp
  requiredBy: []
  timestamp: '2022-03-14 18:12:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/BellmanFord.test.cpp
documentation_of: Graph/BellmanFord.cpp
layout: document
title: Bellman-Ford
---

## 説明

重み付き（有向）グラフにおける最短経路問題を解くアルゴリズム。グラフの辺の重みは負になってもよい。また負閉路（重みの総和が負になる閉路）の検出も可能。

- `vector<T> bellman_ford(int node,int edge,vector<Edge<T>> graph,int start)` : 辺の情報をもった配列 `graph` で表される、頂点数 `node`、変数 `edge` のグラフにおいて、頂点 `start` から各頂点への最短経路を求める。返り値として長さ `node` の配列 `dist` が返される。
    - `dist[i]` = 頂点 `start` から頂点 `i` への最短距離、ただしパスが存在しない場合は `std::numeric_limits<T>::max()` を、負閉路の影響で最短距離が求まらない場合は `-std::numeric_limits<T>::max()` が返り値の配列に格納される。計算量 $O(node \times edge)$
- `bool find_negative_loop(int node,int edge,vector<Edge<T>> graph)` : グラフに負閉路が含まれているかどうかを確かめる。計算量 $O(node \times edge)$
