---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/BellmanFord.cpp
    title: Bellman-Ford
  - icon: ':question:'
    path: Other/Template.cpp
    title: Other/Template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"Test/AOJ/BellmanFord.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Other/Template.cpp\"\
    \nconstexpr int Inf = 2000000030;\nconstexpr long long INF= 2000000000000000000;\n\
    \ntemplate<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return\
    \ true; } return false; }\ntemplate<typename T> inline bool chmin(T &a, T b) {\
    \ if (a > b) { a = b; return true; } return false; }\n#line 1 \"Graph/BellmanFord.cpp\"\
    \ntemplate<typename T>\nstruct Edge{\n    int from,to;\n    T cost;\n};\n\ntemplate<typename\
    \ T>\nstd::vector<T> bellman_ford(const int& node,const int& edge,const std::vector<Edge<T>>&\
    \ graph,const int& start) {\n    std::vector<T> dist(node,std::numeric_limits<T>::max());\n\
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
    }\n#line 8 \"Test/AOJ/BellmanFord.test.cpp\"\n\nint main() {\n    int N,M,r;\n\
    \    cin >> N >> M >> r;\n    vector<Edge<long long>> es(M);\n    for(int i =\
    \ 0;i < M;i++) {\n        int s,t;\n        long long d;\n        cin >> s >>\
    \ t >> d;\n        es[i] = {s,t,d};\n    }\n    vector<long long> dist = bellman_ford(N,M,es,r);\n\
    \    bool isnegative = false;\n    for(int i = 0;i < N;i++) {\n        if(dist[i]\
    \ == -numeric_limits<long long>::max()) isnegative = true;\n    }\n    if(isnegative)\
    \ {\n        cout << \"NEGATIVE CYCLE\" << endl;\n        return 0;\n    }\n \
    \   for(int i = 0;i < N;i++) {\n        if(dist[i] == numeric_limits<long long>::max())\
    \ cout << \"INF\" << endl;\n        else cout << dist[i] << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../Graph/BellmanFord.cpp\"\n\nint main() {\n    int N,M,r;\n  \
    \  cin >> N >> M >> r;\n    vector<Edge<long long>> es(M);\n    for(int i = 0;i\
    \ < M;i++) {\n        int s,t;\n        long long d;\n        cin >> s >> t >>\
    \ d;\n        es[i] = {s,t,d};\n    }\n    vector<long long> dist = bellman_ford(N,M,es,r);\n\
    \    bool isnegative = false;\n    for(int i = 0;i < N;i++) {\n        if(dist[i]\
    \ == -numeric_limits<long long>::max()) isnegative = true;\n    }\n    if(isnegative)\
    \ {\n        cout << \"NEGATIVE CYCLE\" << endl;\n        return 0;\n    }\n \
    \   for(int i = 0;i < N;i++) {\n        if(dist[i] == numeric_limits<long long>::max())\
    \ cout << \"INF\" << endl;\n        else cout << dist[i] << endl;\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - Graph/BellmanFord.cpp
  isVerificationFile: true
  path: Test/AOJ/BellmanFord.test.cpp
  requiredBy: []
  timestamp: '2022-03-14 20:51:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/BellmanFord.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/BellmanFord.test.cpp
- /verify/Test/AOJ/BellmanFord.test.cpp.html
title: Test/AOJ/BellmanFord.test.cpp
---
