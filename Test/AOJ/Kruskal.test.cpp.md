---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.cpp
    title: DataStructure/UnionFind.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/Kruskal.cpp
    title: Graph/Kruskal.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"Test/AOJ/Kruskal.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
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
    \ - 1,M);\n    }\n    return N * RS(N, P-1, M) % M;\n}\n#line 1 \"DataStructure/UnionFind.cpp\"\
    \nclass UnionFind {\n    vector<int> par; //\u89AA\n    vector<int> siz; //\u6839\
    \u30CE\u30FC\u30C9i\u306E\u6728\u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u6570\
    \u3002i\u304C\u6839\u30CE\u30FC\u30C9\u51FA\u306A\u3044\u5834\u5408\u7121\u610F\
    \u5473\u306A\u5024\u3068\u306A\u308B\u3002\n\npublic:\n    //n\u8981\u7D20\u3067\
    \u521D\u671F\u5316\n    UnionFind(int n) {\n        par.resize(n);\n        siz.resize(n);\n\
    \        for(int i = 0;i < n;i++) {\n            par[i] = i;\n            siz[i]\
    \ = 1;\n        }\n    }\n\n    //\u6728\u306E\u6839\u3092\u6C42\u3081\u308B\n\
    \    int find(int x) {\n        if(par[x] == x) {\n            return x;\n   \
    \     }\n        else {\n            return par[x] = find(par[x]);\n        }\n\
    \    }\n\n    //\uFF58\u3068\uFF59\u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\
    \u5408\n    void unite(int x,int y) {\n        x = find(x);\n        y = find(y);\n\
    \        if(x == y) {\n            return;\n        }\n        if(siz[x] < siz[y])\
    \ {\n            swap(x,y);\n        }\n        par[y] = x;\n        siz[x] +=\
    \ siz[y];\n    }\n\n    //\uFF58\u3068\uFF59\u304C\u540C\u3058\u96C6\u5408\u306B\
    \u5C5E\u3059\u308B\u304B\u5426\u304B\n    bool same(int x,int y) {\n        return\
    \ find(x) == find(y);\n    }\n\n    int size(int x) {\n        return siz[find(x)];\n\
    \    }\n};\n#line 1 \"Graph/Kruskal.cpp\"\n//UnionFind\u30E9\u30A4\u30D6\u30E9\
    \u30EA\u3092\u547C\u3073\u51FA\u3059\u3053\u3068\nstruct edge {\n    int u,v;\n\
    \    ll cost;\n};\n\nbool comp(const edge &e1,const edge &e2) {\n    return e1.cost\
    \ < e2.cost;\n}\n\nint N,M; //\u9802\u70B9\u306E\u672C\u6570\u3001\u70B9\u306E\
    \u500B\u6570\nedge graph[200010];\n\nll Kruskal() {\n    sort(graph,graph + M,comp);\n\
    \    UnionFind uf(N);\n    ll ret = 0;\n    for(int i = 0;i < M;i++) {\n     \
    \   edge e = graph[i];\n        if(!uf.same(e.u,e.v)) {\n            uf.unite(e.u,e.v);\n\
    \            ret += e.cost;\n        }\n    }\n    return ret;\n}\n#line 9 \"\
    Test/AOJ/Kruskal.test.cpp\"\n\nint main() {\n    cin >> N >> M;\n    for(int i\
    \ = 0;i < M;i++) {\n        int s,t;\n        ll w;\n        cin >> s >> t >>\
    \ w;\n        graph[i] = edge{s,t,w};\n    }\n    cout << Kruskal() << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../DataStructure/UnionFind.cpp\"\n#include\"../../Graph/Kruskal.cpp\"\
    \n\nint main() {\n    cin >> N >> M;\n    for(int i = 0;i < M;i++) {\n       \
    \ int s,t;\n        ll w;\n        cin >> s >> t >> w;\n        graph[i] = edge{s,t,w};\n\
    \    }\n    cout << Kruskal() << endl;\n}\n"
  dependsOn:
  - Other/Template.cpp
  - DataStructure/UnionFind.cpp
  - Graph/Kruskal.cpp
  isVerificationFile: true
  path: Test/AOJ/Kruskal.test.cpp
  requiredBy: []
  timestamp: '2021-02-06 17:01:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/Kruskal.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/Kruskal.test.cpp
- /verify/Test/AOJ/Kruskal.test.cpp.html
title: Test/AOJ/Kruskal.test.cpp
---
