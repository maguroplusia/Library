---
title: Binary Indexed Tree
documentation_of: ../DataStructure/BinaryIndexedTree.cpp
---

## 説明
別名 Fenwick Tree 。配列に対する1点更新クエリと区間和を求めるクエリを Segment Tree より高速に処理出来る。

- `BinaryIndexedTree<T> bit(int n)` : 長さ $n$ の配列 $A_0,\ A_1,\ A_2,\ \cdots ,\ A_{n - 1}$ を構築する。計算量 $O(N)$
- `void bit.add(int i,T x)` : `A[i] += x` を行う。計算量 $O(\log N)$
- `T bit.sum(int l,int r)` : `A[l] + A[l + 1] + … + A[r - 1]` を求める。計算量 $O(\log N)$