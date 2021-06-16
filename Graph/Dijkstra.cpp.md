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
  bundledCode: "#line 1 \"Graph/Dijkstra.cpp\"\nstruct edge{\n    int to;\n    long\
    \ long cost;\n};\n\nvector<int> pre;\n\nvector<long long> Dijkstra(const int&\
    \ N,const vector<vector<edge>>& graph,const int& s) {\n    priority_queue<pair<long\
    \ long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> que;\n \
    \   vector<long long> dist(N,INF);\n    pre = vector<int>(N,-1);\n    dist[s]\
    \ = 0;\n    que.push({0,s});\n\n    while(!que.empty()) {\n        auto [cost,v]\
    \ = que.top();\n        que.pop();\n        if(dist[v] < cost) continue;\n   \
    \     for(const auto& [to,d]:graph[v]) {\n            if(chmin(dist[to],dist[v]\
    \ + d)) {\n                pre[to] = v;\n                que.push({dist[to],to});\n\
    \            }\n        }\n    }\n\n    return dist;\n}\n\nvector<int> GetPath(int\
    \ t) {\n    vector<int> path;\n\n    while(t != -1) {\n        path.push_back(t);\n\
    \        t = pre[t];\n    }\n\n    reverse(path.begin(),path.end());\n    return\
    \ path;\n}\n"
  code: "struct edge{\n    int to;\n    long long cost;\n};\n\nvector<int> pre;\n\n\
    vector<long long> Dijkstra(const int& N,const vector<vector<edge>>& graph,const\
    \ int& s) {\n    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long\
    \ long,int>>> que;\n    vector<long long> dist(N,INF);\n    pre = vector<int>(N,-1);\n\
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
  timestamp: '2021-06-16 21:34:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/Dijkstra.test.cpp
documentation_of: Graph/Dijkstra.cpp
layout: document
title: Dijkstra
---

## 説明

重み付き（有向）グラフにおける最短経路問題を解くアルゴリズム。グラフの重みは非負でないといけない。負の重みの辺がある場合は[Bellman-Ford法](https://maguroplusia.github.io/Library/Graph/BellmanFord.cpp)を使う。

- `int N` : グラフの頂点の数
- `vector<vector<edge>> graph` : グラフの情報（隣接リスト）
- 'vector<long long> Dijkstra(int s)' : 頂点`s`から全頂点の最短距離を求める。計算量 $O(E + V \log V)$
- `vector<int> get_path(int t)` : 頂点`s`から頂点`t`までの最短経路の内 $1$ つを列挙する。
