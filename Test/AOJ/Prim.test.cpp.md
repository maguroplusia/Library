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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A&lang=jp
  bundledCode: "#line 1 \"Test/AOJ/Prim.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A&lang=jp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Other/Template.cpp\"\
    \ntypedef long long ll;\n\ntemplate<typename T> inline bool chmax(T &a, T b) {\
    \ if (a < b) { a = b; return true; } return false; }\ntemplate<typename T> inline\
    \ bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }\n\
    \ntemplate<typename T>\nT modpow(T N, T P, T M){\n    if(P == 0) return 1;\n \
    \   if(P < 0) return 0;\n    if(P % 2 == 0){\n        T t = modpow(N, P/2, M);\n\
    \        if(M == -1) return t * t;\n        return t * t % M;\n    }\n    if(M\
    \ == -1) return N * modpow(N,P - 1,M);\n    return N * modpow(N, P-1, M) % M;\n\
    }\n#line 1 \"Graph/Prim.cpp\"\nll cost[2010][2010]; // cost[u][v]\u306F\u8FBA\
    e=(u,v)\u306E\u30B3\u30B9\u30C8\nll mincost[2010]; // \u96C6\u5408X\u304B\u3089\
    \u306E\u3078\u8FBA\u306E\u6700\u5C0F\u30B3\u30B9\u30C8\nbool used[2010]; //\u3059\
    \u3067\u306B\u9802\u70B9i\u304CX\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\
    \nint N,M; //\u9802\u70B9\u306E\u500B\u6570\u3001\u8FBA\u306E\u672C\u6570\n\n\
    ll prim() {\n    for(int i = 0;i < N;i++) {\n        mincost[i] = INF;\n     \
    \   used[i] = false;\n    }\n    mincost[0] = 0;\n    ll res = 0;\n    while(true)\
    \ {\n        int v = -1;\n        //X\u306B\u5C5E\u3055\u306A\u3044\u9802\u70B9\
    \u306E\u3046\u3061X\u304B\u3089\u306E\u8FBA\u306E\u30B3\u30B9\u30C8\u304C\u6700\
    \u5C0F\u306B\u306A\u308B\u9802\u70B9\u3092\u63A2\u3059\n        for(int u = 0;u\
    \ < N;u++) {\n            if(!used[u] && (v == -1 || mincost[u] < mincost[v]))\
    \ {\n                v = u;\n            }\n        }\n        if(v == -1) break;\n\
    \        used[v] = true; //\u9802\u70B9v\u3092X\u306B\u8FFD\u52A0\n        res\
    \ += mincost[v];\n        for(int u = 0;u < N;u++) {\n            chmin(mincost[u],cost[v][u]);\n\
    \        }\n    }\n    return res;\n}\n#line 8 \"Test/AOJ/Prim.test.cpp\"\n\n\
    int main() {\n    cin >> N;\n    for(int i = 0;i < N;i++) {\n        for(int j\
    \ = 0;j < N;j++) {\n            cin >> cost[i][j];\n            if(cost[i][j]\
    \ == -1) cost[i][j] = INF;\n        }\n    }\n    cout << prim() << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A&lang=jp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../Graph/Prim.cpp\"\n\nint main() {\n    cin >> N;\n    for(int\
    \ i = 0;i < N;i++) {\n        for(int j = 0;j < N;j++) {\n            cin >> cost[i][j];\n\
    \            if(cost[i][j] == -1) cost[i][j] = INF;\n        }\n    }\n    cout\
    \ << prim() << endl;\n}\n"
  dependsOn:
  - Other/Template.cpp
  - Graph/Prim.cpp
  isVerificationFile: true
  path: Test/AOJ/Prim.test.cpp
  requiredBy: []
  timestamp: '2021-06-08 16:42:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/AOJ/Prim.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/Prim.test.cpp
- /verify/Test/AOJ/Prim.test.cpp.html
title: Test/AOJ/Prim.test.cpp
---
