---
title: Sliding Window Aggregation (SWAG)
documentation_of: ../DataStructure/SlidingWindowAggregation.cpp
---

## 説明
[半群](https://ja.wikipedia.org/wiki/%E5%8D%8A%E7%BE%A4) $(S,\bullet)$ とその配列 $(a_0,a_1,\cdots,a_{N - 1})$ を扱う。

実装は、キューをスタック 2 個で表現する方法を用いている。

- `SWAG<S> swag(std::function<S(S,S)>)` : 空の配列を作成する。
- `bool swag.empty()` : 配列が空であるかを確かめる。時間計算量 $O(1)$
- `S swag.fold_all()` : $a_0 \bullet a_1 \bullet \cdots \bullet a_{N - 1}$ を求める。時間計算量 $O(1)$
- `S swag.push(S x)` : 配列に $x$ を追加する。時間計算量 $O(1)$
- `S swag.pop()` : 配列の先頭の要素を削除する。時間計算量 $O(1)\ \mathrm{amortized}$