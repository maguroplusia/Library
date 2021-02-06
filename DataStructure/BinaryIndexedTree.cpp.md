---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-judge/BinaryIndexedTree.test.cpp
    title: Test/yosupo-judge/BinaryIndexedTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/BinaryIndexedTree.cpp\"\ntemplate <typename\
    \ T>\nclass BinaryIndexedTree {\n    int N;\n    vector<T> bit;\n\n    //a\u756A\
    \u76EE\u307E\u3067\u306E\u548C\u3092\u8A08\u7B97\u3059\u308B\n    T sum_sub(int\
    \ a) {\n        a++;\n        T ret = 0;\n        if(a == 0) return ret;\n   \
    \     while(a > 0) {\n            ret += bit[a];\n            a -= a & -a;\n \
    \       }\n        return ret;\n    }\n\npublic:\n\n    BinaryIndexedTree(int\
    \ a): N(a) {\n        bit.assign(++a,0);\n    }\n\n    //A[a]\u306Bw\u3092\u52A0\
    \u7B97\u3059\u308B\n    void add(int a,T w) {\n        a++;\n        if(a == 0)\
    \ return;\n        while(a < bit.size()) {\n            bit[a] += w;\n       \
    \     a += a & -a;\n        }\n    }\n\n    T sum(int a,int b) {\n        return\
    \ sum_sub(b - 1) - sum_sub(a - 1);\n    }\n};\n"
  code: "template <typename T>\nclass BinaryIndexedTree {\n    int N;\n    vector<T>\
    \ bit;\n\n    //a\u756A\u76EE\u307E\u3067\u306E\u548C\u3092\u8A08\u7B97\u3059\u308B\
    \n    T sum_sub(int a) {\n        a++;\n        T ret = 0;\n        if(a == 0)\
    \ return ret;\n        while(a > 0) {\n            ret += bit[a];\n          \
    \  a -= a & -a;\n        }\n        return ret;\n    }\n\npublic:\n\n    BinaryIndexedTree(int\
    \ a): N(a) {\n        bit.assign(++a,0);\n    }\n\n    //A[a]\u306Bw\u3092\u52A0\
    \u7B97\u3059\u308B\n    void add(int a,T w) {\n        a++;\n        if(a == 0)\
    \ return;\n        while(a < bit.size()) {\n            bit[a] += w;\n       \
    \     a += a & -a;\n        }\n    }\n\n    T sum(int a,int b) {\n        return\
    \ sum_sub(b - 1) - sum_sub(a - 1);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryIndexedTree.cpp
  requiredBy: []
  timestamp: '2021-01-05 12:08:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-judge/BinaryIndexedTree.test.cpp
documentation_of: DataStructure/BinaryIndexedTree.cpp
layout: document
redirect_from:
- /library/DataStructure/BinaryIndexedTree.cpp
- /library/DataStructure/BinaryIndexedTree.cpp.html
title: DataStructure/BinaryIndexedTree.cpp
---
