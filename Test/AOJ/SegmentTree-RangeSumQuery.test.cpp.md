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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"Test/AOJ/SegmentTree-RangeSumQuery.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"Other/Template.cpp\"\ntypedef long long ll;\n\
    constexpr int Inf = 2000000030;\nconstexpr long long INF= 2000000000000000000;\n\
    \ntemplate<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return\
    \ true; } return false; }\ntemplate<typename T> inline bool chmin(T &a, T b) {\
    \ if (a > b) { a = b; return true; } return false; }\n#line 1 \"DataStructure/SegmentTree.cpp\"\
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
    \n    T operator[](int i) {return dat[i + N - 1];}\n};\n#line 8 \"Test/AOJ/SegmentTree-RangeSumQuery.test.cpp\"\
    \n\nint main() {\n    int N,Q;\n    cin >> N >> Q;\n    SegmentTree<int> seg(N,0,\n\
    \    [](int a,int b){return a + b;},\n    [](int a,int b){return a + b;});\n \
    \   for(int i = 0;i < Q;i++) {\n        int t;\n        cin >> t;\n        if(t\
    \ == 0) {\n            int p,x;\n            cin >> p >> x;\n            p--;\n\
    \            seg.update(p,x);\n        }\n        else {\n            int s,t;\n\
    \            cin >> s >> t;\n            s--;\n            t--;\n            cout\
    \ << seg.query(s,t + 1) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\"../../Other/Template.cpp\"\
    \n#include\"../../DataStructure/SegmentTree.cpp\"\n\nint main() {\n    int N,Q;\n\
    \    cin >> N >> Q;\n    SegmentTree<int> seg(N,0,\n    [](int a,int b){return\
    \ a + b;},\n    [](int a,int b){return a + b;});\n    for(int i = 0;i < Q;i++)\
    \ {\n        int t;\n        cin >> t;\n        if(t == 0) {\n            int\
    \ p,x;\n            cin >> p >> x;\n            p--;\n            seg.update(p,x);\n\
    \        }\n        else {\n            int s,t;\n            cin >> s >> t;\n\
    \            s--;\n            t--;\n            cout << seg.query(s,t + 1) <<\
    \ endl;\n        }\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - DataStructure/SegmentTree.cpp
  isVerificationFile: true
  path: Test/AOJ/SegmentTree-RangeSumQuery.test.cpp
  requiredBy: []
  timestamp: '2021-06-14 17:23:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/SegmentTree-RangeSumQuery.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/SegmentTree-RangeSumQuery.test.cpp
- /verify/Test/AOJ/SegmentTree-RangeSumQuery.test.cpp.html
title: Test/AOJ/SegmentTree-RangeSumQuery.test.cpp
---
