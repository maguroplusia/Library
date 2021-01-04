---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/UnionFind.cpp
    title: DataStructure/UnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"Test/yosupo-judge/UnionFind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include<bits/stdc++.h>\nusing\
    \ namesapce std;\n\n#line 1 \"DataStructure/UnionFind.cpp\"\nclass UnionFind {\n\
    \tvector<int> par; //\u89AA\n\tvector<int> siz; //\u6839\u30CE\u30FC\u30C9i\u306E\
    \u6728\u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u6570\u3002i\u304C\u6839\u30CE\
    \u30FC\u30C9\u51FA\u306A\u3044\u5834\u5408\u7121\u610F\u5473\u306A\u5024\u3068\
    \u306A\u308B\u3002\n\npublic:\n\t//n\u8981\u7D20\u3067\u521D\u671F\u5316\n\tUnionFind(int\
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
    }\n};\n#line 7 \"Test/yosupo-judge/UnionFind.test.cpp\"\n\nint main() {\n    int\
    \ N,Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n    for(int i = 0;i < Q;i++)\
    \ {\n        int t,a,b;\n        cin >> t >> a >> b;\n        if(t == 0) {\n \
    \           uf.unite(a,b);\n        }\n        else {\n            cout << uf.same(a,b)\
    \ << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include<bits/stdc++.h>\n\
    using namesapce std;\n\n#include\"../../DataStructure/UnionFind.cpp\"\n\nint main()\
    \ {\n    int N,Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n    for(int i = 0;i\
    \ < Q;i++) {\n        int t,a,b;\n        cin >> t >> a >> b;\n        if(t ==\
    \ 0) {\n            uf.unite(a,b);\n        }\n        else {\n            cout\
    \ << uf.same(a,b) << endl;\n        }\n    }\n}\n"
  dependsOn:
  - DataStructure/UnionFind.cpp
  isVerificationFile: true
  path: Test/yosupo-judge/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2021-01-04 18:34:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/yosupo-judge/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-judge/UnionFind.test.cpp
- /verify/Test/yosupo-judge/UnionFind.test.cpp.html
title: Test/yosupo-judge/UnionFind.test.cpp
---
