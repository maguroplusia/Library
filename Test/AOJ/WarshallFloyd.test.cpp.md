---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/WarshallFloyd.cpp
    title: Graph/WarshallFloyd.cpp
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
    \ntypedef long long ll;\n\ntemplate<typename T> inline bool chmax(T &a, T b) {\
    \ if (a < b) { a = b; return true; } return false; }\ntemplate<typename T> inline\
    \ bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }\n\
    \ntemplate<typename T>\nT modpow(T N, T P, T M){\n    if(P == 0) return 1;\n \
    \   if(P < 0) return 0;\n    if(P % 2 == 0){\n        T t = modpow(N, P/2, M);\n\
    \        if(M == -1) return t * t;\n        return t * t % M;\n    }\n    if(M\
    \ == -1) return N * modpow(N,P - 1,M);\n    return N * modpow(N, P-1, M) % M;\n\
    }\n#line 1 \"Graph/WarshallFloyd.cpp\"\nint N; //\u9802\u70B9\u6570\nll dist[500][500];\
    \ //d[u][v]\u306F\u8FBAe=(u,v)\u306E\u30B3\u30B9\u30C8\uFF08\u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306FINF\u3001\u305F\u3060\u3057d[i][i]=0\u3068\u3059\
    \u308B\uFF09\n\nvoid init() {\n    for(int i = 0;i < 500;i++) {\n        for(int\
    \ j = 0;j < 500;j++) {\n            if(i == j) {\n                dist[i][j] =\
    \ 0;\n            }\n            else {\n                dist[i][j] = INF;\n \
    \           }\n        }\n    }\n}\n\nvoid WarshallFloyd() {\n    for(int k =\
    \ 0;k < N;k++) {\n        for(int i = 0;i < N;i++) {\n            for(int j =\
    \ 0;j < N;j++) {\n                if(dist[i][k] != INF && dist[k][j] != INF) {\n\
    \                    chmin(dist[i][j],dist[i][k] + dist[k][j]);\n            \
    \    }\n            }\n        }\n    }\n}\n#line 8 \"Test/AOJ/WarshallFloyd.test.cpp\"\
    \n\nint main() {\n    cin >> N;\n    int M;\n    cin >> M;\n    init();\n    for(int\
    \ i = 0;i < M;i++) {\n        int s,t;\n        ll d;\n        cin >> s >> t >>\
    \ d;\n        dist[s][t] = d;\n    }\n    WarshallFloyd();\n    bool isnegative\
    \ = false;\n    for(int i = 0;i < N;i++) {\n        if(dist[i][i] < 0) isnegative\
    \ = true;\n    }\n    if(isnegative) {\n        cout << \"NEGATIVE CYCLE\" <<\
    \ endl;\n        return 0;\n    }\n    for(int i = 0;i < N;i++) {\n        for(int\
    \ j = 0;j < N;j++) {\n            if(dist[i][j] == INF) cout << \"INF\";\n   \
    \         else cout << dist[i][j];\n            if(j != N - 1) cout << \" \";\n\
    \        }\n        cout << endl;\n    }\n}\n"
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
  timestamp: '2021-06-08 16:42:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/AOJ/WarshallFloyd.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/WarshallFloyd.test.cpp
- /verify/Test/AOJ/WarshallFloyd.test.cpp.html
title: Test/AOJ/WarshallFloyd.test.cpp
---
