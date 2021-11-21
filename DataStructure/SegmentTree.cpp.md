---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp
    title: Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp
  - icon: ':x:'
    path: Test/AOJ/SegmentTree-RangeSumQuery.test.cpp
    title: Test/AOJ/SegmentTree-RangeSumQuery.test.cpp
  - icon: ':x:'
    path: Test/yosupo-judge/SegmentTree-PointAddRangeSum.test.cpp
    title: Test/yosupo-judge/SegmentTree-PointAddRangeSum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/SegmentTree.cpp\"\ntemplate<typename T>\n\
    class SegmentTree {\n    int internal_size, seg_size;\n    const T def;\n    std::vector<T>\
    \ dat;\n    std::function<T(T, T)> operation;\n    std::function<T(T, T)> update;\n\
    \npublic:\n    explicit SegmentTree(const int size, const T& e, std::function<T(T,\
    \ T)> operation, std::function<T(T, T)> update): internal_size(size), def(e),\
    \ operation(operation), update(update) {\n        for(seg_size = 1; seg_size <\
    \ internal_size; seg_size *= 2);\n        dat = std::vector<T>(2 * seg_size, def);\n\
    \    }\n\n    explicit SegmentTree(std::vector<T> v, const T& e,std::function<T(T,\
    \ T)> operation, std::function<T(T, T)> update): internal_size(v.size()), def(e),\
    \ operation(operation), update(update) {\n        for(seg_size = 1; seg_size <\
    \ internal_size; seg_size *= 2);\n        dat.resize(2 * seg_size, def);\n\n \
    \       for(int i = 0; i < seg_size;i++) dat[i + seg_size] = v[i];\n        for(int\
    \ i = seg_size - 1; i >= 1; i--) {\n            dat[i] = operation(dat[i * 2],\
    \ dat[i * 2 + 1]);\n        }\n    }\n\n    void set_val(int i, const T& value)\
    \ {\n        i += seg_size;\n        dat[i] = update(dat[i], value);\n       \
    \ while(i > 1) {\n            i >>= 1;\n            dat[i] = operation(dat[i *\
    \ 2], dat[i * 2 + 1]);\n        }\n    }\n\n    T fold(int l,int r) {\n      \
    \  l += seg_size;\n        r += seg_size;\n        T ret = def;\n        while(l\
    \ < r) {\n            if(l & 1) ret = operation(ret,dat[l++]);\n            if(r\
    \ & 1) ret = operation(dat[--r],ret);\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n        return ret;\n    }\n\n    int max_right(int l, std::function<bool(T)>\
    \ f) {\n        if(l == internal_size) return internal_size;\n        l += seg_size;\n\
    \        T sum = def;\n        do {\n            while(!(l & 1)) l >>= 1;\n  \
    \          if(!f(operation(sum, data[l]))) {\n                while(l < seg_size)\
    \ {\n                    l <<= 1;\n                    if(f(operation(sum, data[l])))\
    \ sum = operation(sum, data[l++]);\n                }\n                return\
    \ l - seg_size;\n            }\n        } while((l & -1) != l);\n        return\
    \ internal_size;\n    }\n\n    T operator[](int i) {return dat[i + seg_size];}\n\
    };\n"
  code: "template<typename T>\nclass SegmentTree {\n    int internal_size, seg_size;\n\
    \    const T def;\n    std::vector<T> dat;\n    std::function<T(T, T)> operation;\n\
    \    std::function<T(T, T)> update;\n\npublic:\n    explicit SegmentTree(const\
    \ int size, const T& e, std::function<T(T, T)> operation, std::function<T(T, T)>\
    \ update): internal_size(size), def(e), operation(operation), update(update) {\n\
    \        for(seg_size = 1; seg_size < internal_size; seg_size *= 2);\n       \
    \ dat = std::vector<T>(2 * seg_size, def);\n    }\n\n    explicit SegmentTree(std::vector<T>\
    \ v, const T& e,std::function<T(T, T)> operation, std::function<T(T, T)> update):\
    \ internal_size(v.size()), def(e), operation(operation), update(update) {\n  \
    \      for(seg_size = 1; seg_size < internal_size; seg_size *= 2);\n        dat.resize(2\
    \ * seg_size, def);\n\n        for(int i = 0; i < seg_size;i++) dat[i + seg_size]\
    \ = v[i];\n        for(int i = seg_size - 1; i >= 1; i--) {\n            dat[i]\
    \ = operation(dat[i * 2], dat[i * 2 + 1]);\n        }\n    }\n\n    void set_val(int\
    \ i, const T& value) {\n        i += seg_size;\n        dat[i] = update(dat[i],\
    \ value);\n        while(i > 1) {\n            i >>= 1;\n            dat[i] =\
    \ operation(dat[i * 2], dat[i * 2 + 1]);\n        }\n    }\n\n    T fold(int l,int\
    \ r) {\n        l += seg_size;\n        r += seg_size;\n        T ret = def;\n\
    \        while(l < r) {\n            if(l & 1) ret = operation(ret,dat[l++]);\n\
    \            if(r & 1) ret = operation(dat[--r],ret);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return ret;\n    }\n\n    int max_right(int\
    \ l, std::function<bool(T)> f) {\n        if(l == internal_size) return internal_size;\n\
    \        l += seg_size;\n        T sum = def;\n        do {\n            while(!(l\
    \ & 1)) l >>= 1;\n            if(!f(operation(sum, data[l]))) {\n            \
    \    while(l < seg_size) {\n                    l <<= 1;\n                   \
    \ if(f(operation(sum, data[l]))) sum = operation(sum, data[l++]);\n          \
    \      }\n                return l - seg_size;\n            }\n        } while((l\
    \ & -1) != l);\n        return internal_size;\n    }\n\n    T operator[](int i)\
    \ {return dat[i + seg_size];}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree.cpp
  requiredBy: []
  timestamp: '2021-11-21 13:14:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/yosupo-judge/SegmentTree-PointAddRangeSum.test.cpp
  - Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp
  - Test/AOJ/SegmentTree-RangeSumQuery.test.cpp
documentation_of: DataStructure/SegmentTree.cpp
layout: document
title: Segment Tree
---

## 説明

配列に対する 1 点更新クエリと区間求値クエリを高速に処理できる。

- `SegmentTree<T> seg(int size, T e, std::function<T(T, T)> operation, std::function<T(T, T)> update)` : 以下のような配列 `A` を構成する。計算量 $O(size)$
    - `size` : 配列の長さ
    - `e` : `T`の単位元かつ `A` の全ての要素の初期値
    - `operation` : 求値クエリで使う二項演算
    - `update` : 更新クエリで使う二項演算
- `SegmentTree<T> seg(std::vector<T> v, T e, std::function<T(T, T)> operation, std::function<T(T, T)>` : 配列 `v` で初期化したものを構成する。計算量 $O(size)$
- `void seg.set_val(int i, T x)` : `A[i] = update(A[i], x)` の操作を行う。計算量 $O(\log size)$
- `T seg.fold(int l, int r)` : `operation(A[l], A[l + 1], …, A[r - 1])` を求める。計算量 $O(\log size)$
- `T seg[i]` : `A[i]` を返す。計算量 $O(1)$
- `int seg.max_right(int l, std::function<bool(T)> f)` : `f(A[l], A[l + 1], …, A[r]) == true` を満たす最大の `r` を求める。計算量 $O(\log size)$


**注意** 上に書かれている計算量は `operation` 、 `update` が定数時間で動くものと仮定して書かれている。これらの内部の計算量が $O(f(n))$ だった場合、全ての計算量が $O(f(n))$ 倍される。
