---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-judge/SegmentTree.test.cpp
    title: Test/yosupo-judge/SegmentTree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/SegmentTree.cpp\"\ntemplate<typename T>\n\
    class SegmentTree {\n    int N; //\u8449\u306E\u6570\n    T def; //\u5358\u4F4D\
    \u5143\n    vector<T> dat; //\u30C7\u30FC\u30BF\n    function<T(T,T)> operation_;\
    \ //\u533A\u9593\u30AF\u30A8\u30EA\u3067\u4F7F\u3046\u51E6\u7406\n    function<T(T,T)>\
    \ update_; //\u66F4\u65B0\u30AF\u30A8\u30EA\u3067\u4F7F\u3046\u51E6\u7406\n\n\
    \    T query_sub(int a,int b,int l,int r,int k) {\n        if(r <= a || b <= l)\
    \ return def;\n        if(a <= l && r <= b) return dat[k];\n        T c1 = query_sub(a,b,l,(l\
    \ + r) / 2,2 * k + 1);\n        T c2 = query_sub(a,b,(l + r) / 2,r,2 * k + 2);\n\
    \        return operation_(c1,c2);\n    }\n\npublic:\n    SegmentTree(int n,T\
    \ e,function<T(T,T)> op,function<T(T,T)> up): def(e),operation_(op),update_(up)\
    \ {\n        int n_ = 1;\n        while(n > n_) {\n            n_ *= 2;\n    \
    \    }\n        N = n_;\n        dat = vector<T>(2 * N - 1,def);\n    }\n\n  \
    \  //\u6700\u521D\u306Bset\u3059\u308B\u6642\u306B\u547C\u3076\n    void set(int\
    \ i,T x) { dat[i + N - 1] = x;}\n    void build() {\n        for (int i = N -\
    \ 2; i >= 0; i--){\n            dat[i] = operation_(dat[i * 2 + 1],dat[i * 2 +\
    \ 2]);\n        }\n    }\n\n    //i\u756A\u76EE\u306E\u5024\u3092\u66F4\u65B0\u3059\
    \u308B\n    void update(int i,T x) {\n        i += N - 1;\n        dat[i] = update_(dat[i],x);\n\
    \        while(i > 0) {\n            i = (i - 1) / 2;\n            dat[i] = operation_(dat[i\
    \ * 2 + 1],dat[i * 2 + 2]);\n        }\n    }\n\n    //[a,b)\u5168\u3066\u3067\
    operator\u3092\u4F5C\u7528\u3055\u305B\u305F\u5024\u3092\u6C42\u3081\u308B\n \
    \   T query(int a,int b) {return query_sub(a,b,0,N,0);}\n\n    T operator[](int\
    \ i) {return dat[i + N - 1];}\n};\n"
  code: "template<typename T>\nclass SegmentTree {\n    int N; //\u8449\u306E\u6570\
    \n    T def; //\u5358\u4F4D\u5143\n    vector<T> dat; //\u30C7\u30FC\u30BF\n \
    \   function<T(T,T)> operation_; //\u533A\u9593\u30AF\u30A8\u30EA\u3067\u4F7F\u3046\
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
    \ N - 1];}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree.cpp
  requiredBy: []
  timestamp: '2021-01-04 17:29:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-judge/SegmentTree.test.cpp
documentation_of: DataStructure/SegmentTree.cpp
layout: document
redirect_from:
- /library/DataStructure/SegmentTree.cpp
- /library/DataStructure/SegmentTree.cpp.html
title: DataStructure/SegmentTree.cpp
---
