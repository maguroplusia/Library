#include<bits/stdc++.h>
#include "../DataStructure/LazySegmentTree.cpp"

struct HeavyLightDecomposition{
    int node;
    std::vector<std::vector<int>> graph;
    std::vector<int> size, order, parent, top_vertex;

    HeavyLightDecomposition(int n): node(n) {
        graph.resize(n);
        size.resize(n);
        order.resize(n);
        parent.resize(n);
        top_vertex.resize(n);
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int dfs(int v, int p = -1) {
        int current_size = 0;
        int max_child_size = 0;
        int max_child_vertex = -1;
        for(auto& next : graph[v]) {
            if(next != p) {
                int child_size = dfs(next, v);
                current_size += child_size;
                if(max_child_size < child_size) {
                    max_child_size = child_size;
                    max_child_vertex = next;
                }
            }
        }

        top_vertex[max_child_vertex] = top_vertex[v];
        return size[v] = current_size + 1;
    }
    
};