---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/BellmanFord.cpp
    title: Bellman-Ford
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"Test/AOJ/BellmanFord.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Other/Template.cpp\"\
    \nconstexpr int Inf = 2000000030;\nconstexpr long long INF= 2000000000000000000;\n\
    \ntemplate<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return\
    \ true; } return false; }\ntemplate<typename T> inline bool chmin(T &a, T b) {\
    \ if (a > b) { a = b; return true; } return false; }\n#line 1 \"Graph/BellmanFord.cpp\"\
    \nstruct edge{\n    int from,to;\n    long long cost;\n};\n\nvector<long long>\
    \ BellmanFord(const int& N,const int& M,const vector<edge>& es,const int& s) {\n\
    \    vector<long long> dist(N,INF);\n    dist[s] = 0;\n\n    for(int i = 0;i <\
    \ N * 2;i++) {\n        for(const auto& [from,to,cost]:es) {\n            if(dist[from]\
    \ < INF && dist[from] + cost < dist[to])  {\n                if(i >= N - 1) dist[to]\
    \ = -INF;\n                else dist[to] = dist[from] + cost;\n            }\n\
    \        }\n    }\n\n    return dist;\n}\n\nbool FindNegativeLoop(const int& N,const\
    \ int& M,const vector<edge>& es) {\n    vector<long long> dist(N);\n\n    for(int\
    \ i = 0;i < N;i++) {\n        for(const auto& [from,to,cost]:es) {\n         \
    \   if(chmin(dist[to],dist[from] + cost) && i == N - 1) return true;\n       \
    \ }\n    }\n\n    return false;\n}\n#line 8 \"Test/AOJ/BellmanFord.test.cpp\"\n\
    \nint main() {\n    int N,M,r;\n    cin >> N >> M >> r;\n    vector<edge> es(M);\n\
    \    for(int i = 0;i < M;i++) {\n        int s,t;\n        long long d;\n    \
    \    cin >> s >> t >> d;\n        es[i] = {s,t,d};\n    }\n    vector<ll> dist\
    \ = BellmanFord(N,M,es,r);\n    bool isnegative = false;\n    for(int i = 0;i\
    \ < N;i++) {\n        if(dist[i] == -INF) isnegative = true;\n    }\n    if(isnegative)\
    \ {\n        cout << \"NEGATIVE CYCLE\" << endl;\n        return 0;\n    }\n \
    \   for(int i = 0;i < N;i++) {\n        if(dist[i] == INF) cout << \"INF\" <<\
    \ endl;\n        else cout << dist[i] << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../Graph/BellmanFord.cpp\"\n\nint main() {\n    int N,M,r;\n  \
    \  cin >> N >> M >> r;\n    vector<edge> es(M);\n    for(int i = 0;i < M;i++)\
    \ {\n        int s,t;\n        long long d;\n        cin >> s >> t >> d;\n   \
    \     es[i] = {s,t,d};\n    }\n    vector<ll> dist = BellmanFord(N,M,es,r);\n\
    \    bool isnegative = false;\n    for(int i = 0;i < N;i++) {\n        if(dist[i]\
    \ == -INF) isnegative = true;\n    }\n    if(isnegative) {\n        cout << \"\
    NEGATIVE CYCLE\" << endl;\n        return 0;\n    }\n    for(int i = 0;i < N;i++)\
    \ {\n        if(dist[i] == INF) cout << \"INF\" << endl;\n        else cout <<\
    \ dist[i] << endl;\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - Graph/BellmanFord.cpp
  isVerificationFile: true
  path: Test/AOJ/BellmanFord.test.cpp
  requiredBy: []
  timestamp: '2021-06-18 21:14:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/AOJ/BellmanFord.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/BellmanFord.test.cpp
- /verify/Test/AOJ/BellmanFord.test.cpp.html
title: Test/AOJ/BellmanFord.test.cpp
---
