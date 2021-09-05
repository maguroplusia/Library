---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp
    title: Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/SegmentTree-RangeSumQuery.test.cpp
    title: Test/AOJ/SegmentTree-RangeSumQuery.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-judge/SegmentTree-PointAddRangeSum.test.cpp
    title: Test/yosupo-judge/SegmentTree-PointAddRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/SegmentTree.cpp\"\ntemplate<typename T>\n\
    class SegmentTree {\n    int N;\n    const T def;\n    vector<T> dat;\n    function<T(T,T)>\
    \ operation_;\n    function<T(T,T)> update_;\n\n    T query_sub(int a,int b,int\
    \ l,int r,int k) {\n        if(r <= a || b <= l) return def;\n        if(a <=\
    \ l && r <= b) return dat[k];\n        T c1 = query_sub(a,b,l,(l + r) / 2,2 *\
    \ k + 1);\n        T c2 = query_sub(a,b,(l + r) / 2,r,2 * k + 2);\n        return\
    \ operation_(c1,c2);\n    }\n\npublic:\n    SegmentTree(int n,T e,function<T(T,T)>\
    \ operation,function<T(T,T)> update): def(e),operation_(operation),update_(update)\
    \ {\n        int n_ = 1;\n        while(n > n_) {\n            n_ *= 2;\n    \
    \    }\n        N = n_;\n        dat = vector<T>(2 * N - 1,def);\n    }\n\n  \
    \  void set(int i,T x) { dat[i + N - 1] = x;}\n    void build() {\n        for\
    \ (int i = N - 2; i >= 0; i--){\n            dat[i] = operation_(dat[i * 2 + 1],dat[i\
    \ * 2 + 2]);\n        }\n    }\n\n    void update(int i,T x) {\n        i += N\
    \ - 1;\n        dat[i] = update_(dat[i],x);\n        while(i > 0) {\n        \
    \    i = (i - 1) / 2;\n            dat[i] = operation_(dat[i * 2 + 1],dat[i *\
    \ 2 + 2]);\n        }\n    }\n\n    T query(int a,int b) {return query_sub(a,b,0,N,0);}\n\
    \n    T operator[](int i) {return dat[i + N - 1];}\n};\n"
  code: "template<typename T>\nclass SegmentTree {\n    int N;\n    const T def;\n\
    \    vector<T> dat;\n    function<T(T,T)> operation_;\n    function<T(T,T)> update_;\n\
    \n    T query_sub(int a,int b,int l,int r,int k) {\n        if(r <= a || b <=\
    \ l) return def;\n        if(a <= l && r <= b) return dat[k];\n        T c1 =\
    \ query_sub(a,b,l,(l + r) / 2,2 * k + 1);\n        T c2 = query_sub(a,b,(l + r)\
    \ / 2,r,2 * k + 2);\n        return operation_(c1,c2);\n    }\n\npublic:\n   \
    \ SegmentTree(int n,T e,function<T(T,T)> operation,function<T(T,T)> update): def(e),operation_(operation),update_(update)\
    \ {\n        int n_ = 1;\n        while(n > n_) {\n            n_ *= 2;\n    \
    \    }\n        N = n_;\n        dat = vector<T>(2 * N - 1,def);\n    }\n\n  \
    \  void set(int i,T x) { dat[i + N - 1] = x;}\n    void build() {\n        for\
    \ (int i = N - 2; i >= 0; i--){\n            dat[i] = operation_(dat[i * 2 + 1],dat[i\
    \ * 2 + 2]);\n        }\n    }\n\n    void update(int i,T x) {\n        i += N\
    \ - 1;\n        dat[i] = update_(dat[i],x);\n        while(i > 0) {\n        \
    \    i = (i - 1) / 2;\n            dat[i] = operation_(dat[i * 2 + 1],dat[i *\
    \ 2 + 2]);\n        }\n    }\n\n    T query(int a,int b) {return query_sub(a,b,0,N,0);}\n\
    \n    T operator[](int i) {return dat[i + N - 1];}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree.cpp
  requiredBy: []
  timestamp: '2021-04-20 19:31:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/SegmentTree-RangeSumQuery.test.cpp
  - Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp
  - Test/yosupo-judge/SegmentTree-PointAddRangeSum.test.cpp
documentation_of: DataStructure/SegmentTree.cpp
layout: document
title: Segment Tree
---

## 説明

配列に対する1点更新クエリと区間求値クエリを高速に処理出来る。

- `SegmentTree<T> seg(int n,T e,function<T(T,T)> operation,function<T(T,T)> update)` : 以下のような配列 `A` を構成する。
    - `n` : 配列の長さ
    - `e` : `T`の単位元かつ `A` の全ての要素の初期値
    - `operation` : 求値クエリで使う二項演算
    - `update` : 更新クエリで使う二項演算
- `void seg.set(int i,T x), void seg.build()` : 配列の初期値が存在する場合これを用いる。計算量 $O(N)$
- `void seg.update(int i,T x)` : `A[i] = update(A[i],x)` の操作を行う。計算量 $O(\log N)$
- `T seg.query(int l,int r)` : `operation(A[l],A[l + 1],…,A[r - 1])` を求める。計算量 $O(\log N)$
- `T seg[i]` : `A[i]` を返す。計算量 $O(1)$

**注意** 上に書かれている計算量は `operation` 、 `update` が定数時間で動くものと仮定して書かれている。これらの内部の計算量が $O(f(n))$ だった場合、全ての計算量が $O(f(n))$ 倍される。
