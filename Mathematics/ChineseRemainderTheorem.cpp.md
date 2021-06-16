---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/ChineseRemainderTheorem.test.cpp
    title: Test/yukicoder/ChineseRemainderTheorem.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Mathematics/ChineseRemainderTheorem.cpp\"\n//extgcd(a,b,x,y):ax+by=gcd(a,b)\u3092\
    \u6E80\u305F\u3059(x,y)\u304C\u683C\u7D0D\u3055\u308C\u308B\u3000\u8FD4\u308A\u5024\
    \u306Fgcd(a,b)\nlong long extgcd(long long a,long long b,long long &x,long long\
    \ &y) {\n    if(b == 0) {\n        x = 1;\n        y = 0;\n        return a;\n\
    \    }\n    long long d = extgcd(b,a % b,y,x);\n    y -= a / b * x;\n    return\
    \ d;\n}\n\n//CRT(b,m):n\u6B21\u5408\u540C\u65B9\u7A0B\u5F0F\u3092\u89E3\u304F\u3002\
    \u7B54\u3048\u306F x = retr(mod retm)\u306E\u5F62\u3067\u8868\u3055\u308C\u308B\
    \uFF08\u89E3\u304C\u7121\u3044\u5834\u5408\u306F(0,-1)\u306E\u5F62\u3067\u8868\
    \u3055\u308C\u308B\uFF09\npair<long long,long long> CRT(vector<long long> r,vector<long\
    \ long> m) {\n    if(r.empty() || m.empty()) return make_pair(0,1);\n    long\
    \ long R = r.front();\n    long long M = m.front();\n    for(int i = 1;i < (int)r.size();i++)\
    \ {\n        long long x,y;\n        long long d = extgcd(M,m.at(i),x,y);\n  \
    \      if((r.at(i) - R) % d != 0) return make_pair(0,-1);\n        long long tmp\
    \ = (r.at(i) - R) / d % (m.at(i) / d) * x % (m.at(i) / d);\n        R += M * tmp;\n\
    \        M *= m.at(i) / d;\n    }\n    R %= M;\n    if(R < 0) R += M;\n    return\
    \ make_pair(R,M);\n}\n"
  code: "//extgcd(a,b,x,y):ax+by=gcd(a,b)\u3092\u6E80\u305F\u3059(x,y)\u304C\u683C\
    \u7D0D\u3055\u308C\u308B\u3000\u8FD4\u308A\u5024\u306Fgcd(a,b)\nlong long extgcd(long\
    \ long a,long long b,long long &x,long long &y) {\n    if(b == 0) {\n        x\
    \ = 1;\n        y = 0;\n        return a;\n    }\n    long long d = extgcd(b,a\
    \ % b,y,x);\n    y -= a / b * x;\n    return d;\n}\n\n//CRT(b,m):n\u6B21\u5408\
    \u540C\u65B9\u7A0B\u5F0F\u3092\u89E3\u304F\u3002\u7B54\u3048\u306F x = retr(mod\
    \ retm)\u306E\u5F62\u3067\u8868\u3055\u308C\u308B\uFF08\u89E3\u304C\u7121\u3044\
    \u5834\u5408\u306F(0,-1)\u306E\u5F62\u3067\u8868\u3055\u308C\u308B\uFF09\npair<long\
    \ long,long long> CRT(vector<long long> r,vector<long long> m) {\n    if(r.empty()\
    \ || m.empty()) return make_pair(0,1);\n    long long R = r.front();\n    long\
    \ long M = m.front();\n    for(int i = 1;i < (int)r.size();i++) {\n        long\
    \ long x,y;\n        long long d = extgcd(M,m.at(i),x,y);\n        if((r.at(i)\
    \ - R) % d != 0) return make_pair(0,-1);\n        long long tmp = (r.at(i) - R)\
    \ / d % (m.at(i) / d) * x % (m.at(i) / d);\n        R += M * tmp;\n        M *=\
    \ m.at(i) / d;\n    }\n    R %= M;\n    if(R < 0) R += M;\n    return make_pair(R,M);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/ChineseRemainderTheorem.cpp
  requiredBy: []
  timestamp: '2021-06-16 21:34:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yukicoder/ChineseRemainderTheorem.test.cpp
documentation_of: Mathematics/ChineseRemainderTheorem.cpp
layout: document
redirect_from:
- /library/Mathematics/ChineseRemainderTheorem.cpp
- /library/Mathematics/ChineseRemainderTheorem.cpp.html
title: Mathematics/ChineseRemainderTheorem.cpp
---
