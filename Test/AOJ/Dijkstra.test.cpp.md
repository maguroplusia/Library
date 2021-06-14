---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/Dijkstra.cpp
    title: Graph/Dijkstra.cpp
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
    \ntypedef long long ll;\nconstexpr int Inf = 2000000030;\nconstexpr long long\
    \ INF= 2000000000000000000;\n\ntemplate<typename T> inline bool chmax(T &a, T\
    \ b) { if (a < b) { a = b; return true; } return false; }\ntemplate<typename T>\
    \ inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false;\
    \ }\n#line 1 \"Graph/Dijkstra.cpp\"\nstruct edge{\n    int to;\n    ll cost;\n\
    };\n\nint N; //\u9802\u70B9\u6570\nvector<edge> graph[200010];\nvector<ll> dist;\
    \ //\u9802\u70B9s\u304B\u3089\u306E\u6700\u77ED\u8DDD\u96E2\nvector<int> pre;\n\
    \nvoid Dijkstra(int s) {\n    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>\
    \ que;\n    dist = vector<ll>(N,INF);\n    pre = vector<int>(N,-1);\n    dist[s]\
    \ = 0;\n    que.push({0,s});\n\n    while(!que.empty()) {\n        auto [cost,v]\
    \ = que.top();\n        que.pop();\n        if(dist[v] < cost) continue;\n   \
    \     for(const auto& [d,to]:graph[v]) {\n            if(chmin(dist[to],dist[v]\
    \ + d)) {\n                pre[to] = v;\n                que.push({dist[to],to});\n\
    \            }\n        }\n    }\n}\n\n//\u6700\u77ED\u8DEF\u3092\u53D6\u5F97\n\
    vector<int> get_path(int t) {\n    vector<int> path;\n    while(t != -1) {\n \
    \       path.push_back(t);\n        t = pre[t];\n    }\n    reverse(path.begin(),path.end());\n\
    \    return path;\n}\n#line 8 \"Test/AOJ/Dijkstra.test.cpp\"\n\nint main() {\n\
    \    cin >> N;\n    int M,r;\n    cin >> M >> r;\n    for(int i = 0;i < M;i++)\
    \ {\n        int s,t;\n        ll d;\n        cin >> s >> t >> d;\n        graph[s].push_back(edge{t,d});\n\
    \    }\n    Dijkstra(r);\n    for(int i = 0;i < N;i++) {\n        if(dist[i] ==\
    \ INF) cout << \"INF\" << endl;\n        else cout << dist[i] << endl;\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../Graph/Dijkstra.cpp\"\n\nint main() {\n    cin >> N;\n    int\
    \ M,r;\n    cin >> M >> r;\n    for(int i = 0;i < M;i++) {\n        int s,t;\n\
    \        ll d;\n        cin >> s >> t >> d;\n        graph[s].push_back(edge{t,d});\n\
    \    }\n    Dijkstra(r);\n    for(int i = 0;i < N;i++) {\n        if(dist[i] ==\
    \ INF) cout << \"INF\" << endl;\n        else cout << dist[i] << endl;\n    }\n\
    }\n"
  dependsOn:
  - Other/Template.cpp
  - Graph/Dijkstra.cpp
  isVerificationFile: true
  path: Test/AOJ/Dijkstra.test.cpp
  requiredBy: []
  timestamp: '2021-06-14 18:10:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/AOJ/Dijkstra.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/Dijkstra.test.cpp
- /verify/Test/AOJ/Dijkstra.test.cpp.html
title: Test/AOJ/Dijkstra.test.cpp
---
