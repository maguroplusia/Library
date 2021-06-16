---
title: Bellman-Ford
documentation_of: ../Graph/BellmanFord.cpp
---

## 説明

重み付き（有向）グラフにおける最短経路問題を解くアルゴリズム。グラフの辺の重みは負になってもよい。また負閉路（重みの総和が負になる閉路）の検出も可能。

- `vector<long long> BellmanFord(int N,int M,vector<edge> es,int s)` : `N`頂点`M`辺のグラフ`es`の頂点`s`から全頂点の最短距離を求める。`s` からのパスが存在しない場合は `INF` を、負閉路の影響で最短距離が求まらない場合は `-INF` が返り値の配列に格納される。計算量 $O(NM)$
- `bool FindNegativeLoop(int N,int M,vector<edge> es,int s)` : グラフに負閉路が含まれているかどうかを確かめる。計算量 $O(NM)$
