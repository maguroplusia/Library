/*
    X:値配列の型
    M:遅延配列の型
*/
template<typename X,typename M>
class LazySegmentTree {
    using FX = function<X(X,X)>;
    using FA = function<X(X,M)>;
    using FM = function<M(M,M)>;
    int N; //要素数
    const X xdef; //Xの単位元
    const M mdef; //Mの単位元
    vector<X> dat; //値配列
    vector<M> lazy; //遅延配列
    FX fx; //値配列で下から更新するための関数
    FA fa; //遅延配列から値配列に伝播するための関数
    FM fm; //遅延配列内でMを更新するための関数

    //値配列のk番目の値を正しい値にする
    void prop(int k) {
        if(lazy[k] == mdef) return; //更新が無ければ終了
        //葉で無ければ遅延配列を下に伝播する
        if(k < N - 1) {
            lazy[k * 2 + 1] = fm(lazy[k * 2 + 1],lazy[k]);
            lazy[k * 2 + 2] = fm(lazy[k * 2 + 2],lazy[k]);
        }
        dat[k] = fa(dat[k],lazy[k]);
        lazy[k] = mdef;
    }

    //値配列の[a,b)番目にmを作用させる
    void update_sub(int a,int b,int l,int r,int k,M m) {
        prop(k);
        if(a <= l && r <= b) {
            lazy[k] = fm(lazy[k],m);
            prop(k);
        }
        else if(a < r && l < b) {
            update_sub(a,b,l,(l + r) / 2,k * 2 + 1,m); //左の子
            update_sub(a,b,(l + r) / 2,r,k * 2 + 2,m); //右の子
            dat[k] = fx(dat[k * 2 + 1],dat[k * 2 + 2]);
        }
    }

    //値配列の[a,b)全てでfxを作用させた値を求める
    X query_sub(int a,int b,int l,int r,int k) {
        prop(k);
        if (r <= a || b <= l) {
            return xdef;
        }
        else if (a <= l && r <= b) {
            return dat[k];
        }
        else {
            X vl = query_sub(a,b,l,(l + r) / 2,k * 2 + 1); //右の子
            X vr = query_sub(a,b,(l + r) / 2,r,k * 2 + 2); //左の子
            return fx(vl,vr);
        }
    }

public:
    LazySegmentTree(int n,X ex,M em,FX fx_,FA fa_,FM fm_): N(),xdef(ex),mdef(em),fx(fx_),fa(fa_),fm(fm_),dat(n * 4,ex),lazy(n * 4,em) {
        int x = 1;
        while(n > x) x *= 2;
        N = x;
    }

    //最初にsetするときに呼ぶ
    void set(int i,X x) {dat[i + N - 1] = x;}
    void build() {
        for(int i = N - 2;i >= 0;i--) {
            dat[i] = fx(dat[i * 2 + 1],dat[i * 2 + 2]);
        }
    }

    void update(int a,int b,M m) {update_sub(a,b,0,N,0,m);}

    X query(int a,int b) {return query_sub(a,b,0,N,0);}
};
