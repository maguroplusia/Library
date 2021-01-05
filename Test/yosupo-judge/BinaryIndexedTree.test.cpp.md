---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree.cpp
    title: DataStructure/BinaryIndexedTree.cpp
  - icon: ':question:'
    path: Other/Template.cpp
    title: Other/Template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
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
    constexpr int Inf = 1000000030;\nconstexpr ll INF= 2000000000000000000;\nconstexpr\
    \ ll MOD = 1000000007;\nconst double PI = 3.1415926535897;\ntypedef pair<ll,ll>\
    \ P;\ntypedef pair<ll,P> PP;\n\ntemplate<class T> inline bool chmax(T &a, T b)\
    \ {\n    if (a < b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n\
    }\n\ntemplate<class T> inline bool chmin(T &a, T b) {\n    if (a > b) {\n    \
    \    a = b;\n        return 1;\n    }\n    return 0;\n}\n\n\nll mod(ll val, ll\
    \ M) {\n    val = val % M;\n    if(val < 0) {\n        val += M;\n    }\n    return\
    \ val;\n}\n\ntemplate<typename T>\nT RS(T N, T P, T M){\n    if(P == 0) {\n  \
    \      return 1;\n    }\n    if(P < 0) {\n        return 0;\n    }\n    if(P %\
    \ 2 == 0){\n        ll t = RS(N, P/2, M);\n        if(M == -1) return t * t;\n\
    \        return t * t % M;\n    }\n    if(M == -1) {\n        return N * RS(N,P\
    \ - 1,M);\n    }\n    return N * RS(N, P-1, M) % M;\n}\n#line 1 \"DataStructure/BinaryIndexedTree.cpp\"\
    \ntemplate <typename T>\nclass BinaryIndexedTree {\n    int N;\n    vector<T>\
    \ bit;\n\n    //a\u756A\u76EE\u307E\u3067\u306E\u548C\u3092\u8A08\u7B97\u3059\u308B\
    \n    T sum_sub(int a) {\n        a++;\n        T ret = 0;\n        if(a == 0)\
    \ return ret;\n        while(a > 0) {\n            ret += bit[a];\n          \
    \  a -= a & -a;\n        }\n        return ret;\n    }\n\npublic:\n\n    BinaryIndexedTree(int\
    \ a): N(a) {\n        bit.assign(++a,0);\n    }\n\n    //A[a]\u306Bw\u3092\u52A0\
    \u7B97\u3059\u308B\n    void add(int a,T w) {\n        a++;\n        if(a == 0)\
    \ return;\n        while(a < bit.size()) {\n            bit[a] += w;\n       \
    \     a += a & -a;\n        }\n    }\n\n    T sum(int a,int b) {\n        return\
    \ sum_sub(b - 1) - sum_sub(a - 1);\n    }\n};\n#line 8 \"Test/yosupo-judge/BinaryIndexedTree.test.cpp\"\
    \n\nint main() {\n    int N,Q;\n    cin >> N >> Q;\n    vector<ll> vec(N);\n \
    \   for(int i = 0;i < N;i++) {\n        cin >> vec.at(i);\n    }\n    BinaryIndexedTree<ll>\
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
  timestamp: '2021-01-05 12:08:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-judge/BinaryIndexedTree.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-judge/BinaryIndexedTree.test.cpp
- /verify/Test/yosupo-judge/BinaryIndexedTree.test.cpp.html
title: Test/yosupo-judge/BinaryIndexedTree.test.cpp
---
