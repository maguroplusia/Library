---
title: Dijkstra
documentation_of: ../Graph/Dijkstra.cpp
---

## 説明

重み付き（有向）グラフにおける最短経路問題を解くアルゴリズム。グラフの重みは非負でないといけない。負の重みの辺がある場合は [Bellman-Ford法](https://maguroplusia.github.io/Library/Graph/BellmanFord.cpp) を使う。

- `vector<T> dijkstra(int node,vector<vector<Edge<T>> graph,int start)` : 隣接リストで表現された `node` 頂点のグラフ `graph` において、頂点 `start` から全頂点の最短距離を求める。返り値として長さ `node` の配列 `dist` が返される。辺の本数を $edge$ とおくと計算量 $O(edge + node \log node)$
    - `dist[i]` = 頂点 `s` から頂点 `i` までの最短距離、ただしパスが存在しない場合は `numeric_limits<T>::max()` が格納される
- `vector<int> get_path(int t)` :  頂点 `start` から頂点 `t` までの最短経路の内 1 つを列挙する。計算量 $O(node)$
