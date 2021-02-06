---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/BellmanFord.cpp
    title: Graph/BellmanFord.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"Test/AOJ/BellmanFord.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
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
    \ - 1,M);\n    }\n    return N * RS(N, P-1, M) % M;\n}\n#line 1 \"Graph/BellmanFord.cpp\"\
    \n//\u9802\u70B9from\u304B\u3089\u9802\u70B9to\u3078\u306E\u30B3\u30B9\u30C8cost\u306E\
    \u8FBA\nstruct edge{\n    int from,to;\n    ll cost;\n};\n\nedge es[3010]; //\u8FBA\
    \nll dist[3010]; //\u6700\u77ED\u8DDD\u96E2\nint N,M; //\u9802\u70B9\u6570\u3001\
    \u8FBA\u6570\n\n//s\u756A\u76EE\u306E\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\
    \u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\uFF08\u305F\u3060\
    \u3057s\u756A\u76EE\u306E\u9802\u70B9\u304B\u3089\u8CA0\u9589\u8DEF\u3092\u8FBF\
    \u3063\u3066\u884C\u3051\u308B\u5834\u5408\u306F-INF\uFF09\nvoid BellmanFord(int\
    \ s) {\n    for(int i = 0;i < N;i++) {\n        dist[i] = INF;\n    }\n    dist[s]\
    \ = 0;\n    for(int i = 0;i < N * 2;i++) {\n        for(auto e:es) {\n       \
    \     if(dist[e.from] < INF && dist[e.from] + e.cost < dist[e.to])  {\n      \
    \          if(i >= N - 1) {\n                    dist[e.to] = -INF;\n        \
    \        }\n                else {\n                    dist[e.to] = dist[e.from]\
    \ + e.cost;\n                }\n            }\n        }\n    }\n}\n\n//true\u306A\
    \u3089\u8CA0\u306E\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\nbool find_negative_roop()\
    \ {\n    memset(dist,0,sizeof(dist));\n    for(int i = 0;i < N;i++) {\n      \
    \  for(int j = 0;j < M;j++) {\n            edge e = es[j];\n            if(dist[e.to]\
    \ > dist[e.from] + e.cost) {\n                dist[e.to] = dist[e.from] + e.cost;\n\
    \                if(i == N - 1) return true;\n            }\n        }\n    }\n\
    \    return false;\n}\n#line 8 \"Test/AOJ/BellmanFord.test.cpp\"\n\nint main()\
    \ {\n    cin >> N >> M;\n    int r;\n    cin >> r;\n    for(int i = 0;i < M;i++)\
    \ {\n        int s,t;\n        ll d;\n        cin >> s >> t >> d;\n        es[i]\
    \ = (edge{s,t,d});\n    }\n    BellmanFord(r);\n    bool isnegative = false;\n\
    \    for(int i = 0;i < N;i++) {\n        if(dist[i] == -INF) isnegative = true;\n\
    \    }\n    if(isnegative) {\n        cout << \"NEGATIVE CYCLE\" << endl;\n  \
    \      return 0;\n    }\n    for(int i = 0;i < N;i++) {\n        if(dist[i] ==\
    \ INF) cout << \"INF\" << endl;\n        else cout << dist[i] << endl;\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../Graph/BellmanFord.cpp\"\n\nint main() {\n    cin >> N >> M;\n\
    \    int r;\n    cin >> r;\n    for(int i = 0;i < M;i++) {\n        int s,t;\n\
    \        ll d;\n        cin >> s >> t >> d;\n        es[i] = (edge{s,t,d});\n\
    \    }\n    BellmanFord(r);\n    bool isnegative = false;\n    for(int i = 0;i\
    \ < N;i++) {\n        if(dist[i] == -INF) isnegative = true;\n    }\n    if(isnegative)\
    \ {\n        cout << \"NEGATIVE CYCLE\" << endl;\n        return 0;\n    }\n \
    \   for(int i = 0;i < N;i++) {\n        if(dist[i] == INF) cout << \"INF\" <<\
    \ endl;\n        else cout << dist[i] << endl;\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - Graph/BellmanFord.cpp
  isVerificationFile: true
  path: Test/AOJ/BellmanFord.test.cpp
  requiredBy: []
  timestamp: '2021-02-06 17:01:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/BellmanFord.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/BellmanFord.test.cpp
- /verify/Test/AOJ/BellmanFord.test.cpp.html
title: Test/AOJ/BellmanFord.test.cpp
---
