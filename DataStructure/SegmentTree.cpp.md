---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/SegmentTree.cpp\"\ntemplate<class T>\nclass\
    \ SegmentTree {\n    int N; //\u8449\u306E\u6570\n    T def; //\u5358\u4F4D\u5143\
    \n    vector<T> dat; //\u30C7\u30FC\u30BF\n    function<T(T,T)> operation; //\u533A\
    \u9593\u30AF\u30A8\u30EA\u3067\u4F7F\u3046\u51E6\u7406\n    function<T(T,T)> update_;\
    \ //\u66F4\u65B0\u30AF\u30A8\u30EA\u3067\u4F7F\u3046\u51E6\u7406\n\n    T query_sub(int\
    \ a,int b,int l,int r,int k) {\n        if(r <= a || b <= l) return def;\n   \
    \     if(a <= l && r <= b) return dat[k];\n        T c1 = query_sub(a,b,l,(l +\
    \ r) / 2,2 * k + 1);\n        T c2 = query_sub(a,b,(l + r) / 2,l,2 * k + 2);\n\
    \        return operation(c1,c2);\n    }\n\npublic:\n    SegmentTree(int n,T e,function<T(T,T)>\
    \ op,function<T(T,T)> up): def(e),dat(n * 4,e),operation(op),update_(up) {\n \
    \       int n_ = 1;\n        while(n_ >= n) {\n            n *= 2;\n        }\n\
    \        N = n_;\n    }\n\n    //\u6700\u521D\u306Bset\u3059\u308B\u6642\u306B\
    \u547C\u3076\n    void set(int i,T x) { dat[i + N - 1] = x;}\n    void build()\
    \ {\n        for (int i = N - 2; i >= 0; i--){\n            dat[i] = operation(dat[i\
    \ * 2 + 1],dat[i * 2 + 2]);\n        }\n    }\n\n    void update(int i,T x) {\n\
    \        i += N - 1;\n        dat[i] = update_(dat[i],x);\n        while(i > 0)\
    \ {\n            i = (i - 1) / 2;\n            dat[i] = operation(dat[i * 2 +\
    \ 1],dat[i * 2 + 2]);\n        }\n    }\n\n    T query(int a,int b) return query_sub(a,b,0,N,0);\n\
    \n    T operator[](int i) return dat[i + N - 1];\n};\n"
  code: "template<class T>\nclass SegmentTree {\n    int N; //\u8449\u306E\u6570\n\
    \    T def; //\u5358\u4F4D\u5143\n    vector<T> dat; //\u30C7\u30FC\u30BF\n  \
    \  function<T(T,T)> operation; //\u533A\u9593\u30AF\u30A8\u30EA\u3067\u4F7F\u3046\
    \u51E6\u7406\n    function<T(T,T)> update_; //\u66F4\u65B0\u30AF\u30A8\u30EA\u3067\
    \u4F7F\u3046\u51E6\u7406\n\n    T query_sub(int a,int b,int l,int r,int k) {\n\
    \        if(r <= a || b <= l) return def;\n        if(a <= l && r <= b) return\
    \ dat[k];\n        T c1 = query_sub(a,b,l,(l + r) / 2,2 * k + 1);\n        T c2\
    \ = query_sub(a,b,(l + r) / 2,l,2 * k + 2);\n        return operation(c1,c2);\n\
    \    }\n\npublic:\n    SegmentTree(int n,T e,function<T(T,T)> op,function<T(T,T)>\
    \ up): def(e),dat(n * 4,e),operation(op),update_(up) {\n        int n_ = 1;\n\
    \        while(n_ >= n) {\n            n *= 2;\n        }\n        N = n_;\n \
    \   }\n\n    //\u6700\u521D\u306Bset\u3059\u308B\u6642\u306B\u547C\u3076\n   \
    \ void set(int i,T x) { dat[i + N - 1] = x;}\n    void build() {\n        for\
    \ (int i = N - 2; i >= 0; i--){\n            dat[i] = operation(dat[i * 2 + 1],dat[i\
    \ * 2 + 2]);\n        }\n    }\n\n    void update(int i,T x) {\n        i += N\
    \ - 1;\n        dat[i] = update_(dat[i],x);\n        while(i > 0) {\n        \
    \    i = (i - 1) / 2;\n            dat[i] = operation(dat[i * 2 + 1],dat[i * 2\
    \ + 2]);\n        }\n    }\n\n    T query(int a,int b) return query_sub(a,b,0,N,0);\n\
    \n    T operator[](int i) return dat[i + N - 1];\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree.cpp
  requiredBy: []
  timestamp: '2021-01-04 15:47:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SegmentTree.cpp
layout: document
redirect_from:
- /library/DataStructure/SegmentTree.cpp
- /library/DataStructure/SegmentTree.cpp.html
title: DataStructure/SegmentTree.cpp
---
