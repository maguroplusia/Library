template <typename T>
class BinaryIndexedTree {
    int N;
    vector<T> bit;

    T sum_sub(int a) {
        a++;
        T ret = 0;
        if(a == 0) return ret;
        while(a > 0) {
            ret += bit[a];
            a -= a & -a;
        }
        return ret;
    }

public:

    BinaryIndexedTree(int n): N(n) {
        bit.assign(++n,0);
    }

    void add(int i,T x) {
        i++;
        if(i == 0) return;
        while(i < bit.size()) {
            bit[i] += x;
            i += i & -i;
        }
    }

    T sum(int a,int b) {
        return sum_sub(b - 1) - sum_sub(a - 1);
    }
};
