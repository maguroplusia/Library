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
    using namespace std;\n\n#line 1 \"Other/Template.cpp\"\nconstexpr int Inf = 2000000030;\n\
    constexpr long long INF= 2000000000000000000;\n\ntemplate<typename T> inline bool\
    \ chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }\ntemplate<typename\
    \ T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return\
    \ false; }\n#line 1 \"DataStructure/BinaryIndexedTree.cpp\"\ntemplate <typename\
    \ T>\nclass BinaryIndexedTree {\n    int N;\n    vector<T> bit;\n\n    T sum_sub(int\
    \ a) {\n        a++;\n        T ret = 0;\n        if(a == 0) return ret;\n   \
    \     while(a > 0) {\n            ret += bit[a];\n            a -= a & -a;\n \
    \       }\n        return ret;\n    }\n\npublic:\n\n    BinaryIndexedTree(int\
    \ n): N(n) {\n        bit.assign(++n,0);\n    }\n\n    void add(int i,T x) {\n\
    \        i++;\n        if(i == 0) return;\n        while(i < bit.size()) {\n \
    \           bit[i] += x;\n            i += i & -i;\n        }\n    }\n\n    T\
    \ sum(int l,int r) {\n        return sum_sub(r - 1) - sum_sub(l - 1);\n    }\n\
    };\n#line 8 \"Test/yosupo-judge/BinaryIndexedTree.test.cpp\"\n\nint main() {\n\
    \    int N,Q;\n    cin >> N >> Q;\n    vector<long long> vec(N);\n    for(int\
    \ i = 0;i < N;i++) {\n        cin >> vec.at(i);\n    }\n    BinaryIndexedTree<long\
    \ long> bit(N);\n    for(int i = 0;i < N;i++) {\n        bit.add(i,vec.at(i));\n\
    \    }\n    for(int i = 0;i < Q;i++) {\n        int l,r;\n        cin >> l >>\
    \ r;\n        cout << bit.sum(l,r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../DataStructure/BinaryIndexedTree.cpp\"\n\nint main() {\n    int\
    \ N,Q;\n    cin >> N >> Q;\n    vector<long long> vec(N);\n    for(int i = 0;i\
    \ < N;i++) {\n        cin >> vec.at(i);\n    }\n    BinaryIndexedTree<long long>\
    \ bit(N);\n    for(int i = 0;i < N;i++) {\n        bit.add(i,vec.at(i));\n   \
    \ }\n    for(int i = 0;i < Q;i++) {\n        int l,r;\n        cin >> l >> r;\n\
    \        cout << bit.sum(l,r) << endl;\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - DataStructure/BinaryIndexedTree.cpp
  isVerificationFile: true
  path: Test/yosupo-judge/BinaryIndexedTree.test.cpp
  requiredBy: []
  timestamp: '2021-06-18 21:14:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-judge/BinaryIndexedTree.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-judge/BinaryIndexedTree.test.cpp
- /verify/Test/yosupo-judge/BinaryIndexedTree.test.cpp.html
title: Test/yosupo-judge/BinaryIndexedTree.test.cpp
---
