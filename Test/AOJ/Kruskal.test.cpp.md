---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.cpp
    title: Union-Find
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
    \ntypedef long long ll;\nconstexpr int Inf = 2000000030;\nconstexpr long long\
    \ INF= 2000000000000000000;\n\ntemplate<typename T> inline bool chmax(T &a, T\
    \ b) { if (a < b) { a = b; return true; } return false; }\ntemplate<typename T>\
    \ inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false;\
    \ }\n#line 1 \"DataStructure/UnionFind.cpp\"\nclass UnionFind {\n    vector<int>\
    \ par;\n    vector<int> siz;\n\npublic:\n\n    UnionFind(int n) {\n        par.resize(n);\n\
    \        siz.resize(n);\n        for(int i = 0;i < n;i++) {\n            par[i]\
    \ = i;\n            siz[i] = 1;\n        }\n    }\n\n    int find(int x) {\n \
    \       if(par[x] == x) {\n            return x;\n        }\n        else {\n\
    \            return par[x] = find(par[x]);\n        }\n    }\n\n    void unite(int\
    \ x,int y) {\n        x = find(x);\n        y = find(y);\n        if(x == y) {\n\
    \            return;\n        }\n        if(siz[x] < siz[y]) {\n            swap(x,y);\n\
    \        }\n        par[y] = x;\n        siz[x] += siz[y];\n    }\n\n    bool\
    \ same(int x,int y) {\n        return find(x) == find(y);\n    }\n\n    int size(int\
    \ x) {\n        return siz[find(x)];\n    }\n};\n#line 2 \"Graph/Kruskal.cpp\"\
    \n\nstruct edge {\n    int u,v;\n    ll cost;\n\n    bool operator<(const edge&\
    \ b) const {\n        return cost < b.cost;\n    }\n};\n\nint N,M;\nedge graph[200010];\n\
    \nll Kruskal() {\n    sort(graph,graph + M);\n    UnionFind uf(N);\n    ll ret\
    \ = 0;\n    for(int i = 0;i < M;i++) {\n        edge e = graph[i];\n        if(!uf.same(e.u,e.v))\
    \ {\n            uf.unite(e.u,e.v);\n            ret += e.cost;\n        }\n \
    \   }\n    return ret;\n}\n#line 8 \"Test/AOJ/Kruskal.test.cpp\"\n\nint main()\
    \ {\n    cin >> N >> M;\n    for(int i = 0;i < M;i++) {\n        int s,t;\n  \
    \      ll w;\n        cin >> s >> t >> w;\n        graph[i] = edge{s,t,w};\n \
    \   }\n    cout << Kruskal() << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../Graph/Kruskal.cpp\"\n\nint main() {\n    cin >> N >> M;\n  \
    \  for(int i = 0;i < M;i++) {\n        int s,t;\n        ll w;\n        cin >>\
    \ s >> t >> w;\n        graph[i] = edge{s,t,w};\n    }\n    cout << Kruskal()\
    \ << endl;\n}\n"
  dependsOn:
  - Other/Template.cpp
  - Graph/Kruskal.cpp
  - DataStructure/UnionFind.cpp
  isVerificationFile: true
  path: Test/AOJ/Kruskal.test.cpp
  requiredBy: []
  timestamp: '2021-06-16 20:38:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/Kruskal.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/Kruskal.test.cpp
- /verify/Test/AOJ/Kruskal.test.cpp.html
title: Test/AOJ/Kruskal.test.cpp
---
