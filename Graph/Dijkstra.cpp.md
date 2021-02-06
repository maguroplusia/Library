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
    \ cost;\n};\n\nint N; //\u9802\u70B9\u6570\nvector<edge> graph[200010];\nll dist[200010];\
    \ //\u9802\u70B9s\u304B\u3089\u306E\u6700\u77ED\u8DDD\u96E2\nint pre[200010];\n\
    \nvoid Dijkstra(int s) {\n    //greater<P>\u3092\u6307\u5B9A\u3059\u308B\u3053\
    \u3068\u3067first\u304C\u5C0F\u3055\u3044\u9806\u306B\u53D6\u308A\u51FA\u305B\u308B\
    \n    priority_queue<P,vector<P>,greater<P>> que;\n    fill(dist,dist + N,INF);\n\
    \    fill(pre,pre + N,-1);\n    dist[s] = 0;\n    que.push(P(0,s));\n\n    while(!que.empty())\
    \ {\n        P p = que.top();\n        que.pop();\n        int v = p.second;\n\
    \        if(dist[v] < p.first) continue;\n        for(auto x:graph[v]) {\n   \
    \         if(chmin(dist[x.to],dist[v] + x.cost)) {\n                pre[x.to]\
    \ = v;\n                que.push(P(dist[x.to],x.to));\n            }\n       \
    \ }\n    }\n}\n\n//\u6700\u77ED\u8DEF\u3092\u53D6\u5F97\nvector<int> get_path(int\
    \ t) {\n    vector<int> path;\n    while(t != -1) {\n        path.push_back(t);\n\
    \        t = pre[t];\n    }\n    reverse(path.begin(),path.end());\n    return\
    \ path;\n}\n"
  code: "struct edge{\n    int to;\n    ll cost;\n};\n\nint N; //\u9802\u70B9\u6570\
    \nvector<edge> graph[200010];\nll dist[200010]; //\u9802\u70B9s\u304B\u3089\u306E\
    \u6700\u77ED\u8DDD\u96E2\nint pre[200010];\n\nvoid Dijkstra(int s) {\n    //greater<P>\u3092\
    \u6307\u5B9A\u3059\u308B\u3053\u3068\u3067first\u304C\u5C0F\u3055\u3044\u9806\u306B\
    \u53D6\u308A\u51FA\u305B\u308B\n    priority_queue<P,vector<P>,greater<P>> que;\n\
    \    fill(dist,dist + N,INF);\n    fill(pre,pre + N,-1);\n    dist[s] = 0;\n \
    \   que.push(P(0,s));\n\n    while(!que.empty()) {\n        P p = que.top();\n\
    \        que.pop();\n        int v = p.second;\n        if(dist[v] < p.first)\
    \ continue;\n        for(auto x:graph[v]) {\n            if(chmin(dist[x.to],dist[v]\
    \ + x.cost)) {\n                pre[x.to] = v;\n                que.push(P(dist[x.to],x.to));\n\
    \            }\n        }\n    }\n}\n\n//\u6700\u77ED\u8DEF\u3092\u53D6\u5F97\n\
    vector<int> get_path(int t) {\n    vector<int> path;\n    while(t != -1) {\n \
    \       path.push_back(t);\n        t = pre[t];\n    }\n    reverse(path.begin(),path.end());\n\
    \    return path;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2021-02-06 17:01:41+09:00'
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
