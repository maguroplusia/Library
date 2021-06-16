---
title: Sparse Table
documentation_of: ../DataStructure/SparseTable.cpp
---

## 説明

ある区間に対する最小値・最大値などのクエリを処理する。

- `SparseTable(vector<T> v) st` : `v`を表現する Sparse Table を作成する。`v`のサイズを $n$ とすると計算量は $O(n \log n)$
- `T st.query(int l,int r)` : `min(v[l], v[l + 1], … , v[r - 1])`を求める。計算量 $O(1)$

※ クエリで用いる演算は min だけでなく[冪等半群（英版版 Wikipedia）](https://en.wikipedia.org/wiki/Band_(algebra))であればどれでも出来る。todo : min 以外にも対応出来るようにする
