---
title: Bellman-Ford
documentation_of: ../Graph/BellmanFord.cpp
---

## 説明

重み付き（有向）グラフにおける最短経路問題を解くアルゴリズム。グラフの辺の重みは負になってもよい。また負閉路（重みの総和が負になる閉路）の検出も可能。

- `int N,M` : $N$ はグラフの頂点の数、 $M$ はグラフの辺の数。
- `vector<edge> es` : グラフの辺の情報。`edge` は `int to,long long cost` で構成される。
- `vector<long long> BellmanFord(int s)` : 頂点`s`(0-indexed) から全頂点の最短距離を求める。`s` からのパスが存在しない場合は `INF` を、負閉路の影響で最短距離が求まらない場合は `-INF` が返り値の配列に格納される。計算量 $O(NM)$
- `bool FindNegativeLoop()` : グラフに負閉路が含まれているかどうかを確かめる。計算量 $O(NM)$
