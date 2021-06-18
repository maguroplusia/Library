---
title: Warshall-Floyd
documentation_of: ../Graph/WarshallFloyd.cpp
---

## 説明
重み付き（有向）グラフにおける全頂点間の最短距離を求める。

- `vector<vector<long long>> WarshallFloyd(int N,vector<vector<long long>> dist)` : `dist[i][j]` = 頂点`i`と頂点`j`を結ぶ辺の距離（ただし`i`と`j`の間に辺が存在しないならば`INF`）である頂点数が`N`のグラフに対して、全頂点間の最短距離を求める。返り値は2次元配列に格納される（ただし頂点間に経路が存在しないならば`INF`）。計算量 $O(N^3)$

tips : このアルゴリズムは負の辺でも動作する。返り値の配列を`ret`とすると、`ret[i][i] < 0`となる`i`が存在するならばグラフには負閉路が含まれている。
