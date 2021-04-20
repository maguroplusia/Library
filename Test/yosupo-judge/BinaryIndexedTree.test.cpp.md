---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/BinaryIndexedTree.cpp
    title: Binary Indexed Tree
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
    \ bit;\n\n    T sum_sub(int a) {\n        a++;\n        T ret = 0;\n        if(a\
    \ == 0) return ret;\n        while(a > 0) {\n            ret += bit[a];\n    \
    \        a -= a & -a;\n        }\n        return ret;\n    }\n\npublic:\n\n  \
    \  BinaryIndexedTree(int n): N(n) {\n        bit.assign(++n,0);\n    }\n\n   \
    \ void add(int i,T x) {\n        i++;\n        if(i == 0) return;\n        while(i\
    \ < bit.size()) {\n            bit[i] += x;\n            i += i & -i;\n      \
    \  }\n    }\n\n    T sum(int a,int b) {\n        return sum_sub(b) - sum_sub(a\
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
  timestamp: '2021-04-20 18:48:21+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/yosupo-judge/BinaryIndexedTree.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-judge/BinaryIndexedTree.test.cpp
- /verify/Test/yosupo-judge/BinaryIndexedTree.test.cpp.html
title: Test/yosupo-judge/BinaryIndexedTree.test.cpp
---
