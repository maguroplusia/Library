---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.cpp
    title: DataStructure/UnionFind.cpp
  - icon: ':question:'
    path: Other/Template.cpp
    title: Other/Template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"Test/yosupo-judge/UnionFind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 1 \"Other/Template.cpp\"\ntypedef long long ll;\nconstexpr\
    \ int Inf = 1000000030;\nconstexpr ll INF= 2000000000000000000;\nconstexpr ll\
    \ MOD = 1000000007;\nconst double PI = 3.1415926535897;\ntypedef pair<ll,ll> P;\n\
    typedef pair<ll,P> PP;\n\ntemplate<class T> inline bool chmax(T &a, T b) {\n \
    \   if (a < b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n}\n\
    \ntemplate<class T> inline bool chmin(T &a, T b) {\n    if (a > b) {\n       \
    \ a = b;\n        return 1;\n    }\n    return 0;\n}\n\n\nll mod(ll val, ll M)\
    \ {\n    val = val % M;\n    if(val < 0) {\n        val += M;\n    }\n    return\
    \ val;\n}\n\ntemplate<typename T>\nT RS(T N, T P, T M){\n    if(P == 0) {\n  \
    \      return 1;\n    }\n    if(P < 0) {\n        return 0;\n    }\n    if(P %\
    \ 2 == 0){\n        ll t = RS(N, P/2, M);\n        if(M == -1) return t * t;\n\
    \        return t * t % M;\n    }\n    if(M == -1) {\n        return N * RS(N,P\
    \ - 1,M);\n    }\n    return N * RS(N, P-1, M) % M;\n}\n#line 1 \"DataStructure/UnionFind.cpp\"\
    \nclass UnionFind {\n\tvector<int> par; //\u89AA\n\tvector<int> siz; //\u6839\u30CE\
    \u30FC\u30C9i\u306E\u6728\u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u6570\u3002\
    i\u304C\u6839\u30CE\u30FC\u30C9\u51FA\u306A\u3044\u5834\u5408\u7121\u610F\u5473\
    \u306A\u5024\u3068\u306A\u308B\u3002\n\npublic:\n\t//n\u8981\u7D20\u3067\u521D\
    \u671F\u5316\n\tUnionFind(int n) {\n\t\tpar.resize(n);\n\t\tsiz.resize(n);\n\t\
    \tfor(int i = 0;i < n;i++) {\n\t\t\tpar[i] = i;\n\t\t\tsiz[i] = 1;\n\t\t}\n\t\
    }\n\n\t//\u6728\u306E\u6839\u3092\u6C42\u3081\u308B\n\tint find(int x) {\n\t\t\
    if(par[x] == x) {\n\t\t\treturn x;\n\t\t}\n\t\telse {\n\t\t\treturn par[x] = find(par[x]);\n\
    \t\t}\n\t}\n\n\t//\uFF58\u3068\uFF59\u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\
    \u4F75\u5408\n\tvoid unite(int x,int y) {\n\t\tx = find(x);\n\t\ty = find(y);\n\
    \t\tif(x == y) {\n\t\t\treturn;\n\t\t}\n\t\tif(siz[x] < siz[y]) {\n\t\t\tswap(x,y);\n\
    \t\t}\n\t\tpar[y] = x;\n\t\tsiz[x] += siz[y];\n\t}\n\n\t//\uFF58\u3068\uFF59\u304C\
    \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u5426\u304B\n\tbool same(int\
    \ x,int y) {\n\t\treturn find(x) == find(y);\n\t}\n\n\tint size(int x) {\n\t\t\
    return siz[find(x)];\n\t}\n};\n#line 8 \"Test/yosupo-judge/UnionFind.test.cpp\"\
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
  timestamp: '2021-01-04 19:32:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-judge/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-judge/UnionFind.test.cpp
- /verify/Test/yosupo-judge/UnionFind.test.cpp.html
title: Test/yosupo-judge/UnionFind.test.cpp
---
