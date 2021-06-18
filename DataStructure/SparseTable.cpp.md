---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-judge/SparseTable.test.cpp
    title: Test/yosupo-judge/SparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/SparseTable.cpp\"\ntemplate <typename T>\n\
    class SparseTable {\n    vector<vector<T>> table;\n    vector<int> lookup;\n\n\
    public:\n\n    SparseTable(vector<T> v) {\n        int b = 0;\n\n        while((1\
    \ << b) <= v.size()) {\n            b++;\n        }\n\n        table.resize(b,vector<T>(1\
    \ << b));\n\n        for(int i = 0;i < v.size();i++) {\n            table[0][i]\
    \ = v[i];\n        }\n\n        for(int i = 1;i < b;i++) {\n            for(int\
    \ j = 0;j + (1 << i) <= (1 << b);j++) {\n                table[i][j] = min(table[i\
    \ - 1][j],table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n\n   \
    \     lookup.resize(v.size() + 1);\n\n        for(int i = 2;i < lookup.size();i++)\
    \ {\n            lookup[i] = lookup[i >> 1] + 1;\n        }\n    }\n\n    T query(int\
    \ l,int r) {\n        int b = lookup[r - l];\n        return min(table[b][l],table[b][r\
    \ - (1 << b)]);\n    }\n};\n"
  code: "template <typename T>\nclass SparseTable {\n    vector<vector<T>> table;\n\
    \    vector<int> lookup;\n\npublic:\n\n    SparseTable(vector<T> v) {\n      \
    \  int b = 0;\n\n        while((1 << b) <= v.size()) {\n            b++;\n   \
    \     }\n\n        table.resize(b,vector<T>(1 << b));\n\n        for(int i = 0;i\
    \ < v.size();i++) {\n            table[0][i] = v[i];\n        }\n\n        for(int\
    \ i = 1;i < b;i++) {\n            for(int j = 0;j + (1 << i) <= (1 << b);j++)\
    \ {\n                table[i][j] = min(table[i - 1][j],table[i - 1][j + (1 <<\
    \ (i - 1))]);\n            }\n        }\n\n        lookup.resize(v.size() + 1);\n\
    \n        for(int i = 2;i < lookup.size();i++) {\n            lookup[i] = lookup[i\
    \ >> 1] + 1;\n        }\n    }\n\n    T query(int l,int r) {\n        int b =\
    \ lookup[r - l];\n        return min(table[b][l],table[b][r - (1 << b)]);\n  \
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SparseTable.cpp
  requiredBy: []
  timestamp: '2021-06-18 21:14:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-judge/SparseTable.test.cpp
documentation_of: DataStructure/SparseTable.cpp
layout: document
title: Sparse Table
---

## 説明

ある区間に対する最小値・最大値などのクエリを処理する。

- `SparseTable(vector<T> v) st` : `v`を表現する Sparse Table を作成する。`v`のサイズを $n$ とすると計算量は $O(n \log n)$
- `T st.query(int l,int r)` : `min(v[l], v[l + 1], … , v[r - 1])`を求める。計算量 $O(1)$

※ クエリで用いる演算は min だけでなく[冪等半群（英版版 Wikipedia）](https://en.wikipedia.org/wiki/Band_(algebra))であればどれでも出来る。todo : min 以外にも対応出来るようにする
