template<typename T>
struct Edge{
    int from,to;
    T cost;
};

template<typename T>
std::vector<T> bellman_ford(const int& node,const int& edge,const std::vector<Edge<T>>& graph,const int& start) {
    std::vector<T> dist(node,std::numeric_limits<T>::max());
    dist[start] = 0;

    for(int i = 0;i < node * 2;i++) {
        for(const auto& [from,to,cost]: graph) {
            if(dist[from] < std::numeric_limits<T>::max() && dist[from] + cost < dist[to])  {
                if(i >= node - 1) dist[to] = std::numeric_limits<T>::max() * static_cast<T>(-1);
                else dist[to] = dist[from] + cost;
            }
        }
    }

    return dist;
}

template<typename T>
bool find_negative_loop(const int& node,const int& edge,const std::vector<Edge<T>>& graph) {
    std::vector<T> dist(node);

    for(int i = 0;i < node;i++) {
        for(const auto& [from,to,cost]: graph) {
            if(dist[to] > dist[from] + cost && i == node - 1) {
                return true;
            }
        }
    }

    return false;
}
