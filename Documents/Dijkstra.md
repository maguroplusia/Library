---
title: Dijkstra
documentation_of: ../Graph/Dijkstra.cpp
---

## 説明

重み付き（有向）グラフにおける最短経路問題を解くアルゴリズム。グラフの重みは非負でないといけない。負の重みの辺がある場合は[Bellman-Ford法](https://maguroplusia.github.io/Library/Graph/BellmanFord.cpp)を使う。

- `int N` : グラフの頂点の数
- `vector<vector<edge>> graph` : グラフの情報（隣接リスト）
- `vector<long long> Dijkstra(int s)` : 頂点`s`から全頂点の最短距離を求める。計算量 $O(E + V \log V)$
- `vector<int> get_path(int t)` : 頂点`s`から頂点`t`までの最短経路の内 $1$ つを列挙する。
