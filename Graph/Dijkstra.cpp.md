---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/Dijkstra.test.cpp
    title: Test/AOJ/Dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/Dijkstra.cpp\"\ntemplate<typename T>\nstruct Edge\
    \ {\n    int to;\n    T cost;\n};\n\nstd::vector<int> pre;\n\ntemplate<typename\
    \ T>\nstd::vector<T> dijkstra(const int& node,const vector<vector<Edge<T>>>& graph,const\
    \ int& start) {\n    std::priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>\
    \ que;\n    vector<T> dist(node,numeric_limits<T>::max());\n    pre = vector<int>(node,-1);\n\
    \    dist[start] = 0;\n    que.push({0,start});\n\n    while(!que.empty()) {\n\
    \        auto [cost,v] = que.top();\n        que.pop();\n        if(dist[v] <\
    \ cost) continue;\n        for(const auto& [to,d]:graph[v]) {\n            if(dist[to]\
    \ > dist[v] + d) {\n                dist[to] = dist[v] + d;\n                pre[to]\
    \ = v;\n                que.push({dist[to],to});\n            }\n        }\n \
    \   }\n\n    return dist;\n}\n\nvector<int> GetPath(int t) {\n    vector<int>\
    \ path;\n\n    while(t != -1) {\n        path.push_back(t);\n        t = pre[t];\n\
    \    }\n\n    reverse(path.begin(),path.end());\n    return path;\n}\n"
  code: "template<typename T>\nstruct Edge {\n    int to;\n    T cost;\n};\n\nstd::vector<int>\
    \ pre;\n\ntemplate<typename T>\nstd::vector<T> dijkstra(const int& node,const\
    \ vector<vector<Edge<T>>>& graph,const int& start) {\n    std::priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>\
    \ que;\n    vector<T> dist(node,numeric_limits<T>::max());\n    pre = vector<int>(node,-1);\n\
    \    dist[start] = 0;\n    que.push({0,start});\n\n    while(!que.empty()) {\n\
    \        auto [cost,v] = que.top();\n        que.pop();\n        if(dist[v] <\
    \ cost) continue;\n        for(const auto& [to,d]:graph[v]) {\n            if(dist[to]\
    \ > dist[v] + d) {\n                dist[to] = dist[v] + d;\n                pre[to]\
    \ = v;\n                que.push({dist[to],to});\n            }\n        }\n \
    \   }\n\n    return dist;\n}\n\nvector<int> GetPath(int t) {\n    vector<int>\
    \ path;\n\n    while(t != -1) {\n        path.push_back(t);\n        t = pre[t];\n\
    \    }\n\n    reverse(path.begin(),path.end());\n    return path;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2022-03-14 18:12:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/Dijkstra.test.cpp
documentation_of: Graph/Dijkstra.cpp
layout: document
title: Dijkstra
---

## 説明

重み付き（有向）グラフにおける最短経路問題を解くアルゴリズム。グラフの重みは非負でないといけない。負の重みの辺がある場合は [Bellman-Ford法](https://maguroplusia.github.io/Library/Graph/BellmanFord.cpp) を使う。

- `vector<T> dijkstra(int node,vector<vector<Edge<T>> graph,int start)` : 隣接リストで表現された `node` 頂点のグラフ `graph` において、頂点 `start` から各頂点への最短距離を求める。返り値として長さ `node` の配列 `dist` が返される。辺の本数を $edge$ とおくと計算量 $O(edge + node \log node)$
    - `dist[i]` = 頂点 `s` から頂点 `i` までの最短距離、ただしパスが存在しない場合は `std::numeric_limits<T>::max()` が格納される
- `vector<int> get_path(int t)` :  頂点 `start` から頂点 `t` までの最短経路の内 1 つを列挙する。計算量 $O(node)$
