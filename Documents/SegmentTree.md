---
title: Segment Tree
documentation_of: "../DataStructure/SegmentTree.cpp"
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
