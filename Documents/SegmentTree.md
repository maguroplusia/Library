---
title: Segment Tree
documentation_of: "../DataStructure/SegmentTree.cpp"
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
