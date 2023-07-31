---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.cpp
    title: Union-Find
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"Test/yosupo-judge/UnionFind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 1 \"Other/Template.cpp\"\nconstexpr int Inf = 2000000030;\n\
    constexpr long long INF= 2000000000000000000;\n\ntemplate<typename T> inline bool\
    \ chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }\ntemplate<typename\
    \ T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return\
    \ false; }\n#line 1 \"DataStructure/UnionFind.cpp\"\nclass UnionFind {\n    vector<int>\
    \ par;\n    vector<int> siz;\n\npublic:\n\n    UnionFind(int n) {\n        par.resize(n);\n\
    \        siz.resize(n);\n        for(int i = 0;i < n;i++) {\n            par[i]\
    \ = i;\n            siz[i] = 1;\n        }\n    }\n\n    int find(int x) {\n \
    \       if(par[x] == x) {\n            return x;\n        }\n        else {\n\
    \            return par[x] = find(par[x]);\n        }\n    }\n\n    void unite(int\
    \ x,int y) {\n        x = find(x);\n        y = find(y);\n        if(x == y) {\n\
    \            return;\n        }\n        if(siz[x] < siz[y]) {\n            swap(x,y);\n\
    \        }\n        par[y] = x;\n        siz[x] += siz[y];\n    }\n\n    bool\
    \ same(int x,int y) {\n        return find(x) == find(y);\n    }\n\n    int size(int\
    \ x) {\n        return siz[find(x)];\n    }\n};\n#line 8 \"Test/yosupo-judge/UnionFind.test.cpp\"\
    \n\nint main() {\n    int N,Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n   \
    \ for(int i = 0;i < Q;i++) {\n        int t,a,b;\n        cin >> t >> a >> b;\n\
    \        if(t == 0) {\n            uf.unite(a,b);\n        }\n        else {\n\
    \            cout << uf.same(a,b) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#include\"../../Other/Template.cpp\"\n#include\"../../DataStructure/UnionFind.cpp\"\
    \n\nint main() {\n    int N,Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n   \
    \ for(int i = 0;i < Q;i++) {\n        int t,a,b;\n        cin >> t >> a >> b;\n\
    \        if(t == 0) {\n            uf.unite(a,b);\n        }\n        else {\n\
    \            cout << uf.same(a,b) << endl;\n        }\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - DataStructure/UnionFind.cpp
  isVerificationFile: true
  path: Test/yosupo-judge/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2021-06-18 21:14:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-judge/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-judge/UnionFind.test.cpp
- /verify/Test/yosupo-judge/UnionFind.test.cpp.html
title: Test/yosupo-judge/UnionFind.test.cpp
---
