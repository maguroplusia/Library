---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/yukicoder/ChineseRemainderTheorem.test.cpp
    title: Test/yukicoder/ChineseRemainderTheorem.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Mathematics/ChineseRemainderTheorem.cpp\"\n//extgcd(a,b,x,y):ax+by=gcd(a,b)\u3092\
    \u6E80\u305F\u3059(x,y)\u304C\u683C\u7D0D\u3055\u308C\u308B\u3000\u8FD4\u308A\u5024\
    \u306Fgcd(a,b)\nll extgcd(ll a,ll b,ll &x,ll &y) {\n    if(b == 0) {\n       \
    \ x = 1;\n        y = 0;\n        return a;\n    }\n    ll d = extgcd(b,a % b,y,x);\n\
    \    y -= a / b * x;\n    return d;\n}\n\n//CRT(b,m):n\u6B21\u5408\u540C\u65B9\
    \u7A0B\u5F0F\u3092\u89E3\u304F\u3002\u7B54\u3048\u306F x = retr(mod retm)\u306E\
    \u5F62\u3067\u8868\u3055\u308C\u308B\uFF08\u89E3\u304C\u7121\u3044\u5834\u5408\
    \u306F(0,-1)\u306E\u5F62\u3067\u8868\u3055\u308C\u308B\uFF09\npair<ll,ll> CRT(vector<ll>\
    \ b,vector<ll> m) {\n    ll retr = 0;\n    ll retm = 1;\n    for(int i = 0;i <\
    \ (int)b.size();i++) {\n        ll x,y;\n        ll d = extgcd(retm,m.at(i),x,y);\n\
    \        if((b.at(i) - retr) % d != 0) return make_pair(0,-1);\n        ll tmp\
    \ = (b.at(i) - retr) / d * x % (m.at(i) / d);\n        retr += retm * tmp;\n \
    \       retm *= m.at(i) / d;\n    }\n    return make_pair(mod(retr,retm),retm);\n\
    }\n"
  code: "//extgcd(a,b,x,y):ax+by=gcd(a,b)\u3092\u6E80\u305F\u3059(x,y)\u304C\u683C\
    \u7D0D\u3055\u308C\u308B\u3000\u8FD4\u308A\u5024\u306Fgcd(a,b)\nll extgcd(ll a,ll\
    \ b,ll &x,ll &y) {\n    if(b == 0) {\n        x = 1;\n        y = 0;\n       \
    \ return a;\n    }\n    ll d = extgcd(b,a % b,y,x);\n    y -= a / b * x;\n   \
    \ return d;\n}\n\n//CRT(b,m):n\u6B21\u5408\u540C\u65B9\u7A0B\u5F0F\u3092\u89E3\
    \u304F\u3002\u7B54\u3048\u306F x = retr(mod retm)\u306E\u5F62\u3067\u8868\u3055\
    \u308C\u308B\uFF08\u89E3\u304C\u7121\u3044\u5834\u5408\u306F(0,-1)\u306E\u5F62\
    \u3067\u8868\u3055\u308C\u308B\uFF09\npair<ll,ll> CRT(vector<ll> b,vector<ll>\
    \ m) {\n    ll retr = 0;\n    ll retm = 1;\n    for(int i = 0;i < (int)b.size();i++)\
    \ {\n        ll x,y;\n        ll d = extgcd(retm,m.at(i),x,y);\n        if((b.at(i)\
    \ - retr) % d != 0) return make_pair(0,-1);\n        ll tmp = (b.at(i) - retr)\
    \ / d * x % (m.at(i) / d);\n        retr += retm * tmp;\n        retm *= m.at(i)\
    \ / d;\n    }\n    return make_pair(mod(retr,retm),retm);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mathematics/ChineseRemainderTheorem.cpp
  requiredBy: []
  timestamp: '2021-03-12 20:33:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/yukicoder/ChineseRemainderTheorem.test.cpp
documentation_of: Mathematics/ChineseRemainderTheorem.cpp
layout: document
redirect_from:
- /library/Mathematics/ChineseRemainderTheorem.cpp
- /library/Mathematics/ChineseRemainderTheorem.cpp.html
title: Mathematics/ChineseRemainderTheorem.cpp
---
