---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/WarshallFloyd.cpp
    title: Warshall-Floyd
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"Test/AOJ/WarshallFloyd.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Other/Template.cpp\"\
    \ntypedef long long ll;\nconstexpr int Inf = 2000000030;\nconstexpr long long\
    \ INF= 2000000000000000000;\n\ntemplate<typename T> inline bool chmax(T &a, T\
    \ b) { if (a < b) { a = b; return true; } return false; }\ntemplate<typename T>\
    \ inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false;\
    \ }\n#line 1 \"Graph/WarshallFloyd.cpp\"\nvector<vector<long long>> WarshallFloyd(const\
    \ int& N,const vector<vector<long long>> dist) {\n    vector<vector<long long>>\
    \ ret = dist;\n    for(int k = 0;k < N;k++) {\n        for(int i = 0;i < N;i++)\
    \ {\n            for(int j = 0;j < N;j++) {\n                if(ret[i][k] != INF\
    \ && ret[k][j] != INF) {\n                    chmin(ret[i][j],ret[i][k] + ret[k][j]);\n\
    \                }\n            }\n        }\n    }\n    return ret;\n}\n#line\
    \ 8 \"Test/AOJ/WarshallFloyd.test.cpp\"\n\nint main() {\n    int N,M;\n    cin\
    \ >> N >> M;\n    vector<vector<long long>> dist(N,vector<long long>(N));\n  \
    \  for(int i = 0;i < M;i++) {\n        int s,t;\n        long long d;\n      \
    \  cin >> s >> t >> d;\n        dist[s][t] = d;\n    }\n    dist = WarshallFloyd();\n\
    \    bool isnegative = false;\n    for(int i = 0;i < N;i++) {\n        if(dist[i][i]\
    \ < 0) isnegative = true;\n    }\n    if(isnegative) {\n        cout << \"NEGATIVE\
    \ CYCLE\" << endl;\n        return 0;\n    }\n    for(int i = 0;i < N;i++) {\n\
    \        for(int j = 0;j < N;j++) {\n            if(dist[i][j] == INF) cout <<\
    \ \"INF\";\n            else cout << dist[i][j];\n            if(j != N - 1) cout\
    \ << \" \";\n        }\n        cout << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../Graph/WarshallFloyd.cpp\"\n\nint main() {\n    int N,M;\n  \
    \  cin >> N >> M;\n    vector<vector<long long>> dist(N,vector<long long>(N));\n\
    \    for(int i = 0;i < M;i++) {\n        int s,t;\n        long long d;\n    \
    \    cin >> s >> t >> d;\n        dist[s][t] = d;\n    }\n    dist = WarshallFloyd();\n\
    \    bool isnegative = false;\n    for(int i = 0;i < N;i++) {\n        if(dist[i][i]\
    \ < 0) isnegative = true;\n    }\n    if(isnegative) {\n        cout << \"NEGATIVE\
    \ CYCLE\" << endl;\n        return 0;\n    }\n    for(int i = 0;i < N;i++) {\n\
    \        for(int j = 0;j < N;j++) {\n            if(dist[i][j] == INF) cout <<\
    \ \"INF\";\n            else cout << dist[i][j];\n            if(j != N - 1) cout\
    \ << \" \";\n        }\n        cout << endl;\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - Graph/WarshallFloyd.cpp
  isVerificationFile: true
  path: Test/AOJ/WarshallFloyd.test.cpp
  requiredBy: []
  timestamp: '2021-06-18 20:59:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/AOJ/WarshallFloyd.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/WarshallFloyd.test.cpp
- /verify/Test/AOJ/WarshallFloyd.test.cpp.html
title: Test/AOJ/WarshallFloyd.test.cpp
---
