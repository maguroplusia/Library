---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/LazySegmentTree.cpp\"\n/*\n    X:\u5024\u914D\
    \u5217\u306E\u578B\n    M:\u9045\u5EF6\u914D\u5217\u306E\u578B\n*/\ntemplate<typename\
    \ X,typename M>\nclass LazySegmentTree {\n    using FX = function<X(X,X)>;\n \
    \   using FA = function<X(X,M,int,int)>;\n    using FM = function<M(M,M)>;\n \
    \   int N; //\u8981\u7D20\u6570\n    X xdef; //X\u306E\u5358\u4F4D\u5143\n   \
    \ M mdef; //M\u306E\u5358\u4F4D\u5143\n    vector<X> dat; //\u5024\u914D\u5217\
    \n    vector<M> lazy; //\u9045\u5EF6\u914D\u5217\n    FX fx; //\u5024\u914D\u5217\
    \u3067\u4E0B\u304B\u3089\u66F4\u65B0\u3059\u308B\u305F\u3081\u306E\u95A2\u6570\
    \n    FA fa; //\u9045\u5EF6\u914D\u5217\u304B\u3089\u5024\u914D\u5217\u306B\u4F1D\
    \u64AD\u3059\u308B\u305F\u3081\u306E\u95A2\u6570\n    FM fm; //\u9045\u5EF6\u914D\
    \u5217\u5185\u3067M\u3092\u66F4\u65B0\u3059\u308B\u305F\u3081\u306E\u95A2\u6570\
    \n\n    //\u5024\u914D\u5217\u306Ek\u756A\u76EE\u306E\u5024\u3092\u6B63\u3057\u3044\
    \u5024\u306B\u3059\u308B\n    void prop(int k,int l,int r) {\n        if(lazy[k]\
    \ == em) return; //\u66F4\u65B0\u304C\u7121\u3051\u308C\u3070\u7D42\u4E86\n  \
    \      //\u8449\u3067\u7121\u3051\u308C\u3070\u9045\u5EF6\u914D\u5217\u3092\u4E0B\
    \u306B\u4F1D\u64AD\u3059\u308B\n        if(k < N - 1) {\n            lazy[k *\
    \ 2 + 1] = fm(lazy[k * 2 + 1],lazy[k]);\n            lazy[k * 2 + 2] = fm(lazy[k\
    \ * 2 + 2],lazy[k]);\n        }\n        dat[k] = fa(dat[k],lazy[k],l,r);\n  \
    \      lazy[k] = em;\n    }\n\n    //\u5024\u914D\u5217\u306E[a,b)\u756A\u76EE\
    \u306Bm\u3092\u4F5C\u7528\u3055\u305B\u308B\n    void update_sub(int a,int b,int\
    \ l,int r,int k,M m) {\n        prop(k,l,r);\n        if(a <= l && r <= b) {\n\
    \            lazy[k] = fm(m,lazy[k]);\n            prop(k,l,r);\n        }\n \
    \       else if(a < r || l < b) {\n            update_sub(a,b,l,(l + r) / 2,k\
    \ * 2 + 1,m); //\u5DE6\u306E\u5B50\n            update_sub(a,b,(l + r) / 2,r,k\
    \ * 2 + 2,m); //\u53F3\u306E\u5B50\n            dat[k] = fx(dat[k * 2 + 1],dat[k\
    \ * 2 + 2]);\n        }\n    }\n\n    //\u5024\u914D\u5217\u306E[a,b)\u5168\u3066\
    \u3067fx\u3092\u4F5C\u7528\u3055\u305B\u305F\u5024\u3092\u6C42\u3081\u308B\n \
    \   void query_sub(int a,int b,int l,int r,int k) {\n        prop(k,l,r);\n  \
    \      if (r <= a || b <= l) {\n            return ex;\n        }\n        else\
    \ if (a <= l && r <= b) {\n            return dat[k];\n        }\n        else\
    \ {\n            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2); //\u53F3\u306E\
    \u5B50\n            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r); //\u5DE6\
    \u306E\u5B50\n            return fx(vl, vr);\n        }\n    }\n\npublic:\n  \
    \  LazySegmentTree(int n,X ex,M em,FX fx_,FA fa_,FM fm_): N(n),xdef(ex),mdef(em),fx(fx_),fa(fa_),fm(fm_)\
    \ {\n        int n_ = 1;\n        while(n > n_) {\n            n_ *= 2;\n    \
    \    }\n        N = n_;\n        dat = vector<X>(N,ex);\n        lazy = vector<M>(N,em);\n\
    \    }\n\n    //\u6700\u521D\u306Bset\u3059\u308B\u3068\u304D\u306B\u547C\u3076\
    \n    void set(int i,X x) {dat[i + N - 1] = x;}\n    void build() {\n        for(int\
    \ i = N - 2;i >= 0;i--) {\n            dat[i] = fx(dat[i * 2 + 1],dat[i * 2 +\
    \ 2]);\n        }\n    }\n\n    void update(int a,int b,M m) {update_sub(a,b,0,N,m);}\n\
    \n    void query(int a,int b) {return query_sub(a,b,0,N,0);}\n};\n"
  code: "/*\n    X:\u5024\u914D\u5217\u306E\u578B\n    M:\u9045\u5EF6\u914D\u5217\u306E\
    \u578B\n*/\ntemplate<typename X,typename M>\nclass LazySegmentTree {\n    using\
    \ FX = function<X(X,X)>;\n    using FA = function<X(X,M,int,int)>;\n    using\
    \ FM = function<M(M,M)>;\n    int N; //\u8981\u7D20\u6570\n    X xdef; //X\u306E\
    \u5358\u4F4D\u5143\n    M mdef; //M\u306E\u5358\u4F4D\u5143\n    vector<X> dat;\
    \ //\u5024\u914D\u5217\n    vector<M> lazy; //\u9045\u5EF6\u914D\u5217\n    FX\
    \ fx; //\u5024\u914D\u5217\u3067\u4E0B\u304B\u3089\u66F4\u65B0\u3059\u308B\u305F\
    \u3081\u306E\u95A2\u6570\n    FA fa; //\u9045\u5EF6\u914D\u5217\u304B\u3089\u5024\
    \u914D\u5217\u306B\u4F1D\u64AD\u3059\u308B\u305F\u3081\u306E\u95A2\u6570\n   \
    \ FM fm; //\u9045\u5EF6\u914D\u5217\u5185\u3067M\u3092\u66F4\u65B0\u3059\u308B\
    \u305F\u3081\u306E\u95A2\u6570\n\n    //\u5024\u914D\u5217\u306Ek\u756A\u76EE\u306E\
    \u5024\u3092\u6B63\u3057\u3044\u5024\u306B\u3059\u308B\n    void prop(int k,int\
    \ l,int r) {\n        if(lazy[k] == em) return; //\u66F4\u65B0\u304C\u7121\u3051\
    \u308C\u3070\u7D42\u4E86\n        //\u8449\u3067\u7121\u3051\u308C\u3070\u9045\
    \u5EF6\u914D\u5217\u3092\u4E0B\u306B\u4F1D\u64AD\u3059\u308B\n        if(k < N\
    \ - 1) {\n            lazy[k * 2 + 1] = fm(lazy[k * 2 + 1],lazy[k]);\n       \
    \     lazy[k * 2 + 2] = fm(lazy[k * 2 + 2],lazy[k]);\n        }\n        dat[k]\
    \ = fa(dat[k],lazy[k],l,r);\n        lazy[k] = em;\n    }\n\n    //\u5024\u914D\
    \u5217\u306E[a,b)\u756A\u76EE\u306Bm\u3092\u4F5C\u7528\u3055\u305B\u308B\n   \
    \ void update_sub(int a,int b,int l,int r,int k,M m) {\n        prop(k,l,r);\n\
    \        if(a <= l && r <= b) {\n            lazy[k] = fm(m,lazy[k]);\n      \
    \      prop(k,l,r);\n        }\n        else if(a < r || l < b) {\n          \
    \  update_sub(a,b,l,(l + r) / 2,k * 2 + 1,m); //\u5DE6\u306E\u5B50\n         \
    \   update_sub(a,b,(l + r) / 2,r,k * 2 + 2,m); //\u53F3\u306E\u5B50\n        \
    \    dat[k] = fx(dat[k * 2 + 1],dat[k * 2 + 2]);\n        }\n    }\n\n    //\u5024\
    \u914D\u5217\u306E[a,b)\u5168\u3066\u3067fx\u3092\u4F5C\u7528\u3055\u305B\u305F\
    \u5024\u3092\u6C42\u3081\u308B\n    void query_sub(int a,int b,int l,int r,int\
    \ k) {\n        prop(k,l,r);\n        if (r <= a || b <= l) {\n            return\
    \ ex;\n        }\n        else if (a <= l && r <= b) {\n            return dat[k];\n\
    \        }\n        else {\n            X vl = query_sub(a, b, k * 2 + 1, l, (l\
    \ + r) / 2); //\u53F3\u306E\u5B50\n            X vr = query_sub(a, b, k * 2 +\
    \ 2, (l + r) / 2, r); //\u5DE6\u306E\u5B50\n            return fx(vl, vr);\n \
    \       }\n    }\n\npublic:\n    LazySegmentTree(int n,X ex,M em,FX fx_,FA fa_,FM\
    \ fm_): N(n),xdef(ex),mdef(em),fx(fx_),fa(fa_),fm(fm_) {\n        int n_ = 1;\n\
    \        while(n > n_) {\n            n_ *= 2;\n        }\n        N = n_;\n \
    \       dat = vector<X>(N,ex);\n        lazy = vector<M>(N,em);\n    }\n\n   \
    \ //\u6700\u521D\u306Bset\u3059\u308B\u3068\u304D\u306B\u547C\u3076\n    void\
    \ set(int i,X x) {dat[i + N - 1] = x;}\n    void build() {\n        for(int i\
    \ = N - 2;i >= 0;i--) {\n            dat[i] = fx(dat[i * 2 + 1],dat[i * 2 + 2]);\n\
    \        }\n    }\n\n    void update(int a,int b,M m) {update_sub(a,b,0,N,m);}\n\
    \n    void query(int a,int b) {return query_sub(a,b,0,N,0);}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/LazySegmentTree.cpp
  requiredBy: []
  timestamp: '2021-01-04 18:25:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/LazySegmentTree.cpp
layout: document
redirect_from:
- /library/DataStructure/LazySegmentTree.cpp
- /library/DataStructure/LazySegmentTree.cpp.html
title: DataStructure/LazySegmentTree.cpp
---
