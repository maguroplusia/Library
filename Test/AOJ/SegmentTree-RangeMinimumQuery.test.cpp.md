---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.cpp
    title: DataStructure/SegmentTree.cpp
  - icon: ':heavy_check_mark:'
    path: Other/Template.cpp
    title: Other/Template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Other/Template.cpp\"\
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
    \ntemplate<typename T>\nclass SegmentTree {\n    int N; //\u8449\u306E\u6570\n\
    \    T def; //\u5358\u4F4D\u5143\n    vector<T> dat; //\u30C7\u30FC\u30BF\n  \
    \  function<T(T,T)> operation_; //\u533A\u9593\u30AF\u30A8\u30EA\u3067\u4F7F\u3046\
    \u51E6\u7406\n    function<T(T,T)> update_; //\u66F4\u65B0\u30AF\u30A8\u30EA\u3067\
    \u4F7F\u3046\u51E6\u7406\n\n    T query_sub(int a,int b,int l,int r,int k) {\n\
    \        if(r <= a || b <= l) return def;\n        if(a <= l && r <= b) return\
    \ dat[k];\n        T c1 = query_sub(a,b,l,(l + r) / 2,2 * k + 1);\n        T c2\
    \ = query_sub(a,b,(l + r) / 2,r,2 * k + 2);\n        return operation_(c1,c2);\n\
    \    }\n\npublic:\n    SegmentTree(int n,T e,function<T(T,T)> op,function<T(T,T)>\
    \ up): def(e),operation_(op),update_(up) {\n        int n_ = 1;\n        while(n\
    \ > n_) {\n            n_ *= 2;\n        }\n        N = n_;\n        dat = vector<T>(2\
    \ * N - 1,def);\n    }\n\n    //\u6700\u521D\u306Bset\u3059\u308B\u6642\u306B\u547C\
    \u3076\n    void set(int i,T x) { dat[i + N - 1] = x;}\n    void build() {\n \
    \       for (int i = N - 2; i >= 0; i--){\n            dat[i] = operation_(dat[i\
    \ * 2 + 1],dat[i * 2 + 2]);\n        }\n    }\n\n    //i\u756A\u76EE\u306E\u5024\
    \u3092\u66F4\u65B0\u3059\u308B\n    void update(int i,T x) {\n        i += N -\
    \ 1;\n        dat[i] = update_(dat[i],x);\n        while(i > 0) {\n          \
    \  i = (i - 1) / 2;\n            dat[i] = operation_(dat[i * 2 + 1],dat[i * 2\
    \ + 2]);\n        }\n    }\n\n    //[a,b)\u5168\u3066\u3067operator\u3092\u4F5C\
    \u7528\u3055\u305B\u305F\u5024\u3092\u6C42\u3081\u308B\n    T query(int a,int\
    \ b) {return query_sub(a,b,0,N,0);}\n\n    T operator[](int i) {return dat[i +\
    \ N - 1];}\n};\n#line 8 \"Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp\"\n\n\
    int main() {\n    int N,Q;\n    cin >> N >> Q;\n    SegmentTree<int> seg(N,numeric_limits<int>::max(),\n\
    \    [](int a,int b){return min(a,b);},\n    [](int a,int b){return b;});\n  \
    \  for(int i = 0;i < Q;i++) {\n        int t;\n        cin >> t;\n        if(t\
    \ == 0) {\n            int p,x;\n            cin >> p >> x;\n            seg.update(p,x);\n\
    \        }\n        else {\n            int s,t;\n            cin >> s >> t;\n\
    \            cout << seg.query(s,t + 1) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../DataStructure/SegmentTree.cpp\"\n\nint main() {\n    int N,Q;\n\
    \    cin >> N >> Q;\n    SegmentTree<int> seg(N,numeric_limits<int>::max(),\n\
    \    [](int a,int b){return min(a,b);},\n    [](int a,int b){return b;});\n  \
    \  for(int i = 0;i < Q;i++) {\n        int t;\n        cin >> t;\n        if(t\
    \ == 0) {\n            int p,x;\n            cin >> p >> x;\n            seg.update(p,x);\n\
    \        }\n        else {\n            int s,t;\n            cin >> s >> t;\n\
    \            cout << seg.query(s,t + 1) << endl;\n        }\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - DataStructure/SegmentTree.cpp
  isVerificationFile: true
  path: Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp
  requiredBy: []
  timestamp: '2021-01-05 13:22:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp
- /verify/Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp.html
title: Test/AOJ/SegmentTree-RangeMinimumQuery.test.cpp
---
