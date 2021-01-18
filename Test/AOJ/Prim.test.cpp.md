---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/Prim.cpp
    title: Graph/Prim.cpp
  - icon: ':question:'
    path: Other/Template.cpp
    title: Other/Template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"Test/AOJ/Prim.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
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
    \ - 1,M);\n    }\n    return N * RS(N, P-1, M) % M;\n}\n#line 1 \"Graph/Prim.cpp\"\
    \nll cost[20010][20010]; // cost[u][v]\u306F\u8FBAe=(u,v)\u306E\u30B3\u30B9\u30C8\
    \nll mincost[20010]; // \u96C6\u5408X\u304B\u3089\u306E\u3078\u8FBA\u306E\u6700\
    \u5C0F\u30B3\u30B9\u30C8\nbool used[20010]; //\u3059\u3067\u306B\u9802\u70B9i\u304C\
    X\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\nint N; //\u9802\u70B9\u306E\
    \u500B\u6570\n\nll prim() {\n    for(int i = 0;i < N;i++) {\n        mincost[i]\
    \ = INF;\n        used[i] = false;\n    }\n    mincost[0] = 0;\n    ll res = 0;\n\
    \    while(true) {\n        int v = -1;\n        //X\u306B\u5C5E\u3055\u306A\u3044\
    \u9802\u70B9\u306E\u3046\u3061X\u304B\u3089\u306E\u8FBA\u306E\u30B3\u30B9\u30C8\
    \u304C\u6700\u5C0F\u306B\u306A\u308B\u9802\u70B9\u3092\u63A2\u3059\n        for(int\
    \ u = 0;u < N;u++) {\n            if(!used[u] && (v == -1 || mincost[u] < mincost[v]))\
    \ {\n                v = u;\n            }\n        }\n        if(v == -1) {\n\
    \            break;\n        }\n        used[v] = true; //\u9802\u70B9v\u3092\
    X\u306B\u8FFD\u52A0\n        res += mincost[v];\n        for(int u = 0;u < V;u++)\
    \ {\n            chmin(mincost[u],mincost[v]);\n        }\n    }\n    return res;\n\
    }\n#line 8 \"Test/AOJ/Prim.test.cpp\"\n\nint main() {\n    cin >> N;\n    int\
    \ M;\n    cin >> M;\n    for(int i = 0;i < M;i++) {\n        int s,t;\n      \
    \  ll w;\n        cin >> s >> t >> w;\n        s--;\n        t--;\n        cost[s][t]\
    \ = w;\n        cost[t][s] = w;\n    }\n    cout << prim() << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../Graph/Prim.cpp\"\n\nint main() {\n    cin >> N;\n    int M;\n\
    \    cin >> M;\n    for(int i = 0;i < M;i++) {\n        int s,t;\n        ll w;\n\
    \        cin >> s >> t >> w;\n        s--;\n        t--;\n        cost[s][t] =\
    \ w;\n        cost[t][s] = w;\n    }\n    cout << prim() << endl;\n}\n"
  dependsOn:
  - Other/Template.cpp
  - Graph/Prim.cpp
  isVerificationFile: true
  path: Test/AOJ/Prim.test.cpp
  requiredBy: []
  timestamp: '2021-01-18 18:22:50+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/AOJ/Prim.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/Prim.test.cpp
- /verify/Test/AOJ/Prim.test.cpp.html
title: Test/AOJ/Prim.test.cpp
---
