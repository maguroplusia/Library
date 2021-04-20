---
title: Binary Indexed Tree
documentation_of: ../DataStructure/BinaryIndexedTree.cpp
---

## 説明
別名 Fenwick Tree 。1点更新区間加算を Segment Tree より高速に処理出来る。

- `BinaryIndexedTree<T> bit(int n)` : 長さ $n$ の配列 $A_0,\ A_1,\ A_2,\ \cdots ,\ A_{n - 1}$ を構築する。計算量 $O(N)$
- `void bit.add(int i,T x)` : $A[i]$ に $x$ を加算する。計算量 $O(\log N)$
- `T bit.sum(int a,int b)` : $\sum_{i = a}^b A[i]$ を求める。計算量 $O(\log N)$
