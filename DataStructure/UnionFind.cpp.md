---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/Kruskal.test.cpp
    title: Test/AOJ/Kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-judge/UnionFind.test.cpp
    title: Test/yosupo-judge/UnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/UnionFind.cpp\"\nclass UnionFind {\n    vector<int>\
    \ par; //\u89AA\n    vector<int> siz; //\u6839\u30CE\u30FC\u30C9i\u306E\u6728\u306B\
    \u542B\u307E\u308C\u308B\u8981\u7D20\u6570\u3002i\u304C\u6839\u30CE\u30FC\u30C9\
    \u51FA\u306A\u3044\u5834\u5408\u7121\u610F\u5473\u306A\u5024\u3068\u306A\u308B\
    \u3002\n\npublic:\n    //n\u8981\u7D20\u3067\u521D\u671F\u5316\n    UnionFind(int\
    \ n) {\n        par.resize(n);\n        siz.resize(n);\n        for(int i = 0;i\
    \ < n;i++) {\n            par[i] = i;\n            siz[i] = 1;\n        }\n  \
    \  }\n\n    //\u6728\u306E\u6839\u3092\u6C42\u3081\u308B\n    int find(int x)\
    \ {\n        if(par[x] == x) {\n            return x;\n        }\n        else\
    \ {\n            return par[x] = find(par[x]);\n        }\n    }\n\n    //\uFF58\
    \u3068\uFF59\u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\n    void unite(int\
    \ x,int y) {\n        x = find(x);\n        y = find(y);\n        if(x == y) {\n\
    \            return;\n        }\n        if(siz[x] < siz[y]) {\n            swap(x,y);\n\
    \        }\n        par[y] = x;\n        siz[x] += siz[y];\n    }\n\n    //\uFF58\
    \u3068\uFF59\u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u5426\
    \u304B\n    bool same(int x,int y) {\n        return find(x) == find(y);\n   \
    \ }\n\n    int size(int x) {\n        return siz[find(x)];\n    }\n};\n"
  code: "class UnionFind {\n    vector<int> par; //\u89AA\n    vector<int> siz; //\u6839\
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
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.cpp
  requiredBy: []
  timestamp: '2021-02-06 17:01:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-judge/UnionFind.test.cpp
  - Test/AOJ/Kruskal.test.cpp
documentation_of: DataStructure/UnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/UnionFind.cpp
- /library/DataStructure/UnionFind.cpp.html
title: DataStructure/UnionFind.cpp
---
