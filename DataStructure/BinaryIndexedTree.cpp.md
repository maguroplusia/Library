---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-judge/BinaryIndexedTree.test.cpp
    title: Test/yosupo-judge/BinaryIndexedTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ sum(int l,int r) {\n        return sum_sub(r - 1) - sum_sub(l - 1);\n    }\n\
    };\n"
  code: "template <typename T>\nclass BinaryIndexedTree {\n    int N;\n    vector<T>\
    \ bit;\n\n    T sum_sub(int a) {\n        a++;\n        T ret = 0;\n        if(a\
    \ == 0) return ret;\n        while(a > 0) {\n            ret += bit[a];\n    \
    \        a -= a & -a;\n        }\n        return ret;\n    }\n\npublic:\n\n  \
    \  BinaryIndexedTree(int n): N(n) {\n        bit.assign(++n,0);\n    }\n\n   \
    \ void add(int i,T x) {\n        i++;\n        if(i == 0) return;\n        while(i\
    \ < bit.size()) {\n            bit[i] += x;\n            i += i & -i;\n      \
    \  }\n    }\n\n    T sum(int l,int r) {\n        return sum_sub(r - 1) - sum_sub(l\
    \ - 1);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryIndexedTree.cpp
  requiredBy: []
  timestamp: '2021-04-21 14:12:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-judge/BinaryIndexedTree.test.cpp
documentation_of: DataStructure/BinaryIndexedTree.cpp
layout: document
title: Binary Indexed Tree
---

## 説明
別名 Fenwick Tree 。配列に対する1点更新クエリと区間和を求めるクエリを Segment Tree より高速に処理出来る。

- `BinaryIndexedTree<T> bit(int n)` : 長さ $n$ の配列 $A_0,\ A_1,\ A_2,\ \cdots ,\ A_{n - 1}$ を構築する。計算量 $O(N)$
- `void bit.add(int i,T x)` : `A[i] += x` を行う。計算量 $O(\log N)$
- `T bit.sum(int l,int r)` : `A[l] + A[l + 1] + … + A[r - 1]` を求める。計算量 $O(\log N)$
