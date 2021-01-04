template<typename T>
class SegmentTree {
    int N; //葉の数
    T def; //単位元
    vector<T> dat; //データ
    function<T(T,T)> operation_; //区間クエリで使う処理
    function<T(T,T)> update_; //更新クエリで使う処理

    T query_sub(int a,int b,int l,int r,int k) {
        if(r <= a || b <= l) return def;
        if(a <= l && r <= b) return dat[k];
        T c1 = query_sub(a,b,l,(l + r) / 2,2 * k + 1);
        T c2 = query_sub(a,b,(l + r) / 2,r,2 * k + 2);
        return operation_(c1,c2);
    }

public:
    SegmentTree(int n,T e,function<T(T,T)> op,function<T(T,T)> up): def(e),operation_(op),update_(up) {
        int n_ = 1;
        while(n > n_) {
            n_ *= 2;
        }
        N = n_;
        dat = vector<T>(2 * N - 1,def);
    }

    //最初にsetする時に呼ぶ
    void set(int i,T x) { dat[i + N - 1] = x;}
    void build() {
        for (int i = N - 2; i >= 0; i--){
            dat[i] = operation_(dat[i * 2 + 1],dat[i * 2 + 2]);
        }
    }

    //i番目の値を更新する
    void update(int i,T x) {
        i += N - 1;
        dat[i] = update_(dat[i],x);
        while(i > 0) {
            i = (i - 1) / 2;
            dat[i] = operation_(dat[i * 2 + 1],dat[i * 2 + 2]);
        }
    }

    //operator(a,a + 1,…,b - 1)を求める
    T query(int a,int b) {return query_sub(a,b,0,N,0);}

    T operator[](int i) {return dat[i + N - 1];}
};
