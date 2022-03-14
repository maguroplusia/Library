---
title: Bellman-Ford
documentation_of: ../Graph/BellmanFord.cpp
---

## 説明

重み付き（有向）グラフにおける最短経路問題を解くアルゴリズム。グラフの辺の重みは負になってもよい。また負閉路（重みの総和が負になる閉路）の検出も可能。

- `vector<T> bellman_ford(int node,int edge,vector<Edge<T>> graph,int start)` : 辺の情報をもった配列 `graph` で表される、頂点数 `node`、変数 `edge` のグラフにおいて、頂点 `start` から各頂点への最短経路を求める。返り値として長さ `node` の配列 `dist` が返される。
    - `dist[i]` = 頂点 `start` から頂点 `i` への最短距離、ただしパスが存在しない場合は `std::numeric_limits<T>::max()` を、負閉路の影響で最短距離が求まらない場合は `-std::numeric_limits<T>::max()` が返り値の配列に格納される。計算量 $O(node \times edge)$
- `bool find_negative_loop(int node,int edge,vector<Edge<T>> graph)` : グラフに負閉路が含まれているかどうかを確かめる。計算量 $O(node \times edge)$
