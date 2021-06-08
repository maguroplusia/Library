---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree.cpp
    title: Binary Indexed Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"Test/yosupo-judge/BinaryIndexedTree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"Other/Template.cpp\"\ntypedef long long ll;\n\
    \ntemplate<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return\
    \ true; } return false; }\ntemplate<typename T> inline bool chmin(T &a, T b) {\
    \ if (a > b) { a = b; return true; } return false; }\n\ntemplate<typename T>\n\
    T modpow(T N, T P, T M){\n    if(P == 0) return 1;\n    if(P < 0) return 0;\n\
    \    if(P % 2 == 0){\n        T t = modpow(N, P/2, M);\n        if(M == -1) return\
    \ t * t;\n        return t * t % M;\n    }\n    if(M == -1) return N * modpow(N,P\
    \ - 1,M);\n    return N * modpow(N, P-1, M) % M;\n}\n#line 1 \"DataStructure/BinaryIndexedTree.cpp\"\
    \ntemplate <typename T>\nclass BinaryIndexedTree {\n    int N;\n    vector<T>\
    \ bit;\n\n    T sum_sub(int a) {\n        a++;\n        T ret = 0;\n        if(a\
    \ == 0) return ret;\n        while(a > 0) {\n            ret += bit[a];\n    \
    \        a -= a & -a;\n        }\n        return ret;\n    }\n\npublic:\n\n  \
    \  BinaryIndexedTree(int n): N(n) {\n        bit.assign(++n,0);\n    }\n\n   \
    \ void add(int i,T x) {\n        i++;\n        if(i == 0) return;\n        while(i\
    \ < bit.size()) {\n            bit[i] += x;\n            i += i & -i;\n      \
    \  }\n    }\n\n    T sum(int l,int r) {\n        return sum_sub(r - 1) - sum_sub(l\
    \ - 1);\n    }\n};\n#line 8 \"Test/yosupo-judge/BinaryIndexedTree.test.cpp\"\n\
    \nint main() {\n    int N,Q;\n    cin >> N >> Q;\n    vector<ll> vec(N);\n   \
    \ for(int i = 0;i < N;i++) {\n        cin >> vec.at(i);\n    }\n    BinaryIndexedTree<ll>\
    \ bit(N);\n    for(int i = 0;i < N;i++) {\n        bit.add(i,vec.at(i));\n   \
    \ }\n    for(int i = 0;i < Q;i++) {\n        int l,r;\n        cin >> l >> r;\n\
    \        cout << bit.sum(l,r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../DataStructure/BinaryIndexedTree.cpp\"\n\nint main() {\n    int\
    \ N,Q;\n    cin >> N >> Q;\n    vector<ll> vec(N);\n    for(int i = 0;i < N;i++)\
    \ {\n        cin >> vec.at(i);\n    }\n    BinaryIndexedTree<ll> bit(N);\n   \
    \ for(int i = 0;i < N;i++) {\n        bit.add(i,vec.at(i));\n    }\n    for(int\
    \ i = 0;i < Q;i++) {\n        int l,r;\n        cin >> l >> r;\n        cout <<\
    \ bit.sum(l,r) << endl;\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - DataStructure/BinaryIndexedTree.cpp
  isVerificationFile: true
  path: Test/yosupo-judge/BinaryIndexedTree.test.cpp
  requiredBy: []
  timestamp: '2021-06-08 16:42:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-judge/BinaryIndexedTree.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-judge/BinaryIndexedTree.test.cpp
- /verify/Test/yosupo-judge/BinaryIndexedTree.test.cpp.html
title: Test/yosupo-judge/BinaryIndexedTree.test.cpp
---
