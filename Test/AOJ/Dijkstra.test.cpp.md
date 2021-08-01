---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/Dijkstra.cpp
    title: Dijkstra
  - icon: ':question:'
    path: Other/Template.cpp
    title: Other/Template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"Test/AOJ/Dijkstra.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Other/Template.cpp\"\
    \nconstexpr int Inf = 2000000030;\nconstexpr long long INF= 2000000000000000000;\n\
    \ntemplate<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return\
    \ true; } return false; }\ntemplate<typename T> inline bool chmin(T &a, T b) {\
    \ if (a > b) { a = b; return true; } return false; }\n#line 1 \"Graph/Dijkstra.cpp\"\
    \ntemplate<typename T>\nstruct edge {\n    int to;\n    T cost;\n};\n\nvector<int>\
    \ pre;\n\ntemplate<typename T>\nvector<T> Dijkstra(const int& N,const vector<vector<edge<T>>>&\
    \ graph,const int& s) {\n    priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>\
    \ que;\n    vector<T> dist(N,numeric_limits<T>::max());\n    pre = vector<int>(N,-1);\n\
    \    dist[s] = 0;\n    que.push({0,s});\n\n    while(!que.empty()) {\n       \
    \ auto [cost,v] = que.top();\n        que.pop();\n        if(dist[v] < cost) continue;\n\
    \        for(const auto& [to,d]:graph[v]) {\n            if(chmin(dist[to],dist[v]\
    \ + d)) {\n                pre[to] = v;\n                que.push({dist[to],to});\n\
    \            }\n        }\n    }\n\n    return dist;\n}\n\nvector<int> GetPath(cosnt\
    \ int& t) {\n    vector<int> path;\n\n    while(t != -1) {\n        path.push_back(t);\n\
    \        t = pre[t];\n    }\n\n    reverse(path.begin(),path.end());\n    return\
    \ path;\n}\n#line 8 \"Test/AOJ/Dijkstra.test.cpp\"\n\nint main() {\n    int N,M,r;\n\
    \    cin >> N >> M >> r;\n    vector<vector<edge<int>>> graph(N);\n    for(int\
    \ i = 0;i < M;i++) {\n        int s,t,d;\n        cin >> s >> t >> d;\n      \
    \  graph[s].push_back({t,d});\n    }\n    vector<int> dist = Dijkstra(N,graph,r);\n\
    \    for(const auto& x:dist) {\n        if(x == numeric_limits<int>::max()) cout\
    \ << \"INF\" << endl;\n        else cout << x << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../Graph/Dijkstra.cpp\"\n\nint main() {\n    int N,M,r;\n    cin\
    \ >> N >> M >> r;\n    vector<vector<edge<int>>> graph(N);\n    for(int i = 0;i\
    \ < M;i++) {\n        int s,t,d;\n        cin >> s >> t >> d;\n        graph[s].push_back({t,d});\n\
    \    }\n    vector<int> dist = Dijkstra(N,graph,r);\n    for(const auto& x:dist)\
    \ {\n        if(x == numeric_limits<int>::max()) cout << \"INF\" << endl;\n  \
    \      else cout << x << endl;\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - Graph/Dijkstra.cpp
  isVerificationFile: true
  path: Test/AOJ/Dijkstra.test.cpp
  requiredBy: []
  timestamp: '2021-08-01 20:25:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/AOJ/Dijkstra.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/Dijkstra.test.cpp
- /verify/Test/AOJ/Dijkstra.test.cpp.html
title: Test/AOJ/Dijkstra.test.cpp
---
