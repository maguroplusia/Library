template<typename T>
struct Mo {
    int internal_size, packet_size;
    std::vector<T> dat;
    std::vector<int> query_left;
    std::vector<int> query_right;
    
    Mo(int internal_size_, std::vector<T> dat_): internal_size(internal_size_), dat(dat_) {
        assert((int)dat.size() == internal_size);
        packet_size = std::max(1, int(internal_size / std::sqrt(internal_size)));
    };

    void add_query(int l, int r) {
        query_left.emplace_back(l);
        query_right.emplace_back(r);
    }

    template <typename AL, typename AR, typename DL, typename DR, typename REM>
    void build(const AL& add_left, const AR& add_right, const DL& delete_left, const DR& delete_right, const REM& out) {
        std::vector<int> order(query_left.size());
        std::iota(order.begin(), order.end(), 0);
        std::sort(order.begin(), order.end(), [&](int a,int b) {
            if(query_left[a] / packet_size != query_left[b] / packet_size) return query_left[a] / packet_size < query_left[b] / packet_size;
            return query_right[a] < query_right[b];
        });

        int current_left = 0;
        int current_right = 0;
        for(auto& x: order) {
            while(current_left > query_left[x]) add_left(--current_left);
            while(current_right < query_right[x]) add_right(current_right++);
            while(current_left < query_left[x]) delete_left(current_left++);
            while(current_right > query_right[x]) delete_right(--current_right);
            out(x);
        }
    }
};