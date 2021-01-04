template <typename T>
class BinaryIndexedTree {
    int N;
    vector<T> bit;

    //a番目までの和を計算する
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

	BinaryIndexedTree(int a): N(a) {
		bit.assign(++a,0);
	}

    //A[a]にwを加算する
    void add(int a,T w) {
        a++;
        if(a == 0) return;
        while(a < bit.size()) {
            bit[a] += w;
            a += a & -a;
        }
    }

    T sum(int a,int b) {
        return sum_sub(b - 1) - sum_sub(a - 1);
    }
};
