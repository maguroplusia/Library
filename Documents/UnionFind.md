---
title: Union-Find
documentation_of: ../DataStructure/UnionFind.cpp
---

## 説明

別名 Disjoint Set Union 。2つの要素が含まれている集合の併合や、2つの要素が同じ集合に含まれているかの判定などが高速に出来る。実装には根つき木を利用している。

- `UnionFind uf(int n)` : それぞれの要素数が 1 である n 個の集合を生成する。
- `int uf.find(int x)` : `x`が属する集合を表す根つき木の頂点を返す。計算量 $O(\alpha(n))$
- `void unite(int x,int y)` : `x`が属する集合と`y`が属する集合を併合する。計算量 $O(\alpha(n))$
- `bool same(int x,int y)` : `x`と`y`が同じ集合に属しているかを判定する。計算量 $O(\alpha(n))$
- `int size(int x)` : `x`が属している集合の要素数を返す。計算量 $O(\alpha(n))$

※ $\alpha(n)$ はアッカーマン関数の逆関数を表す。実用上は定数と見なせる。
