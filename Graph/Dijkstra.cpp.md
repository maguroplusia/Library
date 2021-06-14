---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/AOJ/Dijkstra.test.cpp
    title: Test/AOJ/Dijkstra.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/Dijkstra.cpp\"\nstruct edge{\n    int to;\n    ll\
    \ cost;\n};\n\nint N; //\u9802\u70B9\u6570\nvector<edge> graph[200010];\nvector<ll>\
    \ dist; //\u9802\u70B9s\u304B\u3089\u306E\u6700\u77ED\u8DDD\u96E2\nvector<int>\
    \ pre;\n\nvoid Dijkstra(int s) {\n    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>\
    \ que;\n    dist = vector<ll>(N,INF);\n    pre = vector<int>(N,-1);\n    dist[s]\
    \ = 0;\n    que.push({0,s});\n\n    while(!que.empty()) {\n        auto [cost,v]\
    \ = que.top();\n        que.pop();\n        if(dist[v] < cost) continue;\n   \
    \     for(const auto& [d,to]:graph[v]) {\n            if(chmin(dist[to],dist[v]\
    \ + d)) {\n                pre[to] = v;\n                que.push({dist[to],to});\n\
    \            }\n        }\n    }\n}\n\n//\u6700\u77ED\u8DEF\u3092\u53D6\u5F97\n\
    vector<int> get_path(int t) {\n    vector<int> path;\n    while(t != -1) {\n \
    \       path.push_back(t);\n        t = pre[t];\n    }\n    reverse(path.begin(),path.end());\n\
    \    return path;\n}\n"
  code: "struct edge{\n    int to;\n    ll cost;\n};\n\nint N; //\u9802\u70B9\u6570\
    \nvector<edge> graph[200010];\nvector<ll> dist; //\u9802\u70B9s\u304B\u3089\u306E\
    \u6700\u77ED\u8DDD\u96E2\nvector<int> pre;\n\nvoid Dijkstra(int s) {\n    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>\
    \ que;\n    dist = vector<ll>(N,INF);\n    pre = vector<int>(N,-1);\n    dist[s]\
    \ = 0;\n    que.push({0,s});\n\n    while(!que.empty()) {\n        auto [cost,v]\
    \ = que.top();\n        que.pop();\n        if(dist[v] < cost) continue;\n   \
    \     for(const auto& [d,to]:graph[v]) {\n            if(chmin(dist[to],dist[v]\
    \ + d)) {\n                pre[to] = v;\n                que.push({dist[to],to});\n\
    \            }\n        }\n    }\n}\n\n//\u6700\u77ED\u8DEF\u3092\u53D6\u5F97\n\
    vector<int> get_path(int t) {\n    vector<int> path;\n    while(t != -1) {\n \
    \       path.push_back(t);\n        t = pre[t];\n    }\n    reverse(path.begin(),path.end());\n\
    \    return path;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2021-06-14 18:10:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/AOJ/Dijkstra.test.cpp
documentation_of: Graph/Dijkstra.cpp
layout: document
redirect_from:
- /library/Graph/Dijkstra.cpp
- /library/Graph/Dijkstra.cpp.html
title: Graph/Dijkstra.cpp
---
