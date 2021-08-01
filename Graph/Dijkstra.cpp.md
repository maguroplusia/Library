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
  bundledCode: "#line 1 \"Graph/Dijkstra.cpp\"\ntemplate<typename T>\nstruct edge\
    \ {\n    int to;\n    T cost;\n};\n\nvector<int> pre;\n\ntemplate<typename T>\n\
    vector<T> Dijkstra(const int& N,const vector<vector<edge<T>>>& graph,const int&\
    \ s) {\n    priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>\
    \ que;\n    vector<T> dist(N,numeric_limits<T>::max());\n    pre = vector<int>(N,-1);\n\
    \    dist[s] = 0;\n    que.push({0,s});\n\n    while(!que.empty()) {\n       \
    \ auto [cost,v] = que.top();\n        que.pop();\n        if(dist[v] < cost) continue;\n\
    \        for(const auto& [to,d]:graph[v]) {\n            if(chmin(dist[to],dist[v]\
    \ + d)) {\n                pre[to] = v;\n                que.push({dist[to],to});\n\
    \            }\n        }\n    }\n\n    return dist;\n}\n\nvector<int> GetPath(int\
    \ t) {\n    vector<int> path;\n\n    while(t != -1) {\n        path.push_back(t);\n\
    \        t = pre[t];\n    }\n\n    reverse(path.begin(),path.end());\n    return\
    \ path;\n}\n"
  code: "template<typename T>\nstruct edge {\n    int to;\n    T cost;\n};\n\nvector<int>\
    \ pre;\n\ntemplate<typename T>\nvector<T> Dijkstra(const int& N,const vector<vector<edge<T>>>&\
    \ graph,const int& s) {\n    priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>\
    \ que;\n    vector<T> dist(N,numeric_limits<T>::max());\n    pre = vector<int>(N,-1);\n\
    \    dist[s] = 0;\n    que.push({0,s});\n\n    while(!que.empty()) {\n       \
    \ auto [cost,v] = que.top();\n        que.pop();\n        if(dist[v] < cost) continue;\n\
    \        for(const auto& [to,d]:graph[v]) {\n            if(chmin(dist[to],dist[v]\
    \ + d)) {\n                pre[to] = v;\n                que.push({dist[to],to});\n\
    \            }\n        }\n    }\n\n    return dist;\n}\n\nvector<int> GetPath(int\
    \ t) {\n    vector<int> path;\n\n    while(t != -1) {\n        path.push_back(t);\n\
    \        t = pre[t];\n    }\n\n    reverse(path.begin(),path.end());\n    return\
    \ path;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2021-08-01 20:48:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/Dijkstra.test.cpp
documentation_of: Graph/Dijkstra.cpp
layout: document
title: Dijkstra
---

## 説明

重み付き（有向）グラフにおける最短経路問題を解くアルゴリズム。グラフの重みは非負でないといけない。負の重みの辺がある場合は[Bellman-Ford法](https://maguroplusia.github.io/Library/Graph/BellmanFord.cpp)を使う。

- `vector<T> Dijkstra(int N,vector<vector<edge<T>>,int s)` : 頂点`s`から全頂点の最短距離を求める。返り値として長さ`N`の配列`dist`が返される。計算量 $O(E + V \log V)$
    - `s` : グラフの頂点数
    - `graph` : グラフの情報（隣接リスト）
    - `s` : 最短路を求める際の始点
    - `dist[i]` = 頂点`s`から頂点`i`までの最短距離、ただしパスが存在しない場合は`numeric_limits<T>::max()`が格納される
- `vector<int> get_path(int t)` : 頂点`s`から頂点`t`までの最短経路の内 $1$ つを列挙
