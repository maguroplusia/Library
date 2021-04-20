---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.cpp
    title: Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"Test/yosupo-judge/SegmentTree-PointAddRangeSum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include<bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Other/Template.cpp\"\
    \ntypedef long long ll;\nconstexpr int Inf = 1000000030;\nconstexpr ll INF= 2000000000000000000;\n\
    constexpr ll MOD = 1000000007;\nconst double PI = 3.1415926535897;\ntypedef pair<ll,ll>\
    \ P;\ntypedef pair<ll,P> PP;\n\ntemplate<class T> inline bool chmax(T &a, T b)\
    \ {\n    if (a < b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n\
    }\n\ntemplate<class T> inline bool chmin(T &a, T b) {\n    if (a > b) {\n    \
    \    a = b;\n        return 1;\n    }\n    return 0;\n}\n\n\nll mod(ll val, ll\
    \ M) {\n    val = val % M;\n    if(val < 0) {\n        val += M;\n    }\n    return\
    \ val;\n}\n\ntemplate<typename T>\nT RS(T N, T P, T M){\n    if(P == 0) {\n  \
    \      return 1;\n    }\n    if(P < 0) {\n        return 0;\n    }\n    if(P %\
    \ 2 == 0){\n        ll t = RS(N, P/2, M);\n        if(M == -1) return t * t;\n\
    \        return t * t % M;\n    }\n    if(M == -1) {\n        return N * RS(N,P\
    \ - 1,M);\n    }\n    return N * RS(N, P-1, M) % M;\n}\n#line 1 \"DataStructure/SegmentTree.cpp\"\
    \ntemplate<typename T>\nclass SegmentTree {\n    int N;\n    const T def;\n  \
    \  vector<T> dat;\n    function<T(T,T)> operation_;\n    function<T(T,T)> update_;\n\
    \n    T query_sub(int a,int b,int l,int r,int k) {\n        if(r <= a || b <=\
    \ l) return def;\n        if(a <= l && r <= b) return dat[k];\n        T c1 =\
    \ query_sub(a,b,l,(l + r) / 2,2 * k + 1);\n        T c2 = query_sub(a,b,(l + r)\
    \ / 2,r,2 * k + 2);\n        return operation_(c1,c2);\n    }\n\npublic:\n   \
    \ SegmentTree(int n,T e,function<T(T,T)> operation,function<T(T,T)> update): def(e),operation_(operation),update_(update)\
    \ {\n        int n_ = 1;\n        while(n > n_) {\n            n_ *= 2;\n    \
    \    }\n        N = n_;\n        dat = vector<T>(2 * N - 1,def);\n    }\n\n  \
    \  void set(int i,T x) { dat[i + N - 1] = x;}\n    void build() {\n        for\
    \ (int i = N - 2; i >= 0; i--){\n            dat[i] = operation_(dat[i * 2 + 1],dat[i\
    \ * 2 + 2]);\n        }\n    }\n\n    void update(int i,T x) {\n        i += N\
    \ - 1;\n        dat[i] = update_(dat[i],x);\n        while(i > 0) {\n        \
    \    i = (i - 1) / 2;\n            dat[i] = operation_(dat[i * 2 + 1],dat[i *\
    \ 2 + 2]);\n        }\n    }\n\n    T query(int a,int b) {return query_sub(a,b,0,N,0);}\n\
    \n    T operator[](int i) {return dat[i + N - 1];}\n};\n#line 8 \"Test/yosupo-judge/SegmentTree-PointAddRangeSum.test.cpp\"\
    \n\nint main() {\n    int N,Q;\n    cin >> N >> Q;\n    SegmentTree<ll> seg(N,(ll)0,\n\
    \    [](ll a,ll b){return a + b;},\n    [](ll a,ll b){return a + b;});\n    for(int\
    \ i = 0;i < N;i++) {\n        ll A;\n        cin >> A;\n        seg.set(i,A);\n\
    \    }\n    seg.build();\n    for(int i = 0;i < Q;i++) {\n        int t;\n   \
    \     cin >> t;\n        if(t == 0) {\n            int p;\n            ll x;\n\
    \            cin >> p >> x;\n            seg.update(p,x);\n        }\n       \
    \ else {\n            int l,r;\n            cin >> l >> r;\n            cout <<\
    \ seg.query(l,r) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../DataStructure/SegmentTree.cpp\"\n\nint main() {\n    int N,Q;\n\
    \    cin >> N >> Q;\n    SegmentTree<ll> seg(N,(ll)0,\n    [](ll a,ll b){return\
    \ a + b;},\n    [](ll a,ll b){return a + b;});\n    for(int i = 0;i < N;i++) {\n\
    \        ll A;\n        cin >> A;\n        seg.set(i,A);\n    }\n    seg.build();\n\
    \    for(int i = 0;i < Q;i++) {\n        int t;\n        cin >> t;\n        if(t\
    \ == 0) {\n            int p;\n            ll x;\n            cin >> p >> x;\n\
    \            seg.update(p,x);\n        }\n        else {\n            int l,r;\n\
    \            cin >> l >> r;\n            cout << seg.query(l,r) << endl;\n   \
    \     }\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - DataStructure/SegmentTree.cpp
  isVerificationFile: true
  path: Test/yosupo-judge/SegmentTree-PointAddRangeSum.test.cpp
  requiredBy: []
  timestamp: '2021-04-20 19:31:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-judge/SegmentTree-PointAddRangeSum.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-judge/SegmentTree-PointAddRangeSum.test.cpp
- /verify/Test/yosupo-judge/SegmentTree-PointAddRangeSum.test.cpp.html
title: Test/yosupo-judge/SegmentTree-PointAddRangeSum.test.cpp
---
