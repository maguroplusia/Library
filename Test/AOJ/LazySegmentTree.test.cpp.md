---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LazySegmentTree.cpp
    title: DataStructure/LazySegmentTree.cpp
  - icon: ':question:'
    path: Other/Template.cpp
    title: Other/Template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F
  bundledCode: "#line 1 \"Test/AOJ/LazySegmentTree.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"Other/Template.cpp\"\ntypedef long long ll;\n\
    \ntemplate<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return\
    \ true; } return false; }\ntemplate<typename T> inline bool chmin(T &a, T b) {\
    \ if (a > b) { a = b; return true; } return false; }\n\ntemplate<typename T>\n\
    T modpow(T N, T P, T M){\n    if(P == 0) return 1;\n    if(P < 0) return 0;\n\
    \    if(P % 2 == 0){\n        T t = modpow(N, P/2, M);\n        if(M == -1) return\
    \ t * t;\n        return t * t % M;\n    }\n    if(M == -1) return N * modpow(N,P\
    \ - 1,M);\n    return N * modpow(N, P-1, M) % M;\n}\n#line 1 \"DataStructure/LazySegmentTree.cpp\"\
    \n/*\n    X:\u5024\u914D\u5217\u306E\u578B\n    M:\u9045\u5EF6\u914D\u5217\u306E\
    \u578B\n*/\ntemplate<typename X,typename M>\nclass LazySegmentTree {\n    using\
    \ FX = function<X(X,X)>;\n    using FA = function<X(X,M)>;\n    using FM = function<M(M,M)>;\n\
    \    int N; //\u8981\u7D20\u6570\n    const X xdef; //X\u306E\u5358\u4F4D\u5143\
    \n    const M mdef; //M\u306E\u5358\u4F4D\u5143\n    vector<X> dat; //\u5024\u914D\
    \u5217\n    vector<M> lazy; //\u9045\u5EF6\u914D\u5217\n    FX fx; //\u5024\u914D\
    \u5217\u3067\u4E0B\u304B\u3089\u66F4\u65B0\u3059\u308B\u305F\u3081\u306E\u95A2\
    \u6570\n    FA fa; //\u9045\u5EF6\u914D\u5217\u304B\u3089\u5024\u914D\u5217\u306B\
    \u4F1D\u64AD\u3059\u308B\u305F\u3081\u306E\u95A2\u6570\n    FM fm; //\u9045\u5EF6\
    \u914D\u5217\u5185\u3067M\u3092\u66F4\u65B0\u3059\u308B\u305F\u3081\u306E\u95A2\
    \u6570\n\n    //\u5024\u914D\u5217\u306Ek\u756A\u76EE\u306E\u5024\u3092\u6B63\u3057\
    \u3044\u5024\u306B\u3059\u308B\n    void prop(int k) {\n        if(lazy[k] ==\
    \ mdef) return; //\u66F4\u65B0\u304C\u7121\u3051\u308C\u3070\u7D42\u4E86\n   \
    \     //\u8449\u3067\u7121\u3051\u308C\u3070\u9045\u5EF6\u914D\u5217\u3092\u4E0B\
    \u306B\u4F1D\u64AD\u3059\u308B\n        if(k < N - 1) {\n            lazy[k *\
    \ 2 + 1] = fm(lazy[k * 2 + 1],lazy[k]);\n            lazy[k * 2 + 2] = fm(lazy[k\
    \ * 2 + 2],lazy[k]);\n        }\n        dat[k] = fa(dat[k],lazy[k]);\n      \
    \  lazy[k] = mdef;\n    }\n\n    //\u5024\u914D\u5217\u306E[a,b)\u756A\u76EE\u306B\
    m\u3092\u4F5C\u7528\u3055\u305B\u308B\n    void update_sub(int a,int b,int l,int\
    \ r,int k,M m) {\n        prop(k);\n        if(a <= l && r <= b) {\n         \
    \   lazy[k] = fm(lazy[k],m);\n            prop(k);\n        }\n        else if(a\
    \ < r && l < b) {\n            update_sub(a,b,l,(l + r) / 2,k * 2 + 1,m); //\u5DE6\
    \u306E\u5B50\n            update_sub(a,b,(l + r) / 2,r,k * 2 + 2,m); //\u53F3\u306E\
    \u5B50\n            dat[k] = fx(dat[k * 2 + 1],dat[k * 2 + 2]);\n        }\n \
    \   }\n\n    //\u5024\u914D\u5217\u306E[a,b)\u5168\u3066\u3067fx\u3092\u4F5C\u7528\
    \u3055\u305B\u305F\u5024\u3092\u6C42\u3081\u308B\n    X query_sub(int a,int b,int\
    \ l,int r,int k) {\n        prop(k);\n        if (r <= a || b <= l) {\n      \
    \      return xdef;\n        }\n        else if (a <= l && r <= b) {\n       \
    \     return dat[k];\n        }\n        else {\n            X vl = query_sub(a,b,l,(l\
    \ + r) / 2,k * 2 + 1); //\u53F3\u306E\u5B50\n            X vr = query_sub(a,b,(l\
    \ + r) / 2,r,k * 2 + 2); //\u5DE6\u306E\u5B50\n            return fx(vl,vr);\n\
    \        }\n    }\n\npublic:\n    LazySegmentTree(int n,X ex,M em,FX fx_,FA fa_,FM\
    \ fm_): N(),xdef(ex),mdef(em),fx(fx_),fa(fa_),fm(fm_),dat(n * 4,ex),lazy(n * 4,em)\
    \ {\n        int x = 1;\n        while(n > x) x *= 2;\n        N = x;\n    }\n\
    \n    //\u6700\u521D\u306Bset\u3059\u308B\u3068\u304D\u306B\u547C\u3076\n    void\
    \ set(int i,X x) {dat[i + N - 1] = x;}\n    void build() {\n        for(int i\
    \ = N - 2;i >= 0;i--) {\n            dat[i] = fx(dat[i * 2 + 1],dat[i * 2 + 2]);\n\
    \        }\n    }\n\n    void update(int a,int b,M m) {update_sub(a,b,0,N,0,m);}\n\
    \n    X query(int a,int b) {return query_sub(a,b,0,N,0);}\n};\n#line 8 \"Test/AOJ/LazySegmentTree.test.cpp\"\
    \n\nint main() {\n    int N,Q;\n    cin >> N >> Q;\n    LazySegmentTree<int,int>\
    \ seg(N,numeric_limits<int>::max(),-1,\n                        [](int a,int b){return\
    \ min(a,b);},\n                        [](int a,int b){return b;},\n         \
    \               [](int a,int b){return b;});\n    for(int i = 0;i < Q;i++) {\n\
    \        int type;\n        cin >> type;\n        if(type == 0) {\n          \
    \  int s,t,x;\n            cin >> s >> t >> x;\n            seg.update(s,t + 1,x);\n\
    \        }\n        else {\n            int s,t;\n            cin >> s >> t;\n\
    \            cout << seg.query(s,t + 1) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../DataStructure/LazySegmentTree.cpp\"\n\nint main() {\n    int\
    \ N,Q;\n    cin >> N >> Q;\n    LazySegmentTree<int,int> seg(N,numeric_limits<int>::max(),-1,\n\
    \                        [](int a,int b){return min(a,b);},\n                \
    \        [](int a,int b){return b;},\n                        [](int a,int b){return\
    \ b;});\n    for(int i = 0;i < Q;i++) {\n        int type;\n        cin >> type;\n\
    \        if(type == 0) {\n            int s,t,x;\n            cin >> s >> t >>\
    \ x;\n            seg.update(s,t + 1,x);\n        }\n        else {\n        \
    \    int s,t;\n            cin >> s >> t;\n            cout << seg.query(s,t +\
    \ 1) << endl;\n        }\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - DataStructure/LazySegmentTree.cpp
  isVerificationFile: true
  path: Test/AOJ/LazySegmentTree.test.cpp
  requiredBy: []
  timestamp: '2021-06-08 16:42:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/LazySegmentTree.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/LazySegmentTree.test.cpp
- /verify/Test/AOJ/LazySegmentTree.test.cpp.html
title: Test/AOJ/LazySegmentTree.test.cpp
---
