---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SparseTable.cpp
    title: Sparse Table
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Test/yosupo-judge/SparseTable.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 1 \"Other/Template.cpp\"\ntypedef long long ll;\nconstexpr\
    \ int Inf = 2000000030;\nconstexpr long long INF= 2000000000000000000;\n\ntemplate<typename\
    \ T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return\
    \ false; }\ntemplate<typename T> inline bool chmin(T &a, T b) { if (a > b) { a\
    \ = b; return true; } return false; }\n#line 1 \"DataStructure/SparseTable.cpp\"\
    \ntemplate <typename T>\nclass SparseTable {\n    vector<vector<T>> table;\n \
    \   vector<int> lookup;\n\npublic:\n\n    SparseTable(vector<T> v) {\n       \
    \ int b = 0;\n\n        while((1 << b) <= v.size()) {\n            b++;\n    \
    \    }\n\n        table.resize(b,vector<T>(1 << b));\n\n        for(int i = 0;i\
    \ < v.size();i++) {\n            table[0][i] = v[i];\n        }\n\n        for(int\
    \ i = 1;i < b;i++) {\n            for(int j = 0;j + (1 << i) <= (1 << b);j++)\
    \ {\n                table[i][j] = min(table[i - 1][j],table[i - 1][j + (1 <<\
    \ (i - 1))]);\n            }\n        }\n\n        lookup.resize(v.size() + 1);\n\
    \        \n        for(int i = 2;i < lookup.size();i++) {\n            lookup[i]\
    \ = lookup[i >> 1] + 1;\n        }\n    }\n\n    //query(l,r) = \u533A\u9593[l,r)\u306E\
    \u6700\u5C0F\u5024\u3092\u8FD4\u3059\n    T query(int l,int r) {\n        int\
    \ b = lookup[r - l];\n        return min(table[b][l],table[b][r - (1 << b)]);\n\
    \    }\n};\n#line 8 \"Test/yosupo-judge/SparseTable.test.cpp\"\n\nint main() {\n\
    \    int N,Q;\n    cin >> N >> Q;\n    vector<int> vec(N);\n    for(int i = 0;i\
    \ < N;i++) {\n        cin >> vec.at(i);\n    }\n    SparseTable st(vec);\n   \
    \ for(int i = 0;i < Q;i++) {\n        int l,r;\n        cin >> l >> r;\n     \
    \   cout << st.query(l,r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#include\"../../Other/Template.cpp\"\n#include\"../../DataStructure/SparseTable.cpp\"\
    \n\nint main() {\n    int N,Q;\n    cin >> N >> Q;\n    vector<int> vec(N);\n\
    \    for(int i = 0;i < N;i++) {\n        cin >> vec.at(i);\n    }\n    SparseTable\
    \ st(vec);\n    for(int i = 0;i < Q;i++) {\n        int l,r;\n        cin >> l\
    \ >> r;\n        cout << st.query(l,r) << endl;\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - DataStructure/SparseTable.cpp
  isVerificationFile: true
  path: Test/yosupo-judge/SparseTable.test.cpp
  requiredBy: []
  timestamp: '2021-06-16 19:56:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-judge/SparseTable.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-judge/SparseTable.test.cpp
- /verify/Test/yosupo-judge/SparseTable.test.cpp.html
title: Test/yosupo-judge/SparseTable.test.cpp
---
