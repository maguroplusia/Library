---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/WarshallFloyd.cpp
    title: Graph/WarshallFloyd.cpp
  - icon: ':heavy_check_mark:'
    path: Other/Template.cpp
    title: Other/Template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"Test/AOJ/WarshallFloyd.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Other/Template.cpp\"\
    \ntypedef long long ll;\nconstexpr int Inf = 1000000030;\nconstexpr ll INF= 2000000000000000000;\n\
    constexpr ll MOD = 1000000007;\nconst double PI = 3.1415926535897;\ntypedef pair<ll,ll>\
    \ P;\ntypedef pair<ll,P> PP;\n\ntemplate<class T> inline bool chmax(T &a, T b)\
    \ {\n    if (a < b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n\
    }\n\ntemplate<class T> inline bool chmin(T &a, T b) {\n    if (a > b) {\n    \
    \    a = b;\n        return 1;\n    }\n    return 0;\n}\n\n\nll mod(ll val, ll\
    \ M) {\n    val = val % M;\n    if(val < 0) {\n        val += M;\n    }\n    return\
    \ val;\n}\n\ntemplate<typename T>\nT RS(T N, T P, T M){\n    if(P == 0) {\n  \
    \      return 1;\n    }\n    if(P < 0) {\n        return 0;\n    }\n    if(P %\
    \ 2 == 0){\n        ll t = RS(N, P/2, M);\n        if(M == -1) return t * t;\n\
    \        return t * t % M;\n    }\n    if(M == -1) {\n        return N * RS(N,P\
    \ - 1,M);\n    }\n    return N * RS(N, P-1, M) % M;\n}\n#line 1 \"Graph/WarshallFloyd.cpp\"\
    \nint N; //\u9802\u70B9\u6570\nll dist[500][500]; //d[u][v]\u306F\u8FBAe=(u,v)\u306E\
    \u30B3\u30B9\u30C8\uFF08\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306FINF\u3001\
    \u305F\u3060\u3057d[i][i]=0\u3068\u3059\u308B\uFF09\n\nvoid init() {\n    for(int\
    \ i = 0;i < 500;i++) {\n        for(int j = 0;j < 500;j++) {\n            if(i\
    \ == j) {\n                dist[i][j] = 0;\n            }\n            else {\n\
    \                dist[i][j] = INF;\n            }\n        }\n    }\n}\n\nvoid\
    \ WarshallFloyd() {\n    for(int k = 0;k < N;k++) {\n        for(int i = 0;i <\
    \ N;i++) {\n            for(int j = 0;j < N;j++) {\n                if(dist[i][k]\
    \ != INF && dist[k][j] != INF) {\n                    chmin(dist[i][j],dist[i][k]\
    \ + dist[k][j]);\n                }\n            }\n        }\n    }\n}\n#line\
    \ 8 \"Test/AOJ/WarshallFloyd.test.cpp\"\n\nint main() {\n    cin >> N;\n    int\
    \ M;\n    cin >> M;\n    init();\n    for(int i = 0;i < M;i++) {\n        int\
    \ s,t;\n        ll d;\n        cin >> s >> t >> d;\n        dist[s][t] = d;\n\
    \    }\n    WarshallFloyd();\n    bool isnegative = false;\n    for(int i = 0;i\
    \ < N;i++) {\n        if(dist[i][i] < 0) isnegative = true;\n    }\n    if(isnegative)\
    \ {\n        cout << \"NEGATIVE CYCLE\" << endl;\n        return 0;\n    }\n \
    \   for(int i = 0;i < N;i++) {\n        for(int j = 0;j < N;j++) {\n         \
    \   if(dist[i][j] == INF) cout << \"INF\";\n            else cout << dist[i][j];\n\
    \            if(j != N - 1) cout << \" \";\n        }\n        cout << endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../Graph/WarshallFloyd.cpp\"\n\nint main() {\n    cin >> N;\n \
    \   int M;\n    cin >> M;\n    init();\n    for(int i = 0;i < M;i++) {\n     \
    \   int s,t;\n        ll d;\n        cin >> s >> t >> d;\n        dist[s][t] =\
    \ d;\n    }\n    WarshallFloyd();\n    bool isnegative = false;\n    for(int i\
    \ = 0;i < N;i++) {\n        if(dist[i][i] < 0) isnegative = true;\n    }\n   \
    \ if(isnegative) {\n        cout << \"NEGATIVE CYCLE\" << endl;\n        return\
    \ 0;\n    }\n    for(int i = 0;i < N;i++) {\n        for(int j = 0;j < N;j++)\
    \ {\n            if(dist[i][j] == INF) cout << \"INF\";\n            else cout\
    \ << dist[i][j];\n            if(j != N - 1) cout << \" \";\n        }\n     \
    \   cout << endl;\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - Graph/WarshallFloyd.cpp
  isVerificationFile: true
  path: Test/AOJ/WarshallFloyd.test.cpp
  requiredBy: []
  timestamp: '2021-02-06 17:01:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/WarshallFloyd.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/WarshallFloyd.test.cpp
- /verify/Test/AOJ/WarshallFloyd.test.cpp.html
title: Test/AOJ/WarshallFloyd.test.cpp
---