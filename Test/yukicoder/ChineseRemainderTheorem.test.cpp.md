---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mathematics/ChineseRemainderTheorem.cpp
    title: Mathematics/ChineseRemainderTheorem.cpp
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
    PROBLEM: https://yukicoder.me/problems/447
    links:
    - https://yukicoder.me/problems/447
  bundledCode: "#line 1 \"Test/yukicoder/ChineseRemainderTheorem.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/447\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 1 \"Other/Template.cpp\"\ntypedef long long ll;\n\n\
    template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return\
    \ true; } return false; }\ntemplate<typename T> inline bool chmin(T &a, T b) {\
    \ if (a > b) { a = b; return true; } return false; }\n\ntemplate<typename T>\n\
    T modpow(T N, T P, T M){\n    if(P == 0) return 1;\n    if(P < 0) return 0;\n\
    \    if(P % 2 == 0){\n        T t = modpow(N, P/2, M);\n        if(M == -1) return\
    \ t * t;\n        return t * t % M;\n    }\n    if(M == -1) return N * modpow(N,P\
    \ - 1,M);\n    return N * modpow(N, P-1, M) % M;\n}\n#line 1 \"Mathematics/ChineseRemainderTheorem.cpp\"\
    \n//extgcd(a,b,x,y):ax+by=gcd(a,b)\u3092\u6E80\u305F\u3059(x,y)\u304C\u683C\u7D0D\
    \u3055\u308C\u308B\u3000\u8FD4\u308A\u5024\u306Fgcd(a,b)\nll extgcd(ll a,ll b,ll\
    \ &x,ll &y) {\n    if(b == 0) {\n        x = 1;\n        y = 0;\n        return\
    \ a;\n    }\n    ll d = extgcd(b,a % b,y,x);\n    y -= a / b * x;\n    return\
    \ d;\n}\n\n//CRT(b,m):n\u6B21\u5408\u540C\u65B9\u7A0B\u5F0F\u3092\u89E3\u304F\u3002\
    \u7B54\u3048\u306F x = retr(mod retm)\u306E\u5F62\u3067\u8868\u3055\u308C\u308B\
    \uFF08\u89E3\u304C\u7121\u3044\u5834\u5408\u306F(0,-1)\u306E\u5F62\u3067\u8868\
    \u3055\u308C\u308B\uFF09\npair<ll,ll> CRT(vector<ll> r,vector<ll> m) {\n    if(r.empty()\
    \ || m.empty()) return make_pair(0,1);\n    ll R = r.front();\n    ll M = m.front();\n\
    \    for(int i = 1;i < (int)r.size();i++) {\n        ll x,y;\n        ll d = extgcd(M,m.at(i),x,y);\n\
    \        if((r.at(i) - R) % d != 0) return make_pair(0,-1);\n        ll tmp =\
    \ (r.at(i) - R) / d % (m.at(i) / d) * x % (m.at(i) / d);\n        R += M * tmp;\n\
    \        M *= m.at(i) / d;\n    }\n    R %= M;\n    if(R < 0) R += M;\n    return\
    \ make_pair(R,M);\n}\n#line 8 \"Test/yukicoder/ChineseRemainderTheorem.test.cpp\"\
    \n\nint main() {\n    ll X1,Y1,X2,Y2,X3,Y3;\n    cin >> X1 >> Y1 >> X2 >> Y2 >>\
    \ X3 >> Y3;\n    pair<ll,ll> ret = CRT({X1,X2,X3},{Y1,Y2,Y3});\n    if(ret.second\
    \ == -1) cout << -1 << endl;\n    else {\n        if(ret.first == 0) cout << ret.second\
    \ << endl;\n        else cout << ret.first << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/447\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#include\"../../Other/Template.cpp\"\n#include\"../../Mathematics/ChineseRemainderTheorem.cpp\"\
    \n\nint main() {\n    ll X1,Y1,X2,Y2,X3,Y3;\n    cin >> X1 >> Y1 >> X2 >> Y2 >>\
    \ X3 >> Y3;\n    pair<ll,ll> ret = CRT({X1,X2,X3},{Y1,Y2,Y3});\n    if(ret.second\
    \ == -1) cout << -1 << endl;\n    else {\n        if(ret.first == 0) cout << ret.second\
    \ << endl;\n        else cout << ret.first << endl;\n    }\n}\n"
  dependsOn:
  - Other/Template.cpp
  - Mathematics/ChineseRemainderTheorem.cpp
  isVerificationFile: true
  path: Test/yukicoder/ChineseRemainderTheorem.test.cpp
  requiredBy: []
  timestamp: '2021-06-08 16:42:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/yukicoder/ChineseRemainderTheorem.test.cpp
layout: document
redirect_from:
- /verify/Test/yukicoder/ChineseRemainderTheorem.test.cpp
- /verify/Test/yukicoder/ChineseRemainderTheorem.test.cpp.html
title: Test/yukicoder/ChineseRemainderTheorem.test.cpp
---
