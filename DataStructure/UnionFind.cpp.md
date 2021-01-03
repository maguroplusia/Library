---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/UnionFind.cpp\"\nclass Union_find {\n\tvector<int>\
    \ par; //\u89AA\n\tvector<int> siz; //\u6839\u30CE\u30FC\u30C9i\u306E\u6728\u306B\
    \u542B\u307E\u308C\u308B\u8981\u7D20\u6570\u3002i\u304C\u6839\u30CE\u30FC\u30C9\
    \u51FA\u306A\u3044\u5834\u5408\u7121\u610F\u5473\u306A\u5024\u3068\u306A\u308B\
    \u3002\n\npublic:\n\t//n\u8981\u7D20\u3067\u521D\u671F\u5316\n\tUnion_find(int\
    \ n) {\n\t\tpar.resize(n);\n\t\tsiz.resize(n);\n\t\tfor(int i = 0;i < n;i++) {\n\
    \t\t\tpar[i] = i;\n\t\t\tsiz[i] = 1;\n\t\t}\n\t}\n\n\t//\u6728\u306E\u6839\u3092\
    \u6C42\u3081\u308B\n\tint find(int x) {\n\t\tif(par[x] == x) {\n\t\t\treturn x;\n\
    \t\t}\n\t\telse {\n\t\t\treturn par[x] = find(par[x]);\n\t\t}\n\t}\n\n\t//\uFF58\
    \u3068\uFF59\u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\n\tvoid unite(int\
    \ x,int y) {\n\t\tx = find(x);\n\t\ty = find(y);\n\t\tif(x == y) {\n\t\t\treturn;\n\
    \t\t}\n\t\tif(siz[x] < siz[y]) {\n\t\t\tswap(x,y);\n\t\t}\n\t\tpar[y] = x;\n\t\
    \tsiz[x] += siz[y];\n\t}\n\n\t//\uFF58\u3068\uFF59\u304C\u540C\u3058\u96C6\u5408\
    \u306B\u5C5E\u3059\u308B\u304B\u5426\u304B\n\tbool same(int x,int y) {\n\t\treturn\
    \ find(x) == find(y);\n\t}\n\n\tint size(int x) {\n\t\treturn siz[find(x)];\n\t\
    }\n};\n"
  code: "class Union_find {\n\tvector<int> par; //\u89AA\n\tvector<int> siz; //\u6839\
    \u30CE\u30FC\u30C9i\u306E\u6728\u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u6570\
    \u3002i\u304C\u6839\u30CE\u30FC\u30C9\u51FA\u306A\u3044\u5834\u5408\u7121\u610F\
    \u5473\u306A\u5024\u3068\u306A\u308B\u3002\n\npublic:\n\t//n\u8981\u7D20\u3067\
    \u521D\u671F\u5316\n\tUnion_find(int n) {\n\t\tpar.resize(n);\n\t\tsiz.resize(n);\n\
    \t\tfor(int i = 0;i < n;i++) {\n\t\t\tpar[i] = i;\n\t\t\tsiz[i] = 1;\n\t\t}\n\t\
    }\n\n\t//\u6728\u306E\u6839\u3092\u6C42\u3081\u308B\n\tint find(int x) {\n\t\t\
    if(par[x] == x) {\n\t\t\treturn x;\n\t\t}\n\t\telse {\n\t\t\treturn par[x] = find(par[x]);\n\
    \t\t}\n\t}\n\n\t//\uFF58\u3068\uFF59\u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\
    \u4F75\u5408\n\tvoid unite(int x,int y) {\n\t\tx = find(x);\n\t\ty = find(y);\n\
    \t\tif(x == y) {\n\t\t\treturn;\n\t\t}\n\t\tif(siz[x] < siz[y]) {\n\t\t\tswap(x,y);\n\
    \t\t}\n\t\tpar[y] = x;\n\t\tsiz[x] += siz[y];\n\t}\n\n\t//\uFF58\u3068\uFF59\u304C\
    \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u5426\u304B\n\tbool same(int\
    \ x,int y) {\n\t\treturn find(x) == find(y);\n\t}\n\n\tint size(int x) {\n\t\t\
    return siz[find(x)];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.cpp
  requiredBy: []
  timestamp: '2021-01-03 18:40:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/UnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/UnionFind.cpp
- /library/DataStructure/UnionFind.cpp.html
title: DataStructure/UnionFind.cpp
---
