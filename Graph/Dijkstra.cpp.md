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
  bundledCode: "#line 1 \"Graph/Dijkstra.cpp\"\nstruct edge{\n    int to;\n    ll\
    \ cost;\n};\n\nint N;\nvector<edge> graph[200010];\nvector<ll> dist;\nvector<int>\
    \ pre;\n\nvoid Dijkstra(int s) {\n    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>\
    \ que;\n    dist = vector<ll>(N,INF);\n    pre = vector<int>(N,-1);\n    dist[s]\
    \ = 0;\n    que.push({0,s});\n\n    while(!que.empty()) {\n        auto [cost,v]\
    \ = que.top();\n        que.pop();\n        if(dist[v] < cost) continue;\n   \
    \     for(const auto& [to,d]:graph[v]) {\n            if(chmin(dist[to],dist[v]\
    \ + d)) {\n                pre[to] = v;\n                que.push({dist[to],to});\n\
    \            }\n        }\n    }\n}\n\nvector<int> GetPath(int t) {\n    vector<int>\
    \ path;\n    while(t != -1) {\n        path.push_back(t);\n        t = pre[t];\n\
    \    }\n    reverse(path.begin(),path.end());\n    return path;\n}\n"
  code: "struct edge{\n    int to;\n    ll cost;\n};\n\nint N;\nvector<edge> graph[200010];\n\
    vector<ll> dist;\nvector<int> pre;\n\nvoid Dijkstra(int s) {\n    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>\
    \ que;\n    dist = vector<ll>(N,INF);\n    pre = vector<int>(N,-1);\n    dist[s]\
    \ = 0;\n    que.push({0,s});\n\n    while(!que.empty()) {\n        auto [cost,v]\
    \ = que.top();\n        que.pop();\n        if(dist[v] < cost) continue;\n   \
    \     for(const auto& [to,d]:graph[v]) {\n            if(chmin(dist[to],dist[v]\
    \ + d)) {\n                pre[to] = v;\n                que.push({dist[to],to});\n\
    \            }\n        }\n    }\n}\n\nvector<int> GetPath(int t) {\n    vector<int>\
    \ path;\n    while(t != -1) {\n        path.push_back(t);\n        t = pre[t];\n\
    \    }\n    reverse(path.begin(),path.end());\n    return path;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2021-06-14 22:10:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/Dijkstra.test.cpp
documentation_of: Graph/Dijkstra.cpp
layout: document
redirect_from:
- /library/Graph/Dijkstra.cpp
- /library/Graph/Dijkstra.cpp.html
title: Graph/Dijkstra.cpp
---
