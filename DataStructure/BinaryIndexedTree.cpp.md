---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/yosupo-judge/BinaryIndexedTree.test.cpp
    title: Test/yosupo-judge/BinaryIndexedTree.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/BinaryIndexedTree.cpp\"\ntemplate <typename\
    \ T>\nclass BinaryIndexedTree {\n    int N;\n    vector<T> bit;\n\n    T sum_sub(int\
    \ a) {\n        a++;\n        T ret = 0;\n        if(a == 0) return ret;\n   \
    \     while(a > 0) {\n            ret += bit[a];\n            a -= a & -a;\n \
    \       }\n        return ret;\n    }\n\npublic:\n\n    BinaryIndexedTree(int\
    \ n): N(n) {\n        bit.assign(++n,0);\n    }\n\n    void add(int i,T x) {\n\
    \        i++;\n        if(i == 0) return;\n        while(i < bit.size()) {\n \
    \           bit[i] += x;\n            i += i & -i;\n        }\n    }\n\n    T\
    \ sum(int a,int b) {\n        return sum_sub(b) - sum_sub(a - 1);\n    }\n};\n"
  code: "template <typename T>\nclass BinaryIndexedTree {\n    int N;\n    vector<T>\
    \ bit;\n\n    T sum_sub(int a) {\n        a++;\n        T ret = 0;\n        if(a\
    \ == 0) return ret;\n        while(a > 0) {\n            ret += bit[a];\n    \
    \        a -= a & -a;\n        }\n        return ret;\n    }\n\npublic:\n\n  \
    \  BinaryIndexedTree(int n): N(n) {\n        bit.assign(++n,0);\n    }\n\n   \
    \ void add(int i,T x) {\n        i++;\n        if(i == 0) return;\n        while(i\
    \ < bit.size()) {\n            bit[i] += x;\n            i += i & -i;\n      \
    \  }\n    }\n\n    T sum(int a,int b) {\n        return sum_sub(b) - sum_sub(a\
    \ - 1);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryIndexedTree.cpp
  requiredBy: []
  timestamp: '2021-04-20 18:48:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/yosupo-judge/BinaryIndexedTree.test.cpp
documentation_of: DataStructure/BinaryIndexedTree.cpp
layout: document
title: Binary Indexed Tree
---

## 説明
別名 Fenwick Tree 。1点更新区間加算を Segment Tree より高速に求められる。

- `BinaryIndexedTree<T> bit(int n)` : 長さ $n$ の配列 $A_0,\ A_1,\ A_2,\ \cdots ,\ A_{n - 1}$ を構築する。計算量 $O(N)$
- `void bit.add(int i,T x)` : $A[i]$ に $x$ を加算する。計算量 $O(\log N)$
- `T bit.sum(int a,int b)` : $\sum_{i = a}^b A[i]$ を求める。計算量 $O(\log N)$
