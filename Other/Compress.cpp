template<typename T>
struct Compress {
    std::vector<T> values;

    Compress() {}
    Compress(const vector<T>& vec): values(vec) {}

    void add(const T& x) {
        values.emplace_back(x);
    }

    void add(const vector<T>& vec) {
        std::copy(vec.begin(), vec.end(), std::back_inserter(values));
    }

    void build() {
        std::sort(values.begin(), values.end());
        std::erase(std::unique(values.begin(), values.end()), values.end());
    }

    int get(T x) {
        return std::lower_bound(values.begin(), values.end(), x) - values.begin();
    }

    const T& operator[](int x) {
        return values[x];
    }
};