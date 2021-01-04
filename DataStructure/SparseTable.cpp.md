---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yosupo-judge/SparseTable.test.cpp
    title: Test/yosupo-judge/SparseTable.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/SparseTable.cpp\"\ntemplate <typename T>\n\
    class SparseTable {\n    vector<vector<T>> table; //table[i][j] = j\u756A\u76EE\
    \u304B\u3089\u898B\u30662^i\u500B\u306E\u8981\u7D20\u306E\u6700\u5C0F\u5024\n\
    \    vector<int> lookup;\n\npublic:\n\n    //Sparse Table\u306E\u69CB\u7BC9\n\
    \    SparseTable(vector<T> v) {\n        //log\u3092\u53D6\u308B\n        int\
    \ b = 0;\n        while((1 << b) <= v.size()) {\n            b++;\n        }\n\
    \        table.resize(b,vector<T>(1 << b));\n        for(int i = 0;i < v.size();i++)\
    \ {\n            table[0][i] = v[i];\n        }\n        for(int i = 1;i < b;i++)\
    \ {\n            for(int j = 0;j + (1 << i) <= (1 << b);j++) {\n             \
    \   table[i][j] = min(table[i - 1][j],table[i - 1][j + (1 << (i - 1))]);\n   \
    \         }\n        }\n        lookup.resize(v.size() + 1);\n        for(int\
    \ i = 2;i < lookup.size();i++) {\n            lookup[i] = lookup[i >> 1] + 1;\n\
    \        }\n    }\n\n    //query(l,r) = \u533A\u9593[l,r)\u306E\u6700\u5C0F\u5024\
    \u3092\u8FD4\u3059\n    T query(int l,int r) {\n        int b = lookup[r - l];\n\
    \        return min(table[b][l],table[b][r - (1 << b)]);\n    }\n};\n"
  code: "template <typename T>\nclass SparseTable {\n    vector<vector<T>> table;\
    \ //table[i][j] = j\u756A\u76EE\u304B\u3089\u898B\u30662^i\u500B\u306E\u8981\u7D20\
    \u306E\u6700\u5C0F\u5024\n    vector<int> lookup;\n\npublic:\n\n    //Sparse Table\u306E\
    \u69CB\u7BC9\n    SparseTable(vector<T> v) {\n        //log\u3092\u53D6\u308B\n\
    \        int b = 0;\n        while((1 << b) <= v.size()) {\n            b++;\n\
    \        }\n        table.resize(b,vector<T>(1 << b));\n        for(int i = 0;i\
    \ < v.size();i++) {\n            table[0][i] = v[i];\n        }\n        for(int\
    \ i = 1;i < b;i++) {\n            for(int j = 0;j + (1 << i) <= (1 << b);j++)\
    \ {\n                table[i][j] = min(table[i - 1][j],table[i - 1][j + (1 <<\
    \ (i - 1))]);\n            }\n        }\n        lookup.resize(v.size() + 1);\n\
    \        for(int i = 2;i < lookup.size();i++) {\n            lookup[i] = lookup[i\
    \ >> 1] + 1;\n        }\n    }\n\n    //query(l,r) = \u533A\u9593[l,r)\u306E\u6700\
    \u5C0F\u5024\u3092\u8FD4\u3059\n    T query(int l,int r) {\n        int b = lookup[r\
    \ - l];\n        return min(table[b][l],table[b][r - (1 << b)]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SparseTable.cpp
  requiredBy: []
  timestamp: '2021-01-04 19:07:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yosupo-judge/SparseTable.test.cpp
documentation_of: DataStructure/SparseTable.cpp
layout: document
redirect_from:
- /library/DataStructure/SparseTable.cpp
- /library/DataStructure/SparseTable.cpp.html
title: DataStructure/SparseTable.cpp
---
