---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Mathematics/MatrixPower.cpp\"\n//\u884C\u5217\u306E\u7A4D\
    \u3092\u6C42\u3081\u308B\uFF08\u305F\u3060\u3057A\u306E\u6A2A\u306E\u8981\u7D20\
    \u6570\u3068B\u306E\u7E26\u306E\u8981\u7D20\u6570\u304C\u7570\u306A\u3063\u305F\
    \u3089RE\uFF09\nvector<vector<long long>> matpro(vector<vector<long long>> A,vector<vector<long\
    \ long>> B) {\n    assert(A.at(0).size() == B.size());\n    int N = A.size();\n\
    \    int M = B.at(0).size();\n    int K = A.at(0).size();\n    vector<vector<long\
    \ long>> res(N,vector<long long>(M));\n    for(int i = 0;i < N;i++) {\n      \
    \  for(int j = 0;j < M;j++) {\n            for(int k = 0;k < K;k++) {\n      \
    \          res.at(i).at(j) += A.at(i).at(k) * B.at(k).at(j);\n            }\n\
    \        }\n    }\n    return res;\n}\n\n//\u884C\u5217\u7D2F\u4E57\u3001A^P\u3092\
    \u6C42\u3081\u308B\nvector<vector<long long>> matpow(long long P,vector<vector<long\
    \ long>> A) {\n    int M = A.size();\n    vector<vector<long long>> res(M,vector<long\
    \ long>(M));\n    for(int i = 0;i < M;i++) {\n        res.at(i).at(i) = 1;\n \
    \   }\n    if(P == 0) {\n        return res;\n    }\n    if(P % 2 == 0) {\n  \
    \      vector<vector<long long>> cnt = matpow(P / 2,A);\n        return matpro(cnt,cnt);\n\
    \    }\n    return matpro(A,matpow(P - 1,A));\n}\n"
  code: "//\u884C\u5217\u306E\u7A4D\u3092\u6C42\u3081\u308B\uFF08\u305F\u3060\u3057\
    A\u306E\u6A2A\u306E\u8981\u7D20\u6570\u3068B\u306E\u7E26\u306E\u8981\u7D20\u6570\
    \u304C\u7570\u306A\u3063\u305F\u3089RE\uFF09\nvector<vector<long long>> matpro(vector<vector<long\
    \ long>> A,vector<vector<long long>> B) {\n    assert(A.at(0).size() == B.size());\n\
    \    int N = A.size();\n    int M = B.at(0).size();\n    int K = A.at(0).size();\n\
    \    vector<vector<long long>> res(N,vector<long long>(M));\n    for(int i = 0;i\
    \ < N;i++) {\n        for(int j = 0;j < M;j++) {\n            for(int k = 0;k\
    \ < K;k++) {\n                res.at(i).at(j) += A.at(i).at(k) * B.at(k).at(j);\n\
    \            }\n        }\n    }\n    return res;\n}\n\n//\u884C\u5217\u7D2F\u4E57\
    \u3001A^P\u3092\u6C42\u3081\u308B\nvector<vector<long long>> matpow(long long\
    \ P,vector<vector<long long>> A) {\n    int M = A.size();\n    vector<vector<long\
    \ long>> res(M,vector<long long>(M));\n    for(int i = 0;i < M;i++) {\n      \
    \  res.at(i).at(i) = 1;\n    }\n    if(P == 0) {\n        return res;\n    }\n\
    \    if(P % 2 == 0) {\n        vector<vector<long long>> cnt = matpow(P / 2,A);\n\
    \        return matpro(cnt,cnt);\n    }\n    return matpro(A,matpow(P - 1,A));\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/MatrixPower.cpp
  requiredBy: []
  timestamp: '2021-06-16 21:34:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mathematics/MatrixPower.cpp
layout: document
redirect_from:
- /library/Mathematics/MatrixPower.cpp
- /library/Mathematics/MatrixPower.cpp.html
title: Mathematics/MatrixPower.cpp
---