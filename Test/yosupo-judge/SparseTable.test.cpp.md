---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SparseTable.cpp
    title: DataStructure/SparseTable.cpp
  - icon: ':heavy_check_mark:'
    path: Other/Template.cpp
    title: Other/Template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
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
    \ int Inf = 1000000030;\nconstexpr ll INF= 2000000000000000000;\nconstexpr ll\
    \ MOD = 1000000007;\nconst double PI = 3.1415926535897;\ntypedef pair<ll,ll> P;\n\
    typedef pair<ll,P> PP;\n\ntemplate<class T> inline bool chmax(T &a, T b) {\n \
    \   if (a < b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n}\n\
    \ntemplate<class T> inline bool chmin(T &a, T b) {\n    if (a > b) {\n       \
    \ a = b;\n        return 1;\n    }\n    return 0;\n}\n\n\nll mod(ll val, ll M)\
    \ {\n    val = val % M;\n    if(val < 0) {\n        val += M;\n    }\n    return\
    \ val;\n}\n\ntemplate<typename T>\nT RS(T N, T P, T M){\n    if(P == 0) {\n  \
    \      return 1;\n    }\n    if(P < 0) {\n        return 0;\n    }\n    if(P %\
    \ 2 == 0){\n        ll t = RS(N, P/2, M);\n        if(M == -1) return t * t;\n\
    \        return t * t % M;\n    }\n    if(M == -1) {\n        return N * RS(N,P\
    \ - 1,M);\n    }\n    return N * RS(N, P-1, M) % M;\n}\n#line 1 \"DataStructure/SparseTable.cpp\"\
    \ntemplate <typename T>\nclass SparseTable {\n    vector<vector<T>> table; //table[i][j]\
    \ = j\u756A\u76EE\u304B\u3089\u898B\u30662^i\u500B\u306E\u8981\u7D20\u306E\u6700\
    \u5C0F\u5024\n    vector<int> lookup;\n\npublic:\n\n    //Sparse Table\u306E\u69CB\
    \u7BC9\n    SparseTable(vector<T> v) {\n        //log\u3092\u53D6\u308B\n    \
    \    int b = 0;\n        while((1 << b) <= v.size()) {\n            b++;\n   \
    \     }\n        table.resize(b,vector<T>(1 << b));\n        for(int i = 0;i <\
    \ v.size();i++) {\n            table[0][i] = v[i];\n        }\n        for(int\
    \ i = 1;i < b;i++) {\n            for(int j = 0;j + (1 << i) <= (1 << b);j++)\
    \ {\n                table[i][j] = min(table[i - 1][j],table[i - 1][j + (1 <<\
    \ (i - 1))]);\n            }\n        }\n        lookup.resize(v.size() + 1);\n\
    \        for(int i = 2;i < lookup.size();i++) {\n            lookup[i] = lookup[i\
    \ >> 1] + 1;\n        }\n    }\n\n    //query(l,r) = \u533A\u9593[l,r)\u306E\u6700\
    \u5C0F\u5024\u3092\u8FD4\u3059\n    T query(int l,int r) {\n        int b = lookup[r\
    \ - l];\n        return min(table[b][l],table[b][r - (1 << b)]);\n    }\n};\n\
    #line 8 \"Test/yosupo-judge/SparseTable.test.cpp\"\n\nint main() {\n    int N,Q;\n\
    \    cin >> N >> Q;\n    vector<int> vec(N);\n    for(int i = 0;i < N;i++) {\n\
    \        cin >> vec.at(i);\n    }\n    SparseTable st(vec);\n    for(int i = 0;i\
    \ < Q;i++) {\n        int l,r;\n        cin >> l >> r;\n        cout << st.query(l,r)\
    \ << endl;\n    }\n}\n"
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
  timestamp: '2021-01-04 19:32:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yosupo-judge/SparseTable.test.cpp
layout: document
redirect_from:
- /verify/Test/yosupo-judge/SparseTable.test.cpp
- /verify/Test/yosupo-judge/SparseTable.test.cpp.html
title: Test/yosupo-judge/SparseTable.test.cpp
---
