template<typename T>
class SegmentTree {
    int internal_size, seg_size;
    const T def;
    std::vector<T> dat;
    std::function<T(T, T)> operation;
    std::function<T(T, T)> update;

public:
    explicit SegmentTree(const int size, const T& e, std::function<T(T, T)> operation, std::function<T(T, T)> update): internal_size(size), def(e), operation(operation), update(update) {
        for(seg_size = 1; seg_size < internal_size; seg_size *= 2);
        dat = std::vector<T>(2 * seg_size, def);
    }

    explicit SegmentTree(std::vector<T> v, const T& e,std::function<T(T, T)> operation, std::function<T(T, T)> update): internal_size(v.size()), def(e), operation(operation), update(update) {
        for(seg_size = 1; seg_size < internal_size; seg_size *= 2);
        dat.resize(2 * seg_size, def);

        for(int i = 0; i < seg_size;i++) dat[i + seg_size] = v[i];
        for(int i = seg_size - 1; i >= 1; i--) {
            dat[i] = operation(dat[i * 2], dat[i * 2 + 1]);
        }
    }

    void set_val(int i, const T& value) {
        i += seg_size;
        dat[i] = update(dat[i], value);
        while(i > 1) {
            i >>= 1;
            dat[i] = operation(dat[i * 2], dat[i * 2 + 1]);
        }
    }

    T fold(int l,int r) {
        l += seg_size;
        r += seg_size;
        T ret = def;
        while(l < r) {
            if(l & 1) ret = operation(ret,dat[l++]);
            if(r & 1) ret = operation(dat[--r],ret);
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }

    int max_right(int l, std::function<bool(T)> f) {
        if(l == internal_size) return internal_size;
        l += seg_size;
        T sum = def;
        do {
            while(!(l & 1)) l >>= 1;
            if(!f(operation(sum, dat[l]))) {
                while(l < seg_size) {
                    l <<= 1;
                    if(f(operation(sum, dat[l]))) sum = operation(sum, dat[l++]);
                }
                return l - seg_size;
            }
        } while((l & -1) != l);
        return internal_size;
    }

    T operator[](int i) {return dat[i + seg_size];}
};
